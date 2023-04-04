/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_condition.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:07:05 by tbouzalm          #+#    #+#             */
/*   Updated: 2023/04/04 05:45:36 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	check_after_pos_tex(t_game *map, int i, int j)
{
	while (map->map[i][j] != '\0')
	{
		if ((map->map[i][j] >= '!' && map->map[i][j] <= '-') \
		|| (map->map[i][j] >= '/' && map->map[i][j] <= '~') \
		|| (map->map[i][j] == '\t'))
			puterr("after tree caractere texture");
		if (map->map[i][j] == '.')
			break ;
		j++;
	}
}

int	texture_no(int i, int j, t_game *map)
{
	char	*n;

	j = 0;
	while (map->map[i][j] == ' ')
		j++;
	if (map->map[i][j] == '\t')
		msg_err_tab();
	if (map->map[i][j] == 'N' && map->map[i][j + 1] == 'O' && \
	map->map[i][j + 2] == ' ')
	{
		j += 2;
		if (map->count_txt_n == 1)
			puterr("Duplicate Texture No");
		check_after_pos_tex(map, i, j);
		map->count += 1;
		n = ft_substr(map->map[i], ft_search(map->map[i], '.'), \
		ft_strlen(map->map[i]));
		map->n_texture_xpm = n;
		check_extension_xpm(n);
		check_path_existe(n);
		map->count_txt_n++;
		return (1);
	}
	return (0);
}

int	texture_so(int i, int j, t_game *map)
{
	char	*s;

	j = 0;
	while (map->map[i][j] == ' ')
			j++;
	if (map->map[i][j] == '\t')
		msg_err_tab();
	if (map->map[i][j] == 'S' && map->map[i][j + 1] == 'O' && \
	map->map[i][j + 2] == ' ')
	{
		j += 2;
		if (map->count_txt_s == 1)
			puterr("Duplicate Texture So");
		check_after_pos_tex(map, i, j);
		map->count += 1;
		s = ft_substr(map->map[i], ft_search(map->map[i], '.'), \
		ft_strlen(map->map[i]));
		check_extension_xpm(s);
		map->s_texture_xpm = s;
		check_path_existe(s);
		map->count_txt_s++;
		return (1);
	}
	return (0);
}

int	texture_wo(int i, int j, t_game *map)
{
	char	*w;

	j = 0;
	while (map->map[i][j] == ' ')
			j++;
	if (map->map[i][j] == '\t')
		msg_err_tab();
	if (map->map[i][j] == 'W' && map->map[i][j + 1] == 'E' && \
	map->map[i][j + 2] == 32)
	{
		j += 2;
		if (map->count_txt_w == 1)
			puterr("Duplicate Texture Wo");
		check_after_pos_tex(map, i, j);
		map->count += 1;
		w = ft_substr(map->map[i], ft_search(map->map[i], '.'), \
		ft_strlen(map->map[i]));
		check_extension_xpm(w);
		map->w_texture_xpm = w;
		check_path_existe(w);
		map->count_txt_w++;
		return (1);
	}
	return (0);
}

int	texture_ea(int i, int j, t_game *map)
{
	char	*ea;

	j = 0;
	while (map->map[i][j] == ' ')
			j++;
	if (map->map[i][j] == '\t')
		msg_err_tab();
	if (map->map[i][j] == 'E' && map->map[i][j + 1] == 'A' && \
	map->map[i][j + 2] == 32)
	{
		j += 2;
		if (map->count_txt_e == 1)
			puterr("Duplicate Texture EA");
		check_after_pos_tex(map, i, j);
		map->count += 1;
		ea = ft_substr(map->map[i], ft_search(map->map[i], '.'), \
		ft_strlen(map->map[i]));
		check_extension_xpm(ea);
		map->e_texture_xpm = ea;
		check_path_existe(ea);
		map->count_txt_e++;
		return (1);
	}
	return (0);
}
