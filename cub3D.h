/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 20:32:31 by tbouzalm          #+#    #+#             */
/*   Updated: 2023/03/31 05:07:41 by tbouzalm         ###   ########.fr       */
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

int	    render(t_game *game);

int	    key_release(int keycode, t_game *game);
int	    key_press(int keycode, t_game *game);
int	    ft_exit(t_game *game);

t_data	*render_minimap(t_data *data);
t_data	*render_minimap_background(t_data *data, int x, int y);
t_data	*draw_square(t_data *data, double i, double j, int color);

#endif