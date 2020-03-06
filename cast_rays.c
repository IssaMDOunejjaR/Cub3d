/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 17:08:53 by iounejja          #+#    #+#             */
/*   Updated: 2020/03/06 12:03:42 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	ft_abs(double nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

void	cast_rays(t_config *c_i)
{
	int		i;
	t_map	map;
	double	z_buffer[c_i->res.width];

	floor_and_ceil(c_i);
	i = 0;
	while (i < c_i->res.width)
	{
		cast_map(c_i, i, &map);
		z_buffer[i] = map.pwd;
		i++;
	}
	dist_sprite(c_i);
	sort_sprite(c_i);
	cast_sprite(c_i, z_buffer);
	if (g_save == 1)
	{
		save_bmp(c_i);
		exit(0);
	}
	mlx_put_image_to_window(c_i->conf_mlx->mlx_ptr,
	c_i->conf_mlx->win_ptr, c_i->conf_mlx->img.img_ptr, 0, 0);
}
