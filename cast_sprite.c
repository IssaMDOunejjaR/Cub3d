/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:20:38 by iounejja          #+#    #+#             */
/*   Updated: 2020/03/06 11:40:44 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	data_s_two(t_config *c_i, double *z_buffer, t_sp *sp)
{
	int y;

	sp->stripe = sp->drsx;
	while (sp->stripe < sp->drex)
	{
		sp->textx = (int)(256 * (sp->stripe -
		(-sp->spw / 2 + sp->sp_sc_x)) * c_i->texture[6].width / sp->spw) / 256;
		if (sp->trany > 0 && sp->stripe > 0 && sp->stripe <
		c_i->res.width && sp->trany < z_buffer[sp->stripe])
		{
			y = sp->drsy;
			while (y < sp->drey)
			{
				sp->d = (y) * 256 - c_i->res.height * 128 + sp->sph * 128;
				sp->texty = ((sp->d * c_i->texture[6].height) / sp->sph) / 256;
				sp->color = c_i->texture[6].
				data[c_i->texture[6].width * sp->texty + sp->textx];
				if ((sp->color & 0x00FFFFFF) != 0)
					c_i->conf_mlx->img.data[sp->stripe +
					c_i->res.width * y] = sp->color;
				y++;
			}
		}
		sp->stripe++;
	}
}

static	void	data_s_one(t_config *c_i, double *z_buffer, t_sp *sp)
{
	sp->sph = ft_abs((int)(c_i->res.height / sp->trany));
	sp->drsy = -sp->sph / 2 + c_i->res.height / 2;
	if (sp->drsy < 0)
		sp->drsy = 0;
	sp->drey = sp->sph / 2 + c_i->res.height / 2;
	if (sp->drey >= c_i->res.height)
		sp->drey = c_i->res.height - 1;
	sp->spw = ft_abs((int)(c_i->res.height / sp->trany));
	sp->drsx = -sp->spw / 2 + sp->sp_sc_x;
	if (sp->drsx < 0)
		sp->drsx = 0;
	sp->drex = sp->spw / 2 + sp->sp_sc_x;
	if (sp->drex >= c_i->res.width)
		sp->drex = c_i->res.width - 1;
	data_s_two(c_i, z_buffer, sp);
}

void			cast_sprite(t_config *c_i, double *z_buffer)
{
	int		i;
	t_sp	sp;

	i = 0;
	while (i < c_i->n_sprite)
	{
		sp.spx = c_i->sprite[i].x - c_i->player_info->map_x;
		sp.spy = c_i->sprite[i].y - c_i->player_info->map_y;
		sp.inv_det = 1.0 / (c_i->player_info->plane_x *
		c_i->player_info->dir_y -
		c_i->player_info->dir_x * c_i->player_info->plane_y);
		sp.tranx = sp.inv_det * (c_i->player_info->dir_y
		* sp.spx - c_i->player_info->dir_x * sp.spy);
		sp.trany = sp.inv_det * (-c_i->player_info->plane_y
		* sp.spx + c_i->player_info->plane_x * sp.spy);
		sp.sp_sc_x = (int)((c_i->res.width / 2) * (1 + sp.tranx / sp.trany));
		data_s_one(c_i, z_buffer, &sp);
		i++;
	}
}
