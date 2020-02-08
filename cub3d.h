/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 19:45:12 by ounejja           #+#    #+#             */
/*   Updated: 2020/02/08 19:01:29 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"

typedef struct  s_img
{
    void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}               t_img;

typedef struct  s_mlx
{
    void    *mlx_ptr;
    void    *win_ptr;
    t_img   img;
}               t_mlx;

typedef struct  s_player
{
    int     x;
    int     y;
}               t_player;

typedef struct  s_config
{
    int     **res;
    char    *path_nord;
    char    *path_sud;
    char    *path_east;
    char    *path_west;
    char    *path_spri;
    int     **floor;
    int     **ceiling;
    char    **map;
}               t_config;

typedef struct  s_all
{
    t_config    *conf_info;
    t_mlx       *conf_mlx;
    t_player    *player_info;
}               t_all;

char    **get_info(int fd);
char    **join_tab(char **tab, char *line);
char    **tab_init(char **tab);
void    parse_info(char **conf, t_config *conf_info);
int     **get_color(char **tab);
int     **get_res(char **tab);
char    *get_path(char **tab, char *path_dest);
void    free_table(char **tab);
void    free_int_table(int **tab, int len);
int     len_tab(char **tab);
void    ft_free(char **conf, t_config *conf_info);
int     **init_int_tab(int width, int height);
void    init_char(t_config *conf_info);
int     check_valid_file(char *str);
void    check_prev_conf(char **conf, t_config *conf_info);
void    parse_map(char **conf, int index, t_config *conf_info);
void    invalid_conf(char **conf, t_config *conf_info);

#endif