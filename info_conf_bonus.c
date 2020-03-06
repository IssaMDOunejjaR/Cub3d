/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_conf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 16:33:09 by iounejja          #+#    #+#             */
/*   Updated: 2020/03/05 17:46:45 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		ft_isnum(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int		get_res(char **tab, t_res *res)
{
	int		i;

	i = len_tab(tab);
	if (i != 3)
		return (1);
	if (ft_isnum(tab[1]))
		res->width = ft_atoi(tab[1]);
	if (ft_isnum(tab[2]))
		res->height = ft_atoi(tab[2]);
	return (0);
}

char	*get_path(char **tab, char *path_dest)
{
	char	*path;
	int		i;

	if (path_dest)
	{
		free(path_dest);
		return (NULL);
	}
	i = 0;
	while (tab[i] != NULL)
		i++;
	if (i == 2)
		path = ft_strdup(tab[1]);
	else
	{
		free(path_dest);
		return (NULL);
	}
	return (path);
}

char	**get_info(int fd)
{
	int		i;
	char	*line;
	char	**tab;

	i = 1;
	tab = NULL;
	tab = tab_init(tab);
	while (i == 1)
	{
		i = get_next_line(fd, &line);
		tab = join_tab(tab, line);
		free(line);
	}
	return (tab);
}
