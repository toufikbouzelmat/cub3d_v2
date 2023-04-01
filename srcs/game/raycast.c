/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 06:37:29 by tbouzalm          #+#    #+#             */
/*   Updated: 2023/04/01 06:56:14 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	perform_dda(t_data *data, t_raycast *rc)
{
	int	hit;

	compute_delta_dist(data, rc);
	compute_side_dist(data, rc);
	hit = 0;
	while (hit == 0)
	{
		if (rc->side_dist[X] < rc->side_dist[Y])
		{
			rc->side_dist[X] += rc->delta_dist[X];
			rc->map[X] += rc->step[X];
			rc->side = X;
		}
		else
		{
			rc->side_dist[Y] += rc->delta_dist[Y];
			rc->map[Y] += rc->step[Y];
			rc->side = Y;
		}
		hit = data->map_data[rc->map[X]][rc->map[Y]] > 0;
	}
}

void	get_texture(t_data *data, t_raycast *rc)
{
	if (rc->side == 1 && rc->ray_dir[Y] > 0)
		data->color = *(int *)(data->img_color_no + \
		(data->tex_y * data->tex_w_no + data->tex_x));
	else if (rc->side == 1 && rc->ray_dir[Y] < 0)
		data->color = *(int *)(data->img_color_so + \
		(data->tex_y * data->tex_w_so + data->tex_x));
	else if (rc->side == 0 && rc->ray_dir[X] > 0)
		data->color = *(int *)(data->img_color_ea + \
		(data->tex_y * data->tex_w_ea + data->tex_x));
	else if (rc->side == 0 && rc->ray_dir[X] < 0)
		data->color = *(int *)(data->img_color_we + \
		(data->tex_y * data->tex_w_we + data->tex_x));
	if (rc->side == 1)
		data->color = (data->color >> 1) & 0x7F7F7F;
}

void	draw_wall(t_data *data, t_raycast *rc, int x)
{
	rc->line_height = (int)(WIN_HEIGHT / rc->perp_wall_dist);
	rc->draw_start = (-rc->line_height / 2) + (WIN_HEIGHT / 2);
	if (rc->draw_start < 0)
		rc->draw_start = 0;
	rc->draw_end = rc->draw_start + rc->line_height;
	if (rc->draw_end > WIN_HEIGHT)
		rc->draw_end = (rc->line_height / 2) + (WIN_HEIGHT / 2);
	if (rc->draw_end >= WIN_HEIGHT)
		rc->draw_end = WIN_HEIGHT - 1;
	if (rc->side == 0)
		data->wall_x = data->pos[Y] + rc->perp_wall_dist * rc->ray_dir[Y];
	else
		data->wall_x = data->pos[X] + rc->perp_wall_dist * rc->ray_dir[X];
	data->wall_x -= floor(data->wall_x);
	data->tex_x = (int)(data->wall_x * (double)(data->tex_w_no));
	if (rc->side == 0 && rc->ray_dir[X] > 0)
		data->tex_x = data->tex_w_no - data->tex_x - 1;
	if (rc->side == 1 && rc->ray_dir[Y] < 0)
		data->tex_x = data->tex_w_no - data->tex_x - 1;
	data->step = 1.0 * data->tex_h_no / rc->line_height;
	data->tex_pos = (rc->draw_start - WIN_HEIGHT / 2 \
	+ rc->line_height / 2) * data->step;
	data->y = rc->draw_start;
	while (data->y < rc->draw_end)
	{
		data->tex_y = (int)data->tex_pos & (data->tex_h_no - 1);
		data->tex_pos += data->step;
		get_texture(data, rc);
		img_pixel_put(data, x, data->y, data->color);
		data->y++;
	}
	draw_vertical_line(data, rc, x);
}

void	raycast(t_data *data)
{
	int			x;
	double		camera_x;
	t_raycast	rc;

	x = -1;
	while (++x < WIN_WIDTH)
	{
		camera_x = 2.0 * x / WIN_WIDTH - 1;
		rc.ray_dir[X] = data->dir[X] + data->plane[X] * camera_x;
		rc.ray_dir[Y] = data->dir[Y] + data->plane[Y] * camera_x;
		perform_dda(data, &rc);
		if (rc.side == X)
			rc.perp_wall_dist = rc.side_dist[X] - rc.delta_dist[X];
		else
			rc.perp_wall_dist = rc.side_dist[Y] - rc.delta_dist[Y];
		draw_wall(data, &rc, x);
	}
	data = render_minimap(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}
