/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_condition.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:07:05 by tbouzalm          #+#    #+#             */
/*   Updated: 2023/04/01 09:15:23 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	check_after_pos_tex(t_game *map, int i, int j)
{
	while (map->map[i][j] != '\0')
	{
		if ((map->map[i][j] >= '0' && map->map[i][j] <= '9') \
		|| (map->map[i][j] >= 'a' && map->map[i][j] <= 'z') \
		|| (map->map[i][j] >= 'A' && map->map[i][j] <= 'Z'))
			msg_err_texture();
		if (map->map[i][j] == '.')
			break ;
		j++;
	}
}

int	texture_no(int i, int j, t_game *map)
{
	int		len;
	int		fd;
	char	*n;

	if (map->map[i][j] == 'N' && map->map[i][j + 1] == 'O' && \
	map->map[i][j + 2] == ' ')
	{
		j = 2;
		check_after_pos_tex(map, i, j);
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
		j = 2;
		check_after_pos_tex(map, i, j);
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
		j = 2;
		check_after_pos_tex(map, i, j);
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
		j = 2;
		check_after_pos_tex(map, i, j);
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
