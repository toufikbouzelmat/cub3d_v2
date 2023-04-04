/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 22:26:38 by yelousse          #+#    #+#             */
/*   Updated: 2023/04/04 22:32:43 by yelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	mouse_move(int x, int y, t_data *data)
{
	if (x >= WIN_WIDTH || x <= 0 || y >= WIN_HEIGHT || y <= 0)
		return (0);
	if (x > data->old_mouse)
		keypress(124, data);
	else if (x < data->old_mouse)
		keypress(123, data);
	if (x == WIN_WIDTH || x == 0)
		x = WIN_WIDTH / 2;
	data->old_mouse = x;
	return (0);
}
