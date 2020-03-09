/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_and_ceil.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 13:22:13 by iounejja          #+#    #+#             */
/*   Updated: 2020/03/09 14:10:32 by iounejja         ###   ########.fr       */
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

	i = c_i->res.height / 2;
	while (i < c_i->res.height)
	{
		data(c_i, i);
		i++;
	}
}
