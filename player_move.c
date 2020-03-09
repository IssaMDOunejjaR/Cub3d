/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 11:15:08 by iounejja          #+#    #+#             */
/*   Updated: 2020/03/09 10:27:47 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_up(t_config *c_i, double ms)
{
	if (c_i->map[(int)(c_i->player_info->map_y + c_i->player_info->dir_y
	* ms)][(int)c_i->player_info->map_x] == '0')
		c_i->player_info->map_y += c_i->player_info->dir_y * ms;
	if (c_i->map[(int)c_i->player_info->map_y][(int)(c_i->player_info->map_x
	+ c_i->player_info->dir_x * ms)] == '0')
		c_i->player_info->map_x += c_i->player_info->dir_x * ms;
}

void	move_down(t_config *c_i, double ms)
{
	if (c_i->map[(int)(c_i->player_info->map_y - c_i->player_info->plane_y
	* ms)][(int)(c_i->player_info->map_x)] == '0')
		c_i->player_info->map_y -= c_i->player_info->plane_y * ms;
	if (c_i->map[(int)(c_i->player_info->map_y)]
	[(int)(c_i->player_info->map_x -
	c_i->player_info->plane_x * ms)] == '0')
		c_i->player_info->map_x -= c_i->player_info->plane_x * ms;
}

void	move_right(t_config *c_i, double ms)
{
	if (c_i->map[(int)(c_i->player_info->map_y +
	c_i->player_info->plane_y * ms)][(int)(c_i->player_info->map_x
	+ c_i->player_info->plane_x * ms)] == '0')
	{
		c_i->player_info->map_y += c_i->player_info->plane_y * ms;
		c_i->player_info->map_x += c_i->player_info->plane_x * ms;
	}
}

void	move_left(t_config *c_i, double ms)
{
	if (c_i->map[(int)(c_i->player_info->map_y -
	c_i->player_info->dir_y * ms)][(int)c_i->player_info->map_x] == '0')
		c_i->player_info->map_y -= c_i->player_info->dir_y * ms;
	if (c_i->map[(int)c_i->player_info->map_y]
	[(int)(c_i->player_info->map_x -
	c_i->player_info->dir_x * ms)] == '0')
		c_i->player_info->map_x -= c_i->player_info->dir_x * ms;
}
