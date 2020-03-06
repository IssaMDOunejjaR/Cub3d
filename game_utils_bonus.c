/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:06:42 by iounejja          #+#    #+#             */
/*   Updated: 2020/03/05 18:03:37 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	load(t_config *c_i)
{
	c_i->texture[0].data =
		(int*)mlx_get_data_addr(c_i->texture[0].img_ptr, &c_i->texture[0].bpp,
				&c_i->texture[0].size_l, &c_i->texture[0].endian);
	c_i->texture[1].data =
		(int*)mlx_get_data_addr(c_i->texture[1].img_ptr, &c_i->texture[1].bpp,
				&c_i->texture[1].size_l, &c_i->texture[1].endian);
	c_i->texture[2].data =
		(int*)mlx_get_data_addr(c_i->texture[2].img_ptr, &c_i->texture[2].bpp,
				&c_i->texture[2].size_l, &c_i->texture[2].endian);
	c_i->texture[3].data =
		(int*)mlx_get_data_addr(c_i->texture[3].img_ptr, &c_i->texture[3].bpp,
				&c_i->texture[3].size_l, &c_i->texture[3].endian);
	c_i->texture[4].data =
		(int*)mlx_get_data_addr(c_i->texture[4].img_ptr, &c_i->texture[4].bpp,
				&c_i->texture[4].size_l, &c_i->texture[4].endian);
	c_i->texture[5].data =
		(int*)mlx_get_data_addr(c_i->texture[5].img_ptr, &c_i->texture[5].bpp,
				&c_i->texture[5].size_l, &c_i->texture[5].endian);
	c_i->texture[6].data =
		(int*)mlx_get_data_addr(c_i->texture[6].img_ptr, &c_i->texture[6].bpp,
				&c_i->texture[6].size_l, &c_i->texture[6].endian);
}

void	load_images(t_config *c_i)
{
	c_i->texture[0].img_ptr =
		mlx_xpm_file_to_image(c_i->conf_mlx->mlx_ptr,
				c_i->p_n, &c_i->texture[0].width, &c_i->texture[0].height);
	c_i->texture[1].img_ptr =
		mlx_xpm_file_to_image(c_i->conf_mlx->mlx_ptr,
				c_i->p_s, &c_i->texture[1].width, &c_i->texture[1].height);
	c_i->texture[2].img_ptr =
		mlx_xpm_file_to_image(c_i->conf_mlx->mlx_ptr,
				c_i->p_e, &c_i->texture[2].width, &c_i->texture[2].height);
	c_i->texture[3].img_ptr =
		mlx_xpm_file_to_image(c_i->conf_mlx->mlx_ptr,
				c_i->p_w, &c_i->texture[3].width, &c_i->texture[3].height);
	c_i->texture[4].img_ptr =
		mlx_xpm_file_to_image(c_i->conf_mlx->mlx_ptr,
				c_i->floor, &c_i->texture[4].width, &c_i->texture[4].height);
	c_i->texture[5].img_ptr =
		mlx_xpm_file_to_image(c_i->conf_mlx->mlx_ptr,
				c_i->ceil, &c_i->texture[5].width, &c_i->texture[5].height);
	c_i->texture[6].img_ptr =
		mlx_xpm_file_to_image(c_i->conf_mlx->mlx_ptr,
				c_i->p_sp, &c_i->texture[6].width, &c_i->texture[6].height);
	load(c_i);
}

int		key_press(int keycode, void *param)
{
	t_config	*c_i;
	double		ms;

	ms = 0.3;
	c_i = (t_config*)param;
	c_i->map[(int)c_i->player_info->map_y][(int)c_i->player_info->map_x] = '0';
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	if (keycode == 13)
		move_up(c_i, ms);
	if (keycode == 0)
		move_down(c_i, ms);
	if (keycode == 2)
		move_right(c_i, ms);
	if (keycode == 1)
		move_left(c_i, ms);
	if (keycode == 123)
		move_camera_left(c_i);
	if (keycode == 124)
		move_camera_right(c_i);
	mlx_destroy_image(c_i->conf_mlx->mlx_ptr, c_i->conf_mlx->img.img_ptr);
	c_i->conf_mlx->img.img_ptr = mlx_new_image(c_i->conf_mlx->mlx_ptr,
			c_i->res.width, c_i->res.height);
	cast_rays(c_i);
	return (0);
}

int		ft_close(void *param)
{
	(void)param;
	exit(EXIT_SUCCESS);
}
