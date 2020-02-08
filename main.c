/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/1018:00:38 by iounejja          #+#    #+#             */
/*   Updated: 2020/01/16 19:47:42by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
    - (void *)mlx_init()
    - (void *)mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title)
    - (int)mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color)
*/

#include "cub3d.h"

int     key(int k, void *param)
{
    printf("key = %d\n", k);
    return (0);
}

int     main()
{
    void    *mlx_ptr;
    void    *win_ptr;
    int     i;

    i = 10;
    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 500, 500, "issam");
    while (i < 100)
    {
        mlx_pixel_put(mlx_ptr, win_ptr, i, 100, 0xF00000);
        i++;
    }
    i = 100;
    while (i < 200)
    {
        mlx_pixel_put(mlx_ptr, win_ptr, 100, i, 0xF00000);
        i++;
    }
    i = 100;
    while (i < 200)
    {
        mlx_pixel_put(mlx_ptr, win_ptr, 10, i, 0xF00000);
        i++;
    }
    i = 10;
    while (i < 100)
    {
        mlx_pixel_put(mlx_ptr, win_ptr, i, 200, 0xF00000);
        i++;
    }
    mlx_key_hook(win_ptr, key, (void *)0);
    mlx_loop(mlx_ptr);
}