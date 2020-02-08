/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 16:31:48 by iounejja          #+#    #+#             */
/*   Updated: 2020/01/2017:47:04 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    draw(t_all *all_conf, int width, int height, char c)
{
    int color;
    int h;
    int w;
    int l_map;
    int w_map;

    l_map = all_conf->conf_info->res[1][0] / len_tab(all_conf->conf_info->map);
    w_map = all_conf->conf_info->res[0][0] / ft_strlen(all_conf->conf_info->map[0]);
    if (c == '1')
        color = 0xF00000;
    else if (c == '0')
        color = 0xFFFFFF;
    else if (c == '2')
        color = 0x61ff00;
    else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
        color = 0x999999;
    h = height;
    while (h < height + l_map)
    {
        w = width;
        while (w < width + w_map)
        {
            all_conf->conf_mlx->img.data[h * all_conf->conf_info->res[0][0] + w] = color;
            w++;
        }
        h++;
    }
}

void    draw_map(t_all *all_conf)
{
    int i;
    int j;
    int w;
    int h;
    int l_map;
    int w_map;

    l_map = all_conf->conf_info->res[1][0] / len_tab(all_conf->conf_info->map);
    w_map = all_conf->conf_info->res[0][0] / ft_strlen(all_conf->conf_info->map[0]);
    i = 0;
    h = 0;
    all_conf->conf_mlx->img.img_ptr = mlx_new_image(all_conf->conf_mlx->mlx_ptr, all_conf->conf_info->res[0][0], all_conf->conf_info->res[1][0]);
    all_conf->conf_mlx->img.data = (int*)mlx_get_data_addr(all_conf->conf_mlx->img.img_ptr, &all_conf->conf_mlx->img.bpp, &all_conf->conf_mlx->img.size_l, &all_conf->conf_mlx->img.endian);
    while (all_conf->conf_info->map[i] != NULL)
    {
        j = 0;
        w = 0;
        while (all_conf->conf_info->map[i][j])
        {
            if (all_conf->conf_info->map[i][j] == 'N')
            {
                all_conf->player_info->x = i;
                all_conf->player_info->y = j;
            }
            draw(all_conf, w, h, all_conf->conf_info->map[i][j]);
            w += w_map;
            j++;
        }
        h += l_map;
        i++;
    }
    mlx_put_image_to_window(all_conf->conf_mlx->mlx_ptr, all_conf->conf_mlx->win_ptr, all_conf->conf_mlx->img.img_ptr, 0, 0);
}

int key_press(int keycode, void *param)
{
    t_all *all_conf;

    all_conf = (t_all*)param;
    if (keycode == 53)
        exit(EXIT_SUCCESS);
    if (keycode == 13)
    {
        all_conf->player_info->x += 1;
        all_conf->player_info->y += 1;
        printf("x = %d, y = %d\n", all_conf->player_info->x, all_conf->player_info->y);
    }
    //printf("key = %d\n", keycode);
    return (0);
}

int ft_close(void *param)
{
    (void)param;
    exit(0);
}

void    window_conf(t_config *conf_info, t_mlx *conf_mlx, t_all *all_conf)
{
    t_player player_info;

    all_conf->conf_info = conf_info;
    all_conf->conf_mlx = conf_mlx;
    all_conf->player_info = &player_info;
    conf_mlx->mlx_ptr = mlx_init();
    conf_mlx->win_ptr = mlx_new_window(conf_mlx->mlx_ptr, conf_info->res[0][0], conf_info->res[1][0], "Cub3d");
    mlx_hook(conf_mlx->win_ptr, 17, 0, ft_close, (void*)0);
    mlx_hook(conf_mlx->win_ptr, 2, 0, key_press, all_conf);
    draw_map(all_conf);
    mlx_loop(conf_mlx->mlx_ptr);
}

int     main(int argc, char **argv)
{
    t_config    conf_info;
    t_mlx       conf_mlx;
    t_all       all_conf;
    int         fd;
    char        **conf;

    if (argc >= 2)
    {
        fd = open(argv[1], O_RDONLY);
        conf = get_info(fd);
        parse_info(conf, &conf_info);
        window_conf(&conf_info, &conf_mlx, &all_conf);
        ft_free(conf, &conf_info);
    }
    else
        printf("No arguments");
    return (0);
}