/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 01:45:31 by tbouzalm          #+#    #+#             */
/*   Updated: 2023/04/01 05:32:55 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/initial.h"

void	set_info_n(t_data *data)
{
	data->dir[X] = -1;
	data->dir[Y] = 0;
	data->plane[X] = 0;
	data->plane[Y] = 0.66;
	data->rot_speed *= -1;
}

void	set_info_s(t_data *data)
{
	data->dir[X] = 1;
	data->dir[Y] = 0;
	data->plane[X] = 0;
	data->plane[Y] = 0.66;
}

void	set_info_e(t_data *data)
{
	data->dir[X] = 0;
	data->dir[Y] = -1;
	data->plane[X] = 0.66;
	data->plane[Y] = 0;
}

void	set_info_w(t_data *data)
{
	data->dir[X] = 0;
	data->dir[Y] = 1;
	data->plane[X] = -0.66;
	data->plane[Y] = 0;
}
