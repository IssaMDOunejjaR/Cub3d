/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 18:37:17 by iounejja          #+#    #+#             */
/*   Updated: 2020/02/06 14:02:09 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    check_map(char **conf, t_config *conf_info, int l_tab, int l_str)
{
    int i;
    int j;

    i = 0;
    while (conf_info->map[i] != NULL)
    {
        j = 0;
        if (ft_strlen(conf_info->map[i]) != l_str)
            invalid_conf(conf, conf_info);
        while (conf_info->map[i][j])
        {
            if ((conf_info->map[i][j] >= '0' && conf_info->map[i][j] <= '2') ||
            (conf_info->map[i][j] == 'N' || conf_info->map[i][j] == 'S' ||
            conf_info->map[i][j] == 'E' || conf_info->map[i][j] == 'W'))
            {
                if (conf_info->map[0][j] != '1' || conf_info->map[l_tab - 1][j] != '1' ||
                conf_info->map[i][0] != '1' || conf_info->map[i][l_str - 1] != '1')
                    invalid_conf(conf, conf_info);
            }
            else
                invalid_conf(conf, conf_info);
            j++;
        }
        i++;
    }
}

char    *line(char *str, int l)
{
    int i;
    int j;
    char *new;

    i = 0;
    j = 0;
    new = malloc(sizeof(char) * (l + 1));
    while (str[i])
    {
        if (str[i] != ' ')
        {
            new[j] = str[i];
            j++;
        }
        i++;
    }
    new[j] = '\0';
    return (new);
}

void    map(char **conf, int l_tab, int l_str, int index, t_config *conf_info)
{
    int i;
    int j;
    int k;
    char    *str;

    j = 0;
    free_table(conf_info->map);
    conf_info->map = malloc(sizeof(char*) * (l_tab + 1));
    while (conf[index] != NULL)
    {
        conf_info->map[j] = line(conf[index], l_str);
        j++;
        index++;
    }
    conf_info->map[j] = NULL;
}

void    parse_map(char **conf, int index, t_config *conf_info)
{
    int i;
    int l_tab;
    int l_str;

    i = index;
    l_tab = 0;
    while (conf[i] != NULL)
    {
        if (conf[i][0] == ' ' || !ft_isdigit(conf[i][0]))
            invalid_conf(conf, conf_info);
        l_tab++;
        i++;
    }
    l_str = 0;
    i = 0;
    while (conf[index][i])
    {
        if (conf[index][i] != ' ')
            l_str++;
        i++;
    }
    map(conf, l_tab, l_str, index, conf_info);
    check_map(conf, conf_info, l_tab, l_str);
}