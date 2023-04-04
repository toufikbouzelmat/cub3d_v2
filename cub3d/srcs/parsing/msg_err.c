/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_err.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 04:44:49 by tbouzalm          #+#    #+#             */
/*   Updated: 2023/03/10 15:38:21 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	msg_err_arg(void)
{
	printf("Error\njust name and map!!\n");
	exit(1);
}

void	msg_err_f(void)
{
	printf("Error\nvirgule depasse 2!!\n");
	exit(1);
}

void	msg_err_tab(void)
{
	printf("Error\ntab!!\n");
	exit(1);
}

void	msg_err_texture(void)
{
	printf("Error\nTexture manque!\n");
	exit(1);
}

void	msg_err_val_color(void)
{
	printf("Error\ndepasse limite color in C\n");
	exit(1);
}
