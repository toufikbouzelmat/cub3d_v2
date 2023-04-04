/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_white_space.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 20:12:09 by tbouzalm          #+#    #+#             */
/*   Updated: 2023/03/23 20:18:15 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	check_tabs(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\t')
		{
			write(2, "remove tabs\n", ft_strlen("remove tabs\n"));
			exit(1);
		}
		i++;
	}
	return (0);
}
