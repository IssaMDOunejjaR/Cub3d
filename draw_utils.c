/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 18:40:08 by iounejja          #+#    #+#             */
/*   Updated: 2020/02/08 18:44:44 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    draw_car(t_config *conf_info, t_mlx *conf_mlx, int width, int height)
{
    int h;
    int w;

    h = height;
    while (h < height + 20)
    {
        w = width;
        while (w < width + 20)
        {
            conf_mlx->img.data[h * conf_info->res[0][0] + w] = color;
            w++;
        }
        h++;
    }
}