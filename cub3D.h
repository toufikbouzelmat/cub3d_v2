/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 20:32:31 by tbouzalm          #+#    #+#             */
/*   Updated: 2023/03/29 20:36:38 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <mlx.h>
# include "utils/utils.h"
# include "srcs/parsing/parsing.h"
# include "includes/initial.h"
# include <math.h>

# define ESC_KEY 53
# define W_KEY 13
# define S_KEY 1
# define A_KEY 0
# define D_KEY 2
# define LEFT_ARROW_KEY 123
# define RIGHT_ARROW_KEY 124
# define GRID_SIZE 64
# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 720
# define WALL_STRIP_WIDTH 1

t_game	initialize_struct(void);

void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
void	ft_window(t_mlx *mlx, t_game game);
int	    render(t_game *game);

int	    key_release(int keycode, t_game *game);
int	    key_press(int keycode, t_game *game);
int	    ft_exit(t_game *game);

t_game	*draw_square(t_game *game, double i, double j, int color);
t_game	*render_minimap_background(t_game *game, int x, int y);
t_game	*render_minimap(t_game *game);
t_game  get_info_player(t_game game);

#endif