/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:15:00 by iounejja          #+#    #+#             */
/*   Updated: 2020/02/07 18:37:54 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int     fail_return(char **tmp)
{
    free_table(tmp);
    return (1);
}

int     check_res_col(char **tmp, t_config *conf_info)
{
    if (ft_strncmp(tmp[0], "R", ft_strlen(tmp[0])) == 0)
    {
        if (conf_info->res[0][0] != -1)
            return (fail_return(tmp)); 
        free_int_table(conf_info->res, 2);
        conf_info->res = get_res(tmp);
    }
    if (ft_strncmp(tmp[0], "F", ft_strlen(tmp[0])) == 0)
    {
        if (conf_info->floor[0][0] != -1)
            return (fail_return(tmp));
        free_int_table(conf_info->floor, 3);
        conf_info->floor = get_color(tmp);
    }
    if (ft_strncmp(tmp[0], "C", ft_strlen(tmp[0])) == 0)
    {
        if (conf_info->ceiling[0][0] != -1)
            return (fail_return(tmp));
        free_int_table(conf_info->ceiling, 3);
        conf_info->ceiling = get_color(tmp);
    }
    free_table(tmp);
    return (0);
}

int    check_path(char **tmp, t_config *conf_info)
{
    if (ft_strncmp(tmp[0], "NO", ft_strlen(tmp[0])) == 0)
        conf_info->path_nord = get_path(tmp, conf_info->path_nord);
    else if (ft_strncmp(tmp[0], "S", ft_strlen(tmp[0])) == 0)
        conf_info->path_spri = get_path(tmp, conf_info->path_spri);
    else if (ft_strncmp(tmp[0], "SO", ft_strlen(tmp[0])) == 0)
        conf_info->path_sud = get_path(tmp, conf_info->path_sud);
    else if (ft_strncmp(tmp[0], "WE", ft_strlen(tmp[0])) == 0)
        conf_info->path_west = get_path(tmp, conf_info->path_west);
    else if (ft_strncmp(tmp[0], "EA", ft_strlen(tmp[0])) == 0)
        conf_info->path_east = get_path(tmp, conf_info->path_east);
    free_table(tmp);
    if (ft_strncmp(tmp[0], "NO", ft_strlen(tmp[0])) == 0)
        return (check_valid_file(conf_info->path_nord));
    else if (ft_strncmp(tmp[0], "S", ft_strlen(tmp[0])) == 0)
        return (check_valid_file(conf_info->path_spri));
    else if (ft_strncmp(tmp[0], "SO", ft_strlen(tmp[0])) == 0)
        return (check_valid_file(conf_info->path_sud));
    else if (ft_strncmp(tmp[0], "WE", ft_strlen(tmp[0])) == 0)
        return (check_valid_file(conf_info->path_west));
    else if (ft_strncmp(tmp[0], "EA", ft_strlen(tmp[0])) == 0)
        return (check_valid_file(conf_info->path_east));
    return (0);
}

int    info(char *info, t_config *conf_info)
{
    char    **tmp;

    tmp =  ft_split(info, ' ');
    if ((ft_strncmp(tmp[0], "R", 1) == 0) || (ft_strncmp(tmp[0], "F", 1) == 0) ||
    (ft_strncmp(tmp[0], "C", 1) == 0))
        return (check_res_col(tmp, conf_info));
    if ((ft_strncmp(tmp[0], "NO", 1) == 0) || (ft_strncmp(tmp[0], "SO", 1) == 0) ||
    (ft_strncmp(tmp[0], "WE", 1) == 0) || (ft_strncmp(tmp[0], "EA", 1) == 0) ||
    (ft_strncmp(tmp[0], "S", 1) == 0))
        return (check_path(tmp, conf_info));
    return (0);
}

void    parse_info(char **conf, t_config *conf_info)
{
    int     i;

    i = 0;
    conf_info->res = init_int_tab(1, 2);
    conf_info->floor = init_int_tab(1, 3);
    conf_info->ceiling = init_int_tab(1, 3);
    conf_info->map = tab_init(conf_info->map);
    init_char(conf_info);
    while (conf[i] != NULL)
    {
        if (ft_isalpha(conf[i][0]))
        {
            if(info(conf[i], conf_info))
                invalid_conf(conf, conf_info);
        }
        else if (ft_isdigit(conf[i][0]))
            break ;
        i++;
    }
    check_prev_conf(conf, conf_info);
    parse_map(conf, i, conf_info);
    // printf("res = %d, %d\n", conf_info->res[0][0], conf_info->res[1][0]);
    // printf("f = %d, %d, %d\n", conf_info->floor[0][0], conf_info->floor[1][0], conf_info->floor[2][0]);
    // printf("c = %d, %d, %d\n", conf_info->ceiling[0][0], conf_info->ceiling[1][0], conf_info->ceiling[2][0]);
    // printf("no = %s\n", conf_info->path_nord);
    // printf("so = %s\n", conf_info->path_sud);
    // printf("we = %s\n", conf_info->path_west);
    // printf("ea = %s\n", conf_info->path_east);
    // printf("sp = %s\n", conf_info->path_spri);
    // i = 0;
    // while (conf_info->map[i] != NULL)
    // {
    //     printf("%s\n", conf_info->map[i]);
    //     i++;
    // }
}