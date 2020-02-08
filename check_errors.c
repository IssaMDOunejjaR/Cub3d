/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 18:26:38 by iounejja          #+#    #+#             */
/*   Updated: 2020/02/06 15:02:09 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    invalid_conf(char **conf, t_config *conf_info)
{
    ft_free(conf, conf_info);
    printf("Error");
    exit(EXIT_FAILURE);
}

int     check_col(int color)
{
    if (color >= 0 && color <= 255)
        return (0);
    return (1);
}

void    check_prev_conf(char **conf, t_config *conf_info)
{
    if (conf_info->res[0][0] < 0 || conf_info->res[1][0] < 0)
        invalid_conf(conf, conf_info);
    if (!conf_info->path_nord || !conf_info->path_sud ||
    !conf_info->path_west || !conf_info->path_east ||
    !conf_info->path_spri)
        invalid_conf(conf, conf_info);
    if (check_col(conf_info->floor[0][0]) || check_col(conf_info->floor[1][0]) ||
    check_col(conf_info->floor[2][0]))
        invalid_conf(conf, conf_info);
    if (check_col(conf_info->ceiling[0][0]) || check_col(conf_info->ceiling[1][0]) ||
    check_col(conf_info->ceiling[2][0]))
        invalid_conf(conf, conf_info);
}