/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 18:26:38 by iounejja          #+#    #+#             */
/*   Updated: 2020/03/09 17:54:58 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	invalid_conf(char **conf, t_config *c_i)
{
	ft_free(conf, c_i);
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd("invalid config\n", 1);
	exit(EXIT_FAILURE);
}

int		check_col(int color)
{
	if (color >= 0 && color <= 255)
		return (0);
	return (1);
}

void	check_prev_conf(char **conf, t_config *c_i)
{
	if (c_i->res.width == -1 || c_i->res.height == -1 ||
	c_i->floor.r == -1 || c_i->ceil.r == -1)
		invalid_conf(conf, c_i);
	if (!c_i->p_n || !c_i->p_s ||
	!c_i->p_w || !c_i->p_e ||
	!c_i->p_sp)
		invalid_conf(conf, c_i);
	if (check_col(c_i->floor.r) || check_col(c_i->floor.g) ||
	check_col(c_i->floor.b) || check_col(c_i->ceil.r) ||
	check_col(c_i->ceil.g) || check_col(c_i->ceil.b))
		invalid_conf(conf, c_i);
	if (c_i->res.width > 2560 || c_i->res.height > 1440)
	{
		c_i->res.width = 2560;
		c_i->res.height = 1440;
	}
	else if (c_i->res.width < 640 || c_i->res.height < 360)
	{
		c_i->res.width = 640;
		c_i->res.height = 360;
	}
}
