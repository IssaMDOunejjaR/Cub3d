/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_config_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:28:23 by iounejja          #+#    #+#             */
/*   Updated: 2020/03/06 18:40:57 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		ft_istralpha(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (!ft_isalpha(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_free(char **conf, t_config *c_i)
{
	free_table(conf);
	free(c_i->p_n);
	free(c_i->p_s);
	free(c_i->p_e);
	free(c_i->p_w);
	free(c_i->p_sp);
	free(c_i->floor);
	free(c_i->ceil);
	free_table(c_i->map);
}

void	init(t_config *c_i)
{
	c_i->res.width = -1;
	c_i->res.height = -1;
	c_i->p_n = NULL;
	c_i->p_s = NULL;
	c_i->p_e = NULL;
	c_i->p_w = NULL;
	c_i->p_sp = NULL;
	c_i->floor = NULL;
	c_i->ceil = NULL;
	c_i->map = tab_init(c_i->map);
}

int		check_valid_file(char *str, char **tmp)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		free_table(tmp);
		return (1);
	}
	free_table(tmp);
	return (0);
}
