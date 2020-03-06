/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 18:37:17 by iounejja          #+#    #+#             */
/*   Updated: 2020/03/05 17:50:49 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

char	*line(char *str, int l)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	new = malloc(sizeof(char) * (l + 1));
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	if (i < l)
	{
		while (i < l)
		{
			new[i] = ' ';
			i++;
		}
	}
	new[i] = '\0';
	return (new);
}

char	**map(char **conf, int l_tab, int l_str, int index)
{
	int		i;
	char	**map;

	i = 0;
	map = malloc(sizeof(char*) * (l_tab + 1));
	while (conf[index] != NULL)
	{
		map[i] = line(conf[index], l_str);
		i++;
		index++;
	}
	map[i] = NULL;
	return (map);
}

void	parse_map(char **conf, int index, t_config *c_i)
{
	int	i;
	int	l_tab;
	int	l_str;

	i = index;
	l_tab = 0;
	while (conf[i] != NULL)
	{
		l_tab++;
		i++;
	}
	l_str = 0;
	i = index;
	while (conf[i] != NULL)
	{
		if (ft_strlen(conf[i]) > l_str)
			l_str = ft_strlen(conf[i]);
		i++;
	}
	free_table(c_i->map);
	c_i->map = map(conf, l_tab, l_str, index);
	check_map(conf, c_i, l_tab, l_str);
	get_player_info(c_i);
}
