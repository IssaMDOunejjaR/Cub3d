/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_and_ceil_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 13:06:12 by iounejja          #+#    #+#             */
/*   Updated: 2020/03/06 17:21:26 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static	void	data(t_config *c_i, int i, t_f_c *f_c)
{
	int x;

	x = 0;
	while (x < c_i->res.width)
	{
		f_c->cx = (int)f_c->fx;
		f_c->cy = (int)f_c->fy;
		f_c->txc = (int)(c_i->texture[5].width *
		(f_c->fx - f_c->cx)) & (c_i->texture[5].width - 1);
		f_c->tyc = (int)(c_i->texture[5].height *
		(f_c->fy - f_c->cy)) & (c_i->texture[5].height - 1);
		f_c->txf = (int)(c_i->texture[4].width *
		(f_c->fx - f_c->cx)) & (c_i->texture[4].width - 1);
		f_c->tyf = (int)(c_i->texture[4].height *
		(f_c->fy - f_c->cy)) & (c_i->texture[4].height - 1);
		f_c->fx += f_c->fsx;
		f_c->fy += f_c->fsy;
		c_i->conf_mlx->img.data[i * c_i->res.width + x] =
		c_i->texture[4].data[c_i->texture[4].width * f_c->tyc + f_c->txc];
		c_i->conf_mlx->img.data[(c_i->res.height - i - 1) *
		c_i->res.width + x] = c_i->texture[5].
		data[c_i->texture[5].width * f_c->tyf + f_c->txf];
		x++;
	}
}

void			floor_and_ceil(t_config *c_i)
{
	int		i;
	t_f_c	f_c;

	i = c_i->res.height / 2;
	while (i < c_i->res.height)
	{
		f_c.rdx0 = c_i->player_info->dir_x - c_i->player_info->plane_x;
		f_c.rdy0 = c_i->player_info->dir_y - c_i->player_info->plane_y;
		f_c.rdx1 = c_i->player_info->dir_x + c_i->player_info->plane_x;
		f_c.rdy1 = c_i->player_info->dir_y + c_i->player_info->plane_y;
		f_c.p = i - c_i->res.height / 2;
		f_c.pos_z = 0.5 * c_i->res.height;
		f_c.row_distance = f_c.pos_z / f_c.p;
		f_c.fsx = f_c.row_distance * (f_c.rdx1 - f_c.rdx0) / c_i->res.width;
		f_c.fsy = f_c.row_distance * (f_c.rdy1 - f_c.rdy0) / c_i->res.width;
		f_c.fx = c_i->player_info->map_x + f_c.row_distance * f_c.rdx0;
		f_c.fy = c_i->player_info->map_y + f_c.row_distance * f_c.rdy0;
		data(c_i, i, &f_c);
		i++;
	}
}
