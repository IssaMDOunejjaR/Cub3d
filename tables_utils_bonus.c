/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tables_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 16:32:34 by iounejja          #+#    #+#             */
/*   Updated: 2020/03/05 18:27:03 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

char	**tab_init(char **tab)
{
	tab = (char**)malloc(sizeof(char) * 1);
	tab[0] = NULL;
	return (tab);
}

int		len_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

char	**join_tab(char **tab, char *line)
{
	char	**new_tab;
	int		i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	new_tab = malloc(sizeof(char*) * (i + 2));
	i = 0;
	while (tab[i] != NULL)
	{
		new_tab[i] = ft_strdup(tab[i]);
		i++;
	}
	new_tab[i] = ft_strdup(line);
	new_tab[++i] = NULL;
	free_table(tab);
	return (new_tab);
}

void	free_table(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
