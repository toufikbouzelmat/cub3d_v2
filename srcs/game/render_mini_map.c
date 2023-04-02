/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mini_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 04:56:39 by tbouzalm          #+#    #+#             */
/*   Updated: 2023/04/02 06:37:10 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

t_data	*my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->data_addr + (y * data->size_line + x * \
	(data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	return (data);
}

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
			data = my_mlx_pixel_put(data, x, y, color);
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
				|| i >= data->map_height || j >= data->map_width)
				data = draw_square(data, i - y + 5, j - x + 5, 0x808080);
			else if (data->game.contenu[i][j] == '0')
				data = draw_square(data, i - y + 5, j - x + 5, 0x000000);
			else if (data->game.contenu[i][j] == '1')
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

	x = (int)(data->pos[X]);
	y = (int)(data->pos[Y]);
	data = render_minimap_background(data, y, x);
	data = draw_square(data, 5, 5, 0xff0000);
	return (data);
}
