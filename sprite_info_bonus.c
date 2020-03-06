/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_info_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 12:41:50 by iounejja          #+#    #+#             */
/*   Updated: 2020/03/05 18:25:36 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	nbr_sprite(t_config *c_i)
{
	int	i;
	int	j;

	i = 0;
	c_i->n_sprite = 0;
	while (c_i->map[i] != NULL)
	{
		j = 0;
		while (c_i->map[i][j])
		{
			if (c_i->map[i][j] == '2')
				c_i->n_sprite++;
			j++;
		}
		i++;
	}
}

void	get_sprite_info(t_config *c_i)
{
	int			i;
	int			j;
	int			k;
	t_sprite	*sprite;

	nbr_sprite(c_i);
	sprite = malloc(sizeof(t_sprite) * c_i->n_sprite);
	i = 0;
	k = 0;
	while (c_i->map[i] != NULL)
	{
		j = 0;
		while (c_i->map[i][j])
		{
			if (c_i->map[i][j] == '2')
			{
				sprite[k].x = j + 0.5;
				sprite[k].y = i + 0.5;
				k++;
			}
			j++;
		}
		i++;
	}
	c_i->sprite = sprite;
}

void	sort_sprite(t_config *c_i)
{
	int			i;
	t_sprite	t;
	int			is_sorted;

	is_sorted = 0;
	i = 0;
	while (is_sorted == 0)
	{
		is_sorted = 1;
		while (i < c_i->n_sprite - 1)
		{
			if (c_i->sprite[i].dist < c_i->sprite[i + 1].dist)
			{
				t = c_i->sprite[i];
				c_i->sprite[i] = c_i->sprite[i + 1];
				c_i->sprite[i + 1] = t;
				is_sorted = 0;
			}
			i++;
		}
	}
}

void	dist_sprite(t_config *c_i)
{
	int i;

	i = 0;
	while (i < c_i->n_sprite)
	{
		c_i->sprite[i].dist = (pow(c_i->player_info->map_x -
		c_i->sprite[i].x, 2) + pow(c_i->player_info->map_y -
		c_i->sprite[i].y, 2));
		i++;
	}
}
