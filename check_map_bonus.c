/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:49:41 by iounejja          #+#    #+#             */
/*   Updated: 2020/03/06 15:29:16 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	check_close_map_three(char **conf, t_config *c_i, int l_tab, int l_str)
{
	int i;
	int j;

	i = 0;
	while (c_i->map[i] != NULL)
	{
		j = 0;
		while (c_i->map[i][j])
		{
			if (c_i->map[i][j] == ' ')
			{
				if (i != l_tab - 1 && (c_i->map[i + 1][j] != '1'
				&& c_i->map[i + 1][j] != ' '))
					invalid_conf(conf, c_i);
				if (j != 0 && (c_i->map[i][j - 1] != '1'
				&& c_i->map[i][j - 1] != ' '))
					invalid_conf(conf, c_i);
				if (j != l_str - 1 && (c_i->map[i][j + 1] != '1'
				&& c_i->map[i][j + 1] != ' '))
					invalid_conf(conf, c_i);
			}
			j++;
		}
		i++;
	}
}

void	check_close_map_two(char **conf, t_config *c_i)
{
	int i;
	int j;
	int f;

	i = 0;
	while (c_i->map[i] != NULL)
	{
		j = 0;
		f = 0;
		while (c_i->map[i][j])
		{
			if (ft_isdigit(c_i->map[i][j]) && f == 0)
			{
				if (c_i->map[i][j] != '1')
					invalid_conf(conf, c_i);
				f = 1;
			}
			if (c_i->map[i][j] == ' ' && i != 0 && (c_i->map[i - 1][j] != '1'
			&& c_i->map[i - 1][j] != ' '))
				invalid_conf(conf, c_i);
			j++;
		}
		i++;
	}
}

void	check_close_map_one(char **conf, t_config *c_i)
{
	int i;
	int j;
	int l;

	i = 0;
	l = 0;
	while (c_i->map[i] != NULL)
	{
		j = 0;
		while (c_i->map[i][j])
		{
			while (--l > 0)
			{
				if (ft_isdigit(c_i->map[i][l]) && c_i->map[i][l] != '1')
					invalid_conf(conf, c_i);
				l--;
			}
			j++;
		}
		i++;
	}
}

void	check_map(char **conf, t_config *c_i, int l_tab, int l_str)
{
	int i;
	int j;
	int s;

	i = 0;
	s = 0;
	while (c_i->map[i] != NULL)
	{
		j = 0;
		while (c_i->map[i][j])
		{
			if (c_i->map[i][j] == 'N' || c_i->map[i][j] == 'S' ||
					c_i->map[i][j] == 'W' || c_i->map[i][j] == 'E')
				s++;
			j++;
		}
		i++;
	}
	if (s != 1)
		invalid_conf(conf, c_i);
	check_close_map_one(conf, c_i);
	check_close_map_two(conf, c_i);
	check_close_map_three(conf, c_i, l_tab, l_str);
}
