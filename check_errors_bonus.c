/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:33:35 by iounejja          #+#    #+#             */
/*   Updated: 2020/03/06 14:20:53 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	invalid_conf(char **conf, t_config *c_i)
{
	ft_free(conf, c_i);
	ft_putstr_fd("Error!\n", 1);
	exit(EXIT_FAILURE);
}

void	check_prev_conf(char **conf, t_config *c_i)
{
	if (c_i->res.width == -1 || c_i->res.height == -1)
		invalid_conf(conf, c_i);
	if (!c_i->p_n || !c_i->p_s ||
	!c_i->p_w || !c_i->p_e ||
	!c_i->p_sp || !c_i->floor || !c_i->ceil)
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
