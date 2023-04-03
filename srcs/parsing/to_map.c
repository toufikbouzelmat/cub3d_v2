/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 06:20:46 by tbouzalm          #+#    #+#             */
/*   Updated: 2023/04/03 00:41:41 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	is_upper(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	is_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	check_if_is_first_mur(int i, t_game *map)
{
	int	j;

	j = 0;
	while (map->map[i][j] != '\0')
	{
		if (map->map[i][j] == '1' || map->map[i][j] == 32 || \
		map->map[i][j] == '\n')
			j++;
		else
			return (1);
	}
	return (0);
}

int	get_map(t_game *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j] != '\0')
		{
			if (is_lower(map->map[i][j]) == 1 || is_upper(map->map[i][j]) == 1)
				break ;
			if (ft_isdigit(map->map[i][j]) == 1)
			{
				if (check_if_is_first_mur(i, map) == 0)
					return (i);
				else if (check_if_is_first_mur(i, map) == 1)
					msg_err_map();
			}
			j++;
		}
		i++;
	}
	return (0);
}
