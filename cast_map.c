/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 17:51:52 by iounejja          #+#    #+#             */
/*   Updated: 2020/03/06 14:32:22 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	direc(int side, double ray_dir_x, double ray_dir_y)
{
	if (side == 1)
	{
		if (ray_dir_y * -1 < 0)
			return ('N');
		else
			return ('S');
	}
	else
	{
		if (ray_dir_x * -1 > 0)
			return ('E');
		else
			return ('W');
	}
}

void	cast_map(t_config *c_i, int i, t_map *map)
{
	int y;

	data_one(c_i, i, map);
	data_two(c_i, map);
	data_three(c_i, map);
	data_four(c_i, map);
	map->text_x = (int)(map->wall_x * (double)c_i->texture[map->texture].width);
	if (map->side == 0 && map->rdx < 0)
		map->text_x = c_i->texture[map->texture].width - map->text_x - 1;
	if (map->side == 1 && map->rdy > 0)
		map->text_x = c_i->texture[map->texture].width - map->text_x - 1;
	map->step = 1.0 * c_i->texture[map->texture].height / map->lh;
	map->text_pos = (map->ds - c_i->res.height / 2 + map->lh / 2) * map->step;
	y = map->ds;
	while (y < map->de)
	{
		map->text_y =
		(int)map->text_pos & (c_i->texture[map->texture].width - 1);
		map->text_pos += map->step;
		map->color = c_i->texture[map->texture].
		data[c_i->texture[map->texture].width * map->text_y + map->text_x];
		c_i->conf_mlx->img.data[i + c_i->res.width * y] = map->color;
		y++;
	}
}
