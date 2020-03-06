/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 14:01:03 by iounejja          #+#    #+#             */
/*   Updated: 2020/03/06 13:59:53 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		fail_return(char **tmp)
{
	free_table(tmp);
	return (1);
}

int		check_res_col(char **tmp, t_config *c_i)
{
	if (ft_strncmp(tmp[0], "R", ft_strlen(tmp[0])) == 0)
	{
		if (c_i->res.width != -1)
			return (fail_return(tmp));
		if (get_res(tmp, &c_i->res))
			return (fail_return(tmp));
	}
	free_table(tmp);
	return (0);
}

int		check_path(char **tmp, t_config *c_i)
{
	if (ft_strcmp(tmp[0], "NO") == 0)
		c_i->p_n = get_path(tmp, c_i->p_n);
	else if (ft_strcmp(tmp[0], "S") == 0)
		c_i->p_sp = get_path(tmp, c_i->p_sp);
	else if (ft_strcmp(tmp[0], "SO") == 0)
		c_i->p_s = get_path(tmp, c_i->p_s);
	else if (ft_strcmp(tmp[0], "WE") == 0)
		c_i->p_w = get_path(tmp, c_i->p_w);
	else if (ft_strcmp(tmp[0], "EA") == 0)
		c_i->p_e = get_path(tmp, c_i->p_e);
	if (ft_strcmp(tmp[0], "NO") == 0)
		return (check_valid_file(c_i->p_n, tmp));
	else if (ft_strcmp(tmp[0], "S") == 0)
		return (check_valid_file(c_i->p_sp, tmp));
	else if (ft_strcmp(tmp[0], "SO") == 0)
		return (check_valid_file(c_i->p_s, tmp));
	else if (ft_strcmp(tmp[0], "WE") == 0)
		return (check_valid_file(c_i->p_w, tmp));
	else if (ft_strcmp(tmp[0], "EA") == 0)
		return (check_valid_file(c_i->p_e, tmp));
	return (0);
}

int		info(char *info, t_config *c_i, char **conf)
{
	char	**tmp;

	tmp = ft_split(info, ' ');
	if (ft_strcmp(tmp[0], "F") == 0)
		c_i->floor = get_path(tmp, c_i->floor);
	else if (ft_strcmp(tmp[0], "C") == 0)
		c_i->ceil = get_path(tmp, c_i->ceil);
	if (ft_strcmp(tmp[0], "F") == 0)
		return (check_valid_file(c_i->floor, tmp));
	else if (ft_strcmp(tmp[0], "C") == 0)
		return (check_valid_file(c_i->ceil, tmp));
	if (ft_strcmp(tmp[0], "R") == 0)
		return (check_res_col(tmp, c_i));
	else if ((ft_strcmp(tmp[0], "NO") == 0) || (ft_strcmp(tmp[0], "SO") == 0) ||
			(ft_strcmp(tmp[0], "WE") == 0) || (ft_strcmp(tmp[0], "EA") == 0) ||
			(ft_strcmp(tmp[0], "S") == 0))
		return (check_path(tmp, c_i));
	else
		invalid_conf(conf, c_i);
	return (0);
}

void	parse_info(char **conf, t_config *c_i)
{
	int		i;
	int		m;

	i = 0;
	init(c_i);
	while (conf[i] != NULL)
	{
		g_conf_spec = ft_split(conf[i], ' ');
		if (ft_isalpha(conf[i][0]))
		{
			if (info(conf[i], c_i, conf))
				invalid_conf(conf, c_i);
		}
		else if (g_conf_spec[0] && (m = ft_isdigit(g_conf_spec[0][0])))
			break ;
		free_table(g_conf_spec);
		i++;
	}
	check_prev_conf(conf, c_i);
	if (m == 1)
		parse_map(conf, i, c_i);
	else
		invalid_conf(conf, c_i);
}
