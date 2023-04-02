/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 04:43:26 by tbouzalm          #+#    #+#             */
/*   Updated: 2023/04/02 05:19:49 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	check_extension_xpm(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (str[len - 1] != 'm' || str[len - 2] != 'p' \
	|| str[len - 3] != 'x' || str[len - 4] != '.')
	{
		printf("Erreur Extention Path\n");
		exit(1);
	}
}

int	check_extension(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (str[len - 1] != 'b' || str[len - 2] != 'u' || str[len - 3] != 'c'\
	|| str[len - 4] != '.')
	{
		write(1, "erreur extension\n", 18);
		exit(1);
	}
	return (0);
}

int	ft_check_texture(t_game *map)
{
	map->last_line_before_m = get_map(map);
	if (ft_check_line_c(map) == 1 || ft_check_line_f(map) == 1)
		msg_err_color();
	if (ft_check_texture_now(map) == 1)
		msg_err_texture();
	return (0);
}
