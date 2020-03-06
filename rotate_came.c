/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_came.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 11:29:04 by iounejja          #+#    #+#             */
/*   Updated: 2020/03/05 18:23:09 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_camera_left(t_config *c_i)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = c_i->player_info->dir_x;
	old_planex = c_i->player_info->plane_x;
	c_i->player_info->dir_x = c_i->player_info->dir_x * cos(-0.1)
	- c_i->player_info->dir_y * sin(-0.1);
	c_i->player_info->dir_y = old_dirx * sin(-0.1) +
	c_i->player_info->dir_y * cos(-0.1);
	c_i->player_info->plane_x = c_i->player_info->plane_x *
	cos(-0.1) - c_i->player_info->plane_y * sin(-0.1);
	c_i->player_info->plane_y = old_planex * sin(-0.1) +
	c_i->player_info->plane_y * cos(-0.1);
}

void	move_camera_right(t_config *c_i)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = c_i->player_info->dir_x;
	old_planex = c_i->player_info->plane_x;
	c_i->player_info->dir_x = c_i->player_info->dir_x
	* cos(0.1) - c_i->player_info->dir_y * sin(0.1);
	c_i->player_info->dir_y = old_dirx * sin(0.1) +
	c_i->player_info->dir_y * cos(0.1);
	c_i->player_info->plane_x = c_i->player_info->plane_x
	* cos(0.1) - c_i->player_info->plane_y * sin(0.1);
	c_i->player_info->plane_y = old_planex * sin(0.1) +
	c_i->player_info->plane_y * cos(0.1);
}
