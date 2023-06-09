/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:21:49 by tbouzalm          #+#    #+#             */
/*   Updated: 2023/04/03 09:23:25 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	norm_check_line_f(int i, int j, t_game *map)
{
	map->floor.count_color_f += 1;
	if (ft_check_virgule(map->map[i]) != 2)
		msg_err_f();
	ft_check_val_f(&map->map[i][j], map);
}

void	norm_check_line_c(int i, int j, t_game *map)
{
	map->ceiling.count_color_c += 1;
	if (ft_check_virgule(map->map[i]) != 2)
		msg_err_f();
	ft_check_val_c(&map->map[i][j], map);
}
