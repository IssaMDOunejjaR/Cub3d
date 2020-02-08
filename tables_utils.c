/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tables_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 16:32:34 by iounejja          #+#    #+#             */
/*   Updated: 2020/02/05 15:25:56 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char    **tab_init(char **tab)
{
    tab = (char**)malloc(sizeof(char) * 1);
    tab[0] = NULL;
    return (tab);
}

int     len_tab(char **tab)
{
    int     i;

    i = 0;
    while (tab[i] != NULL)
        i++;
    return (i);
}

char    **join_tab(char **tab, char *line)
{
    char    **new_tab;
    int     i;

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

void    free_table(char **tab)
{
    int     i;

    i = 0;
    while (tab[i] != NULL)
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}

void    free_int_table(int **tab, int len)
{
    int     i;

    i = 0;
    while (i < len)
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}