/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   degree_to_radian.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 20:12:28 by tbouzalm          #+#    #+#             */
/*   Updated: 2023/03/23 20:17:53 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

double	degree_to_radian(int degree)
{
	return (degree * M_PI / 180);
}
