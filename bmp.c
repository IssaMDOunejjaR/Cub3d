/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 09:34:10 by mymik             #+#    #+#             */
/*   Updated: 2020/03/06 12:02:31 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bmp	new_bmp(int w, int h)
{
	t_bmp bmp;

	bmp.file_type[0] = 'B';
	bmp.file_type[1] = 'M';
	bmp.file_size = 54 + 4 * w * h;
	bmp.reserved = 0;
	bmp.offset = 54;
	bmp.header_size = 54 - 14;
	bmp.width = w;
	bmp.height = -h;
	bmp.plane[0] = 1;
	bmp.plane[1] = 0;
	bmp.bpp[0] = 32;
	bmp.bpp[1] = 0;
	bmp.compression = 0;
	bmp.bit_size = 4 * w * h;
	bmp.perpexx = 0;
	bmp.perpexy = 0;
	bmp.num_color = 0;
	bmp.imp_color = 0;
	return (bmp);
}

void	write_bytes(int *line, int w, int fd)
{
	int i;

	i = 0;
	while (i < w)
	{
		write(fd, &line[i], 4);
		i++;
	}
}

void	write_bitmap(int *data, int h, int w, int fd)
{
	int i;

	i = 0;
	while (i < h)
	{
		write_bytes(&data[i * w], w, fd);
		i++;
	}
}

void	save_bmp(t_config *c_i)
{
	t_bmp	bmp;
	int		fd;

	bmp = new_bmp(c_i->res.width, c_i->res.height);
	fd = open("save.bmp", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	write(fd, &bmp, 54);
	write_bitmap(c_i->conf_mlx->img.data, c_i->res.height, c_i->res.width, fd);
}
