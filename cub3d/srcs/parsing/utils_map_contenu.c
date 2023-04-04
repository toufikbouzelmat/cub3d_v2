/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map_contenu.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:29:42 by tbouzalm          #+#    #+#             */
/*   Updated: 2023/03/10 16:01:22 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_get_max_line(t_game *map)
{
	int	i;
	int	len_current;
	int	len_max;

	i = get_map(map);
	len_current = 0;
	len_max = 0;
	while (i < map->nbr_lines)
	{
		len_current = ft_strlen(map->map[i]);
		if (len_current > len_max)
			len_max = len_current;
		i++;
	}
	map->nbr_colums = len_max;
	return (len_max);
}

int	ft_player_or_mur(char c, t_game	*map)
{
	if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
	{
		map->p += 1;
		return (0);
	}
	else if (c == '1' || c == 32 || c == '0' || c == '\n')
		return (0);
	else
	{
		msg_err_map();
	}
	return (1);
}

void	verife_map_avant_allocer(t_game *map)
{
	int	i;
	int	j;

	i = get_map(map);
	while (map->map[i])
	{
		j = 0;
		if (map->map[i] == '\0')
			msg_err_map();
		while (map->map[i][j] != '\0')
		{
			if (ft_player_or_mur(map->map[i][j], map) == 0)
				j++;
		}
		i++;
	}
}

void	nbr_de_line_contenu(t_game *map)
{
	int	i;

	i = 0;
	while (map->contenu[i])
		i++;
	map->nbr_lines_contenu = i;
}

int	nbr_de_line_map(t_game *map)
{
	int	i;
	int	c;

	i = get_map(map);
	c = 0;
	while (map->map[i])
	{
		c++;
		i++;
	}
	verife_map_avant_allocer(map);
	if (map->p > 1 || map->p == 0)
		msg_err_player();
	return (c);
}
