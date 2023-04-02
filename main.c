/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 02:37:58 by tbouzalm          #+#    #+#             */
/*   Updated: 2023/04/02 09:39:29 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
	mlx_hook(data.win_ptr, 6, 0, mouse_move, &data);
	mlx_loop(data.mlx_ptr);
}
