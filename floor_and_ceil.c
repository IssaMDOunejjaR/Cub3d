/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_and_ceil.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 13:22:13 by iounejja          #+#    #+#             */
/*   Updated: 2020/03/06 17:23:09 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	data(t_config *c_i, int i)
{
	int x;

	x = 0;
	while (x < c_i->res.width)
	{
		c_i->conf_mlx->img.data[i * c_i->res.width + x] =
		((c_i->floor.r * pow(256, 2)) + (c_i->floor.g *
		pow(256, 1)) + c_i->floor.b);
		c_i->conf_mlx->img.data[(c_i->res.height - i - 1) *
		c_i->res.width + x] = ((c_i->ceil.r * pow(256, 2)) +
		(c_i->ceil.g * pow(256, 1)) + c_i->ceil.b);
		x++;
	}
}

void	floor_and_ceil(t_config *c_i)
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
		data(c_i, i);
		i++;
	}
}
