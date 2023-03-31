/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_condition.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:07:05 by tbouzalm          #+#    #+#             */
/*   Updated: 2023/03/14 21:05:50 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	texture_no(int i, int j, t_game *map)
{
	int		len;
	int		fd;
	char	*n;

	if (map->map[i][j] == 'N' && map->map[i][j + 1] == 'O' && \
	map->map[i][j + 2] == ' ')
	{
		map->count += 1;
		len = ft_strlen(map->map[i]);
		n = ft_substr(map->map[i], ft_search(map->map[i], '.'), len);
		map->n_texture_xpm = n;
		check_extension_xpm(n);
		fd = open(n, O_RDONLY);
		if (fd == -1)
			msg_err_file();
		return (1);
	}
	return (0);
}

int	texture_so(int i, int j, t_game *map)
{
	int		len;
	char	*s;
	int		fd;

	if (map->map[i][j] == 'S' && map->map[i][j + 1] == 'O' && \
	map->map[i][j + 2] == 32)
	{
		map->count += 1;
		len = ft_strlen(map->map[i]);
		s = ft_substr(map->map[i], ft_search(map->map[i], '.'), len);
		check_extension_xpm(s);
		map->s_texture_xpm = s;
		fd = open(s, O_RDONLY);
		if (fd == -1)
			msg_err_file();
		return (1);
	}
	return (0);
}

int	texture_wo(int i, int j, t_game *map)
{
	int		len;
	int		fd;
	char	*w;

	if (map->map[i][j] == 'W' && map->map[i][j + 1] == 'E' && \
	map->map[i][j + 2] == 32)
	{
		map->count += 1;
		len = ft_strlen(map->map[i]);
		w = ft_substr(map->map[i], ft_search(map->map[i], '.'), len);
		check_extension_xpm(w);
		map->w_texture_xpm = w;
		fd = open(w, O_RDONLY);
		if (fd == -1)
			msg_err_file();
		return (1);
	}
	return (0);
}

int	texture_ea(int i, int j, t_game *map)
{
	int		len;
	int		fd;
	char	*ea;

	if (map->map[i][j] == 'E' && map->map[i][j + 1] == 'A' && \
	map->map[i][j + 2] == 32)
	{
		map->count += 1;
		len = ft_strlen(map->map[i]);
		ea = ft_substr(map->map[i], ft_search(map->map[i], '.'), len);
		check_extension_xpm(ea);
		map->e_texture_xpm = ea;
		fd = open(ea, O_RDONLY);
		if (fd == -1)
			msg_err_file();
		return (1);
	}
	return (0);
}
