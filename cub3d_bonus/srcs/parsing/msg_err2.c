/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_err2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 08:55:34 by tbouzalm          #+#    #+#             */
/*   Updated: 2023/03/10 15:21:58 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	msg_err_color(void)
{
	printf("Error\nC or F manque");
	exit(1);
}

void	msg_err_map(void)
{
	printf("Error\n(invalid) Map\n");
	exit(1);
}

void	msg_err_player(void)
{
	printf("Error\nJust N or W or W or E || empty player\n");
	exit(1);
}

void	protection_mall(void *str)
{
	if (!str)
		exit(1);
}

void	msg_err_file(void)
{
	printf("Error\nno file existe!\n");
	exit(1);
}
