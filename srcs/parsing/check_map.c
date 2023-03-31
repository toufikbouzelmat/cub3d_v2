/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 01:09:16 by tbouzalm          #+#    #+#             */
/*   Updated: 2023/03/29 21:20:23 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	ft_count_lines(char *av)
{
	char	*str;
	int		i;
	int		fd;

	i = 0;
	fd = open(av, O_RDWR);
	if (fd == -1)
		msg_err_file();
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		free(str);
		i++;
	}
	close (fd);
	return (i);
}

int	ft_read_map(t_game *map, char *av)
{
	int		fd;
	char	*line;

	map->nbr_lines = ft_count_lines(av);
	if (!map->nbr_lines || map->nbr_lines <= 2)
	{
		write(1, "map invalid\n", 13);
		exit(1);
	}
	map->map = malloc(sizeof(char *) *(map->nbr_lines + 1));
	map->nbr_lines = 0;
	fd = open(av, O_RDWR);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map->map[map->nbr_lines] = line;
		map->nbr_lines++;
	}
	map->map[map->nbr_lines] = NULL;
	close(fd);
	return (map->nbr_lines);
}

int	ft_check_texture_now(t_game *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->map[++i])
	{
		j = 0;
		while ((map->map[i][j] != '\0') && (map->map[i][j] != '\t'))
		{
			if (map->map[i][j] == 32)
				j++;
			if (texture_no(i, j, map) == 1)
				break ;
			if (texture_so(i, j, map) == 1)
				break ;
			if (texture_wo(i, j, map) == 1)
				break ;
			if (texture_ea(i, j, map) == 1)
				break ;
			j++;
		}
	}
	if (map->count != 4)
		msg_err_texture();
	return (0);
}

int	ft_check_texture(t_game *map)
{
	if (ft_check_line_c(map) == 1 || ft_check_line_f(map) == 1)
		msg_err_color();
	if (ft_check_texture_now(map) == 1)
		msg_err_texture();
	return (0);
}
