/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 06:49:45 by tbouzalm          #+#    #+#             */
/*   Updated: 2023/04/01 06:52:41 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	compute_delta_dist(t_data *data, t_raycast *rc)
{
	rc->map[X] = data->pos[X];
	rc->map[Y] = data->pos[Y];
	rc->delta_dist[X] = 1e30;
	if (rc->ray_dir[X] != 0.0)
		rc->delta_dist[X] = fabs(1.0 / rc->ray_dir[X]);
	rc->delta_dist[Y] = 1e30;
	if (rc->ray_dir[Y] != 0.0)
		rc->delta_dist[Y] = fabs(1.0 / rc->ray_dir[Y]);
}

void	compute_side_dist(t_data *data, t_raycast *rc)
{
	if (rc->ray_dir[X] < 0)
	{
		rc->step[X] = -1;
		rc->side_dist[X] = (data->pos[X] - rc->map[X]) * rc->delta_dist[X];
	}
	else
	{
		rc->step[X] = 1;
		rc->side_dist[X] = (rc->map[X] + 1 - data->pos[X]) * rc->delta_dist[X];
	}
	if (rc->ray_dir[Y] < 0)
	{
		rc->step[Y] = -1;
		rc->side_dist[Y] = (data->pos[Y] - rc->map[Y]) * rc->delta_dist[Y];
	}
	else
	{
		rc->step[Y] = 1;
		rc->side_dist[Y] = (rc->map[Y] + 1 - data->pos[Y]) * rc->delta_dist[Y];
	}
}
