/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intialise_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:18:37 by tbouzalm          #+#    #+#             */
/*   Updated: 2023/03/31 03:04:40 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_game	initialize_struct(void)
{
	t_game	game;

	ft_bzero(&game, sizeof(game));
	return (game);
}
