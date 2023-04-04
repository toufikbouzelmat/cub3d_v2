/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 20:13:58 by tbouzalm          #+#    #+#             */
/*   Updated: 2023/03/23 20:14:01 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	**ft_realloc(char **map, int size)
{
	char	**new_map;
	int		i;

	i = 0;
	if (map == NULL)
		return ((char **)malloc((size + 1) * sizeof(char *)));
	if (size == 0)
		return (NULL);
	new_map = (char **)malloc((size + 1) * sizeof(char *));
	if (!new_map)
		exit(1);
	while (i < size)
	{
		new_map[i] = map[i];
		i++;
	}
	new_map[size] = NULL;
	free(map);
	return (new_map);
}
