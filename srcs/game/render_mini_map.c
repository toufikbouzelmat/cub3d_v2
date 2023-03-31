/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mini_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 04:56:39 by tbouzalm          #+#    #+#             */
/*   Updated: 2023/03/31 05:12:17 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

t_data	*draw_square(t_data *data, double i, double j, int color)
{
	int	x;
	int	y;

	y = i * 10;
	while (y < (i * 10) + 10)
	{
		x = j * 10;
		while (x < (j * 10) + 10)
		{
			// my_mlx_pixel_put(&data->img_ptr, x, y, color);
			img_pixel_put(data, x, y, color);
			x++;
		}
		y++;
	}
	return (data);
}

t_data	*render_minimap_background(t_data *data, int x, int y)
{
	int	i;
	int	j;

	i = y - 5;
	while (i < y + 5)
	{
		j = x - 5;
		while (j < x + 5)
		{
			if (i < 0 || j < 0
				|| i >= data->MAP_WIDTH || j >= data->MAP_HEIGHT)
				data = draw_square(data, i - y + 5, j - x + 5, 0x808080);
			else if (data->map_data[i][j] == '0')
				data = draw_square(data, i - y + 5, j - x + 5, 0x000000);
			else if (data->map_data[i][j] == '1')
					data = draw_square(data, i - y + 5, j - x + 5, 0xffffff);
			else
				data = draw_square(data, i - y + 5, j - x + 5, 0x808080);
			j++;
		}
		i++;
	}
	return (data);
}

t_data	*render_minimap(t_data *data)
{
	int	x;
	int	y;

	x = (int)(data->pos[X] / GRID_SIZE);
	y = (int)(data->pos[Y] / GRID_SIZE);
	data = render_minimap_background(data, x, y);
	data = draw_square(data, 5, 5, 0xff0000);
	return (data);
}
