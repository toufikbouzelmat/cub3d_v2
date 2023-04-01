/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 02:37:58 by tbouzalm          #+#    #+#             */
/*   Updated: 2023/04/01 07:05:09 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	keypress(int keycode, t_data *data)
{
	double	old_dir;
	double	old_plan;

	if (keycode == 53 && data)
		exit(0);
	if (keycode == 13)
	{
		if (!(data->map_data[(int)(data->pos[X] + data->dir[X] * data->move_speed)][(int)data->pos[Y]]))
    		data->pos[X] += data->dir[X] * data->move_speed;
		if (!(data->map_data[(int)data->pos[X]][(int)(data->pos[Y] + data->dir[Y] * data->move_speed)]))
			data->pos[Y] += data->dir[Y] * data->move_speed;
	}
	if (keycode == 1)
	{
		if (!(data->map_data[(int)(data->pos[X] - data->dir[X] * data->move_speed)][(int)data->pos[Y]]))
			data->pos[X] -= data->dir[X] * data->move_speed;
		if (!(data->map_data[(int)data->pos[X]][(int)(data->pos[Y] - data->dir[Y] * data->move_speed)]))
			data->pos[Y] -= data->dir[Y] * data->move_speed;
	}
	if (keycode == 2)
	{
		if (!(data->map_data[(int)(data->pos[X] + data->plane[X] * data->move_speed)][(int)data->pos[Y]]))
			data->pos[X] += data->plane[X] * data->move_speed;
		if (!(data->map_data[(int)data->pos[X]][(int)(data->pos[Y] + data->plane[Y] * data->move_speed)]))
			data->pos[Y] += data->plane[Y] * data->move_speed;
	}
	if (keycode == 0)
	{
		if (!(data->map_data[(int)(data->pos[X] - data->plane[X] * data->move_speed)][(int)data->pos[Y]]))
			data->pos[X] -= data->plane[X] * data->move_speed;
		if (!(data->map_data[(int)data->pos[X]][(int)(data->pos[Y] - data->plane[Y] * data->move_speed)]))
			data->pos[Y] -= data->plane[Y] * data->move_speed;
	}
	if (keycode == 123)
	{
		old_dir = data->dir[X];
		data->dir[X] = data->dir[X] * cos(-(data->rot_speed)) - data->dir[Y] * sin(-(data->rot_speed));
		data->dir[Y] = old_dir * sin(-(data->rot_speed)) + data->dir[Y] * cos(-(data->rot_speed));
		old_plan = data->plane[X];
		data->plane[X] = data->plane[X] * cos(-(data->rot_speed)) - data->plane[Y] * sin(-(data->rot_speed));
		data->plane[Y] = old_plan * sin(-(data->rot_speed)) + data->plane[Y] * cos(-(data->rot_speed));
	}
	if (keycode == 124)
	{
		old_dir = data->dir[X];
		data->dir[X] = data->dir[X] * cos(data->rot_speed) - data->dir[Y] * sin(data->rot_speed);
		data->dir[Y] = old_dir * sin(data->rot_speed) + data->dir[Y] * cos(data->rot_speed);
		old_plan = data->plane[X];
		data->plane[X] = data->plane[X] * cos(data->rot_speed) - data->plane[Y] * sin(data->rot_speed);
		data->plane[Y] = old_plan * sin(data->rot_speed) + data->plane[Y] * cos(data->rot_speed);
	}
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	raycast(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_game	game;

	if (argc != 2)
		puterr("enter the valid arguments!!\n");
	game = initialize_struct();
	check_extension(argv[1]);
	ft_read_map(&game, argv[1]);
	ft_check_texture(&game);
	remplire_contenu(&game);
	check_map_contenu(&game);
	game_init(&data, &game);
	data.mlx_ptr = mlx_init();
	load_texture(&data, &game);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	data.img_ptr = mlx_new_image(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	data.data_addr = mlx_get_data_addr(data.img_ptr,
			&data.bits_per_pixel, &data.size_line, &data.endian);
	data.game = game;
	raycast(&data);
	mlx_hook(data.win_ptr, 2, 0, keypress, (void *)&data);
	mlx_loop(data.mlx_ptr);
}
