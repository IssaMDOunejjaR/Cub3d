/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_cast_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:34:47 by iounejja          #+#    #+#             */
/*   Updated: 2020/03/06 14:52:52 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	data_one_c(t_map *map)
{
	if (map->rdy == 0)
		map->ddx = 0;
	else
	{
		if (map->rdx == 0)
			map->ddx = 1;
		else
			ft_abs(1 / map->rdx);
	}
	if (map->rdx == 0)
		map->ddy = 0;
	else
	{
		if (map->rdx == 0)
			map->ddy = 1;
		else
			ft_abs(1 / map->rdy);
	}
}

void	data_one(t_config *c_i, int i, t_map *map)
{
	map->camerax = 2 * i / (double)c_i->res.width - 1;
	map->rdx = c_i->player_info->dir_x +
	c_i->player_info->plane_x * map->camerax;
	map->rdy = c_i->player_info->dir_y +
	c_i->player_info->plane_y * map->camerax;
	map->ddx = ft_abs(1 / map->rdx);
	map->ddy = ft_abs(1 / map->rdy);
	map->hit = 0;
	map->mapx = (int)c_i->player_info->map_x;
	map->mapy = (int)c_i->player_info->map_y;
	data_one_c(map);
}

void	data_two(t_config *c_i, t_map *map)
{
	if (map->rdx < 0)
	{
		map->stepx = -1;
		map->sdx = (c_i->player_info->map_x - map->mapx) * map->ddx;
	}
	else
	{
		map->stepx = 1;
		map->sdx = (map->mapx + 1.0 - c_i->player_info->map_x) * map->ddx;
	}
	if (map->rdy < 0)
	{
		map->stepy = -1;
		map->sdy = (c_i->player_info->map_y - map->mapy) * map->ddy;
	}
	else
	{
		map->stepy = 1;
		map->sdy = (map->mapy + 1.0 - c_i->player_info->map_y) * map->ddy;
	}
}

void	data_three(t_config *c_i, t_map *map)
{
	while (map->hit == 0)
	{
		if (map->sdx < map->sdy)
		{
			map->sdx += map->ddx;
			map->mapx += map->stepx;
			map->side = 0;
		}
		else
		{
			map->sdy += map->ddy;
			map->mapy += map->stepy;
			map->side = 1;
		}
		if (c_i->map[map->mapy][map->mapx] == '1')
			map->hit = 1;
	}
	if (map->side == 0)
		map->pwd = (map->mapx - c_i->player_info->map_x +
		(1 - map->stepx) / 2) / map->rdx;
	else
		map->pwd = (map->mapy - c_i->player_info->map_y +
		(1 - map->stepy) / 2) / map->rdy;
}

void	data_four(t_config *c_i, t_map *map)
{
	map->lh = (int)(c_i->res.height / map->pwd);
	map->ds = -map->lh / 2 + c_i->res.height / 2;
	if (map->ds < 0)
		map->ds = 0;
	map->de = map->lh / 2 + c_i->res.height / 2;
	if (map->de >= c_i->res.height)
		map->de = c_i->res.height - 1;
	map->texture = 0;
	if (direc(map->side, map->rdx, map->rdy) == 'N')
		map->texture = 0;
	else if (direc(map->side, map->rdx, map->rdy) == 'S')
		map->texture = 1;
	else if (direc(map->side, map->rdx, map->rdy) == 'E')
		map->texture = 2;
	else if (direc(map->side, map->rdx, map->rdy) == 'W')
		map->texture = 3;
	if (map->side == 0)
		map->wall_x = c_i->player_info->map_y + map->pwd * map->rdy;
	else
		map->wall_x = c_i->player_info->map_x + map->pwd * map->rdx;
	map->wall_x -= floor(map->wall_x);
}
