/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 02:37:58 by tbouzalm          #+#    #+#             */
/*   Updated: 2023/04/01 02:01:34 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	keypress(int keycode,t_data *data)
{
    double oldDir;
    double oldPlan;

	if (keycode == 53 && data)
		exit(0);
	if (keycode == 13)
	{
        if(!(data->map_data[(int)(data->pos[X] + data->dir[X] * data->moveSpeed)][(int)data->pos[Y]]))
            data->pos[X] += data->dir[X] * data->moveSpeed;
        if(!(data->map_data[(int)data->pos[X]][(int)(data->pos[Y] + data->dir[Y] * data->moveSpeed)]))
            data->pos[Y] += data->dir[Y] * data->moveSpeed;
    }
	if (keycode == 1)
	{
        if(!(data->map_data[(int)(data->pos[X] - data->dir[X] * data->moveSpeed)][(int)data->pos[Y]]))
            data->pos[X] -= data->dir[X] * data->moveSpeed;
        if(!(data->map_data[(int)data->pos[X]][(int)(data->pos[Y] - data->dir[Y] * data->moveSpeed)]))
            data->pos[Y] -= data->dir[Y] * data->moveSpeed;
    }
    if (keycode == 2)
    {
        if(!(data->map_data[(int)(data->pos[X] + data->plane[X] * data->moveSpeed)][(int)data->pos[Y]]))
            data->pos[X] += data->plane[X] * data->moveSpeed;
        if(!(data->map_data[(int)data->pos[X]][(int)(data->pos[Y] + data->plane[Y] * data->moveSpeed)]))
            data->pos[Y] += data->plane[Y] * data->moveSpeed;
    }
    if (keycode == 0)
    {
        if(!(data->map_data[(int)(data->pos[X] - data->plane[X] * data->moveSpeed)][(int)data->pos[Y]]))
            data->pos[X] -= data->plane[X] * data->moveSpeed;
        if(!(data->map_data[(int)data->pos[X]][(int)(data->pos[Y] - data->plane[Y] * data->moveSpeed)]))
            data->pos[Y] -= data->plane[Y] * data->moveSpeed;
    }
    if(keycode == 123)
    {
        oldDir = data->dir[X];
        data->dir[X] = data->dir[X] * cos(-(data->rotSpeed)) - data->dir[Y] * sin(-(data->rotSpeed));
        data->dir[Y] = oldDir * sin(-(data->rotSpeed)) + data->dir[Y] * cos(-(data->rotSpeed));
        oldPlan = data->plane[X];
        data->plane[X] = data->plane[X] * cos(-(data->rotSpeed)) - data->plane[Y] * sin(-(data->rotSpeed));
        data->plane[Y] = oldPlan * sin(-(data->rotSpeed)) + data->plane[Y] * cos(-(data->rotSpeed));
    }
    if(keycode == 124)
    {
        oldDir = data->dir[X];
        data->dir[X] = data->dir[X] * cos(data->rotSpeed) - data->dir[Y] * sin(data->rotSpeed);
        data->dir[Y] = oldDir * sin(data->rotSpeed) + data->dir[Y] * cos(data->rotSpeed);
        oldPlan = data->plane[X];
        data->plane[X] = data->plane[X] * cos(data->rotSpeed) - data->plane[Y] * sin(data->rotSpeed);
        data->plane[Y] = oldPlan * sin(data->rotSpeed) + data->plane[Y] * cos(data->rotSpeed);
    }
    mlx_clear_window(data->mlx_ptr, data->win_ptr);
    raycast(data);
	return (0);
}

int main(int argc, char **argv)
{
    t_data  data;
    t_game  game;

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
    data.win_ptr = mlx_new_window(data.mlx_ptr,  WIN_WIDTH,  WIN_HEIGHT,  "cub3D");
    data.img_ptr = mlx_new_image(data.mlx_ptr,  WIN_WIDTH,  WIN_HEIGHT);
    data.data_addr = mlx_get_data_addr(data.img_ptr, 
            &data.bits_per_pixel,  &data.size_line,  &data.endian);
    data.game = game;
    raycast(&data);
	mlx_hook(data.win_ptr, 2, 0, keypress, (void *)&data);
    // mlx_loop_hook(data.mlx_ptr, render, &data);
    mlx_loop(data.mlx_ptr);
}
