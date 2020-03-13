/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 16:31:48 by iounejja          #+#    #+#             */
/*   Updated: 2020/03/10 17:40:45 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	window_conf(t_config *c_i)
{
	c_i->conf_mlx->mlx_ptr = mlx_init();
	if (g_save == 0)
		c_i->conf_mlx->win_ptr = mlx_new_window(c_i->conf_mlx->mlx_ptr,
		c_i->res.width, c_i->res.height, "Cub3d");
	c_i->conf_mlx->img.img_ptr = mlx_new_image(c_i->conf_mlx->mlx_ptr,
	c_i->res.width, c_i->res.height);
	c_i->conf_mlx->img.data = (int*)mlx_get_data_addr(
	c_i->conf_mlx->img.img_ptr, &c_i->conf_mlx->img.bpp,
	&c_i->conf_mlx->img.size_l, &c_i->conf_mlx->img.endian);
	load_images(c_i);
	get_sprite_info(c_i);
	cast_rays(c_i);
	if (g_save == 0)
	{
		mlx_hook(c_i->conf_mlx->win_ptr, 2, 0, key_press, c_i);
		mlx_hook(c_i->conf_mlx->win_ptr, 17, 0, ft_close, (void*)0);
		mlx_loop(c_i->conf_mlx->mlx_ptr);
	}
}

void	collect_data(t_config *c_i, char **conf, char *file)
{
	t_mlx		conf_mlx;
	t_player	player_info;
	int			fd;
	char		**tmp;

	c_i->conf_mlx = &conf_mlx;
	c_i->player_info = &player_info;
	tmp = ft_split(file, '.');
	if (ft_strcmp(tmp[len_tab(tmp) - 1], "cub") == 0)
	{
		fd = open(file, O_RDONLY);
		if (fd == -1)
		{
			ft_putstr_fd("Error\n", 1);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		ft_putstr_fd("Error\n", 1);
		exit(EXIT_FAILURE);
	}
	conf = get_info(fd);
	parse_info(conf, c_i);
	window_conf(c_i);
}

int		main(int argc, char **argv)
{
	t_config	c_i;
	char		**conf;

	conf = NULL;
	g_save = 0;
	if (argc >= 2 && argc <= 3)
	{
		if (argc == 3)
		{
			if (ft_strcmp(argv[2], "--save") == 0)
				g_save = 1;
			else
			{
				ft_putstr_fd("Error\n", 1);
				exit(1);
			}
		}
		collect_data(&c_i, conf, argv[1]);
		ft_free(conf, &c_i);
	}
	else
		ft_putstr_fd("Error\n", 1);
	return (0);
}
