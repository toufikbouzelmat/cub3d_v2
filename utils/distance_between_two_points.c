/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_between_two_points.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 20:12:44 by tbouzalm          #+#    #+#             */
/*   Updated: 2023/03/23 20:17:45 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

double	dist_between_two_points(double a_x, double a_y, double b_x, double b_y)
{
	return (sqrt(pow(b_x - a_x, 2) + pow(b_y - a_y, 2)));
}
