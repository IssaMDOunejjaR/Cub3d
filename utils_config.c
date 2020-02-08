/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 13:51:49 by iounejja          #+#    #+#             */
/*   Updated: 2020/02/06 15:02:13 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    ft_free(char **conf, t_config *conf_info)
{
    free_table(conf);
    free_int_table(conf_info->res, 2);
    free_int_table(conf_info->floor, 3);
    free_int_table(conf_info->ceiling, 3);
    free(conf_info->path_nord);
    free(conf_info->path_sud);
    free(conf_info->path_east);
    free(conf_info->path_west);
    free(conf_info->path_spri);
    free_table(conf_info->map);
}

void    init_char(t_config *conf_info)
{
    conf_info->path_nord = NULL;
    conf_info->path_sud = NULL;
    conf_info->path_east = NULL;
    conf_info->path_west = NULL;
    conf_info->path_spri = NULL;
}

int    **init_int_tab(int width, int height)
{
    int i;
    int j;
    int **tab;

    i = 0;
    tab = malloc(height * sizeof(int*));
    while (i < height)
    {
        j = 0;
        tab[i] = malloc(width * sizeof(int));
        while (j < width)
        {
            tab[i][j] = -1;
            j++;
        }
        i++;
    }
    return (tab);
}

int     check_valid_file(char *str)
{
    int fd;

    fd = open(str, O_RDONLY);
    if (fd == -1)
        return (1);
    return (0);
}