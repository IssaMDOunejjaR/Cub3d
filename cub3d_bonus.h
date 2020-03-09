/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 14:02:54 by iounejja          #+#    #+#             */
/*   Updated: 2020/03/07 14:06:48 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"
# define SIZE 2
# pragma pack(2)

char			**g_conf_spec;
int				g_save;

typedef struct	s_bmp
{
	char		file_type[SIZE];
	int			file_size;
	int			reserved;
	int			offset;
	int			header_size;
	int			width;
	int			height;
	char		plane[SIZE];
	char		bpp[SIZE];
	int			compression;
	int			bit_size;
	int			perpexx;
	int			perpexy;
	int			num_color;
	int			imp_color;
}				t_bmp;

typedef struct	s_res
{
	int			width;
	int			height;
}				t_res;

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct	s_sprite
{
	double x;
	double y;
	double dist;
}				t_sprite;

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
}				t_mlx;

typedef struct	s_player
{
	double		map_x;
	double		map_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
}				t_player;

typedef struct	s_f_c
{
	float		rdx0;
	float		rdy0;
	float		rdx1;
	float		rdy1;
	int			p;
	float		pos_z;
	float		row_distance;
	float		fsx;
	float		fsy;
	float		fx;
	float		fy;
	int			cx;
	int			cy;
	int			txc;
	int			tyc;
	int			txf;
	int			tyf;
}				t_f_c;

typedef struct	s_sp
{
	double		spx;
	double		spy;
	double		inv_det;
	double		tranx;
	double		trany;
	int			sp_sc_x;
	int			sph;
	int			drsy;
	int			drey;
	int			spw;
	int			drsx;
	int			drex;
	int			stripe;
	int			textx;
	int			d;
	int			texty;
	int			color;
}				t_sp;

typedef struct	s_map
{
	double		camerax;
	double		rdx;
	double		rdy;
	double		sdx;
	double		sdy;
	double		ddx;
	double		ddy;
	double		pwd;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			mapx;
	int			mapy;
	int			lh;
	int			ds;
	int			de;
	int			texture;
	double		wall_x;
	int			text_x;
	double		step;
	double		text_pos;
	int			text_y;
	int			color;
}				t_map;

typedef struct	s_config
{
	t_res		res;
	char		*p_n;
	char		*p_s;
	char		*p_e;
	char		*p_w;
	char		*p_sp;
	char		*floor;
	char		*ceil;
	char		**map;
	int			n_sprite;
	t_player	*player_info;
	t_mlx		*conf_mlx;
	t_img		texture[6];
	t_sprite	*sprite;
}				t_config;

char			**get_info(int fd);
char			**join_tab(char **tab, char *line);
char			**tab_init(char **tab);
void			parse_info(char **conf, t_config *conf_info);
int				get_res(char **tab, t_res *res);
char			*get_path(char **tab, char *path_dest);
void			free_table(char **tab);
int				len_tab(char **tab);
void			ft_free(char **conf, t_config *conf_info);
void			init(t_config *conf_info);
int				check_valid_file(char *str, char **tmp);
void			check_prev_conf(char **conf, t_config *conf_info);
void			parse_map(char **conf, int index, t_config *conf_info);
void			invalid_conf(char **conf, t_config *conf_info);
void			get_player_info(t_config *conf_info);
void			cast_rays(t_config *conf_info);
void			get_sprite_info(t_config *conf_info);
int				ft_close(void *param);
int				key_press(int keycode, void *param);
void			move_up(t_config *c_i, double ms);
void			load_images(t_config *c_i);
void			move_up(t_config *c_i, double ms);
void			move_down(t_config *c_i, double ms);
void			move_left(t_config *c_i, double ms);
void			move_right(t_config *c_i, double ms);
void			move_camera_left(t_config *c_i);
void			move_camera_right(t_config *c_i);
void			get_sprite_info(t_config *c_i);
void			sort_sprite(t_config *c_i);
void			dist_sprite(t_config *c_i);
void			floor_and_ceil(t_config *c_i);
void			cast_sprite(t_config *c_i, double *z_buffer);
double			ft_abs(double nb);
void			cast_map(t_config *c_i, int i, t_map *map);
void			data_one(t_config *c_i, int i, t_map *map);
void			data_two(t_config *c_i, t_map *map);
void			data_three(t_config *c_i, t_map *map);
void			data_four(t_config *c_i, t_map *map);
char			direc(int side, double ray_dir_x, double ray_dir_y);
int				ft_istralpha(char *str);
void			check_map(char **conf, t_config *c_i, int l_tab, int l_str);
void			save_bmp(t_config *c_i);

#endif
