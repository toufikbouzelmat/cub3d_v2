/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_contenu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 01:56:08 by tbouzalm          #+#    #+#             */
/*   Updated: 2023/03/30 01:37:25 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	norm_function_remplir_contenu(int id, int i, t_game *map, int j)
{
	while (map->map[i][j] != '\0')
	{
		if (map->map[i][j] == ' ')
			map->contenu[id][j] = '2';
		else
			map->contenu[id][j] = map->map[i][j];
		j++;
	}
	while (j <= ft_get_max_line(map))
	{
		map->contenu[id][j] = '2';
		j++;
	}
	map->contenu[id][j] = '\0';
}

int	remplire_contenu(t_game *map)
{
	int	i;
	int	j;
	int	id;

	id = 0;
	map->contenu = malloc(sizeof(char *) * (nbr_de_line_map(map) + 1));
	protection_mall(map->contenu);
	i = get_map(map);
	while (map->map[i])
	{
		j = 0;
		map->contenu[id] = malloc(sizeof(char *) * (1 + ft_get_max_line(map)));
		protection_mall(map->contenu);
		norm_function_remplir_contenu(id, i, map, j);
		i++;
		id++;
	}
	map->contenu[id] = NULL;
	nbr_de_line_contenu(map);
	return (0);
}
