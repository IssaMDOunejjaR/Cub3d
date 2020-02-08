/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_conf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 16:33:09 by iounejja          #+#    #+#             */
/*   Updated: 2020/01/2218:34:37 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int    **get_res(char **tab)
{
    int    **res;
    int     i;

    i = len_tab(tab);
    if (i == 3)
        res = malloc(sizeof(int*) * 2);
    else
        return (init_int_tab(1, 2));
    res[0] = malloc(sizeof(int) * 1);
    res[1] = malloc(sizeof(int) * 1);
    res[0][0] = ft_atoi(tab[1]);
    res[1][0] = ft_atoi(tab[2]);
    return (res);
}

char    *get_path(char **tab, char *path_dest)
{
    char    *path;
    int     i;

    if(path_dest)
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

int    **get_color(char **tab)
{
    char    **rgb;
    int     **color;
    int     i;

    i = len_tab(tab);
    if (i == 2)
        rgb = ft_split(tab[1], ',');
    else
        return (init_int_tab(1, 3));
    i = len_tab(rgb);
    if (i == 3)
        color = malloc(sizeof(int*) * 3);
    else
    {
        free_table(rgb);
        return (init_int_tab(1, 3));
    }
    color[0] = malloc(sizeof(int) * 1);
    color[1] = malloc(sizeof(int) * 1);
    color[2] = malloc(sizeof(int) * 1);
    color[0][0] = ft_atoi(rgb[0]);
    color[1][0] = ft_atoi(rgb[1]);
    color[2][0] = ft_atoi(rgb[2]);
    free_table(rgb);
    return (color);
}

char    **get_info(int fd)
{
    int     i;
    char    *line;
    char    **tab;

    i = 1;
    tab = tab_init(tab);
    while (i == 1)
    {
        i = get_next_line(fd, &line);
        tab = join_tab(tab, line);
        free(line);
    }
    return (tab);
}