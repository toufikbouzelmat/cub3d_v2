/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 20:32:26 by tbouzalm          #+#    #+#             */
/*   Updated: 2023/04/02 02:58:26 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	img_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->data_addr
		+ (y * data->size_line + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_vertical_line(t_data *data, t_raycast *rc, int x)
{
	int	y;

	y = -1;
	while (++y < rc->draw_start)
		img_pixel_put(data, x, y, SKY);
	while (y < rc->draw_end)
		y++;
	while (++y < WIN_HEIGHT)
		img_pixel_put(data, x, y, GRASS);
}
