/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 02:42:06 by tbouzalm          #+#    #+#             */
/*   Updated: 2023/03/31 03:01:10 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/initial.h"

void	fill_map(t_data *data, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	data->map_data = (int **)malloc(sizeof(int *) * game->nbr_lines_contenu);
	while (i < game->nbr_lines_contenu)
	{
		data->map_data[i] = (int *)malloc(sizeof(int) * game->nbr_colums);
		j = 0;
		while (j < game->nbr_colums)
		{
			if (game->contenu[i][j] >= '0' && game->contenu[i][j] <= '9')
				data->map_data[i][j] = game->contenu[i][j] - '0';
			else
			{
				data->map_data[i][j] = game->contenu[i][j];
				data->view = game->contenu[i][j];
			}
			j++;
		}
		i++;
	}
}

void	get_player_position(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->MAP_WIDTH)
	{
		j = 0;
		while (j < data->MAP_HEIGHT)
		{
			if (data->map_data[i][j] == 'N' || data->map_data[i][j] == 'W'
				|| data->map_data[i][j] == 'S' || data->map_data[i][j] == 'E')
			{
				data->pos[X] = i;
				data->pos[Y] = j;
				data->map_data[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}

void	get_player_direction(t_data *data)
{
	if (data->view == 'N')
	{
		data->dir[X] = -1;
		data->dir[Y] = 0;
		data->plane[X] = 0;
		data->plane[Y] = 0.66;
		data->rotSpeed *= -1;
	}
	else if (data->view == 'E')
	{
		data->dir[X] = 0;
		data->dir[Y] = -1;
		data->plane[X] = 0.66;
		data->plane[Y] = 0;
	}
	else if (data->view == 'S')
	{
		data->dir[X] = 1;
		data->dir[Y] = 0;
		data->plane[X] = 0;
		data->plane[Y] = 0.66;
	}
	else if (data->view == 'W')
	{
		data->dir[X] = 0;
		data->dir[Y] = 1;
		data->plane[X] = -0.66;
		data->plane[Y] = 0;
	}
}

void	game_init(t_data *data, t_game *game)
{
	data->MAP_WIDTH = game->nbr_lines_contenu;
	data->MAP_HEIGHT = game->nbr_colums;
	data->rotSpeed = 0.08;
	data->moveSpeed = 0.9;
	fill_map(data, game);
	get_player_position(data);
	get_player_direction(data);
}
