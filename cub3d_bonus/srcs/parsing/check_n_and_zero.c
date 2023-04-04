/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_n_and_zero.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 08:58:40 by tbouzalm          #+#    #+#             */
/*   Updated: 2023/03/09 14:40:24 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_zero(int i, int j, t_game *map)
{
	if (map->contenu[i][j + 1] == '2' || map->contenu[i][j - 1] == '2' || \
	map->contenu[i + 1][j] == '2' || map->contenu[i - 1][j] == '2' )
		msg_err_map();
}
