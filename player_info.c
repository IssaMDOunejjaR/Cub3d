/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 15:02:51 by iounejja          #+#    #+#             */
/*   Updated: 2020/03/06 11:52:00 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_player_pos(t_config *conf_info)
{
	int	i;
	int	j;

	i = 0;
	while (conf_info->map[i] != NULL)
	{
		j = 0;
		while (conf_info->map[i][j])
		{
			if (conf_info->map[i][j] == 'N' || conf_info->map[i][j] == 'S' ||
					conf_info->map[i][j] == 'E' || conf_info->map[i][j] == 'W')
			{
				conf_info->player_info->map_x = j + 0.5;
				conf_info->player_info->map_y = i + 0.5;
			}
			j++;
		}
		i++;
	}
}

void	get_player_dir(t_config *conf_info)
{
	if (conf_info->map[(int)conf_info->player_info->map_y]
	[(int)conf_info->player_info->map_x] == 'N')
	{
		conf_info->player_info->dir_x = 0;
		conf_info->player_info->dir_y = -1;
	}
	else if (conf_info->map[(int)conf_info->player_info->map_y]
	[(int)conf_info->player_info->map_x] == 'S')
	{
		conf_info->player_info->dir_x = 0;
		conf_info->player_info->dir_y = 1;
	}
	else if (conf_info->map[(int)conf_info->player_info->map_y]
	[(int)conf_info->player_info->map_x] == 'W')
	{
		conf_info->player_info->dir_x = -1;
		conf_info->player_info->dir_y = 0;
	}
	else if (conf_info->map[(int)conf_info->player_info->map_y]
	[(int)conf_info->player_info->map_x] == 'E')
	{
		conf_info->player_info->dir_x = 1;
		conf_info->player_info->dir_y = 0;
	}
}

void	get_camera_plane(t_config *conf_info)
{
	if (conf_info->map[(int)conf_info->player_info->map_y]
	[(int)conf_info->player_info->map_x] == 'N')
	{
		conf_info->player_info->plane_x = 0.66;
		conf_info->player_info->plane_y = 0;
	}
	else if (conf_info->map[(int)conf_info->player_info->map_y]
	[(int)conf_info->player_info->map_x] == 'S')
	{
		conf_info->player_info->plane_x = -0.66;
		conf_info->player_info->plane_y = 0;
	}
	else if (conf_info->map[(int)conf_info->player_info->map_y]
	[(int)conf_info->player_info->map_x] == 'W')
	{
		conf_info->player_info->plane_x = 0;
		conf_info->player_info->plane_y = -0.66;
	}
	else if (conf_info->map[(int)conf_info->player_info->map_y]
	[(int)conf_info->player_info->map_x] == 'E')
	{
		conf_info->player_info->plane_x = 0;
		conf_info->player_info->plane_y = 0.66;
	}
}

void	get_player_info(t_config *conf_info)
{
	get_player_pos(conf_info);
	get_player_dir(conf_info);
	get_camera_plane(conf_info);
}
