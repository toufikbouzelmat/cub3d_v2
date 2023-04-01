/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_contenu_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 05:51:12 by tbouzalm          #+#    #+#             */
/*   Updated: 2023/04/01 07:25:03 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	last_line_mur(t_game *map)
{
	int	i;
	int	last_line;
	int	len;

	last_line = 0;
	while (map && map->contenu && map->contenu[last_line])
		last_line++;
	last_line--;
	len = ft_strlen(map->contenu[last_line]);
	i = 0;
	while (i < len)
	{
		if (map->contenu[last_line][i] != '1' && \
		map->contenu[last_line][i] != '2')
			msg_err_map();
		i++;
	}
}

void	first_and_last_of_line(t_game *map)
{
	int	i;
	int	len;

	i = 0;
	while (map->contenu[i] != NULL)
	{
		len = ft_strlen(map->contenu[i]);
		if ((map->contenu[i][0] == '1' || map->contenu[i][0] == '2') && \
		(map->contenu[i][len - 1] == '1' || map->contenu[i][len - 1] == '2'))
			i++;
		else
			msg_err_map();
	}
}

int	verifie_player_and_zero(t_game *map)
{
	int	i;
	int	j;

	i = 1;
	while (map->contenu[i])
	{
		j = 0;
		while (map->contenu[i][j] != '\0')
		{
			if (map->contenu[i][j] == '0' || map->contenu[i][j] == 'N' \
			|| map->contenu[i][j] == 'E' || map->contenu[i][j] == 'S' || \
			map->contenu[i][j] == 'W')
				ft_zero(i, j, map);
			j++;
		}
		i++;
	}
	return (0);
}

void	last_check_empty_line(t_game *map)
{
	int	i;
	int	len;
	int	c;
	int	j;

	i = 0;
	len = ft_strlen(map->contenu[i]);
	while (map->contenu[i])
	{
		j = 0;
		c = 0;
		while (map->contenu[i][j] != '\0')
		{
			if (map->contenu[i][j] != '0' && map->contenu[i][j] != '1' && \
			map->contenu[i][j] != 'N' \
			&& map->contenu[i][j] != 'E' && map->contenu[i][j] != 'S' && \
			map->contenu[i][j] != 'W')
				c += 1;
			j++;
		}
		if (c == len)
			msg_err_empty();
		i++;
	}
}

int	check_map_contenu(t_game *map)
{
	last_line_mur(map);
	first_and_last_of_line(map);
	verifie_player_and_zero(map);
	last_check_empty_line(map);
	return (0);
}
