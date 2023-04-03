/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 09:10:55 by yelousse          #+#    #+#             */
/*   Updated: 2023/04/03 03:34:09 by yelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	up_down(t_data *data, int i)
{
	if (!(data->map_data[(int)(data->pos[X]
				+ (data->dir[X] * data->move_speed) * i)][(int)data->pos[Y]]))
		data->pos[X] += (data->dir[X] * data->move_speed) * i;
	if (!(data->map_data[(int)data->pos[X]][(int)(data->pos[Y]
			+ (data->dir[Y] * data->move_speed) * i)]))
		data->pos[Y] += (data->dir[Y] * data->move_speed) * i;
}

void	left_right(t_data *data, int i)
{
	if (!(data->map_data[(int)(data->pos[X]
				+ (data->plane[X] * data->move_speed) * i)][(int)data->pos[Y]]))
		data->pos[X] += (data->plane[X] * data->move_speed) * i;
	if (!(data->map_data[(int)data->pos[X]]
			[(int)(data->pos[Y] + (data->plane[Y] * data->move_speed) * i)]))
		data->pos[Y] += (data->plane[Y] * data->move_speed) * i;
}

void	rotation(t_data *data, int i)
{
	double	old_dir;
	double	old_plan;

	old_plan = data->plane[X];
	old_dir = data->dir[X];
	data->dir[X] = data->dir[X] * cos(data->rot_speed * i)
		- data->dir[Y] * sin(data->rot_speed * i);
	data->dir[Y] = old_dir * sin(data->rot_speed * i)
		+ data->dir[Y] * cos(data->rot_speed * i);
	data->plane[X] = data->plane[X] * cos(data->rot_speed * i)
		- data->plane[Y] * sin(data->rot_speed * i);
	data->plane[Y] = old_plan * sin(data->rot_speed * i)
		+ data->plane[Y] * cos(data->rot_speed * i);
}

int	keypress(int keycode, t_data *data)
{
	if (keycode == 53 && data)
		exit(0);
	if (keycode == 13)
		up_down(data, 1);
	if (keycode == 1)
		up_down(data, -1);
	if (keycode == 2)
		left_right(data, 1);
	if (keycode == 0)
		left_right(data, -1);
	if (keycode == 123)
		rotation(data, -1);
	if (keycode == 124)
		rotation(data, 1);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	raycast(data);
	return (0);
}

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
