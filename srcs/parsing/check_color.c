/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 05:14:38 by tbouzalm          #+#    #+#             */
/*   Updated: 2023/04/03 10:01:12 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_if_is_floor_or_celing(t_game *map, int i, int j, int index)
{
	if (map->map[i][j + index] == 'F' && map->map[i][j + index + 1] == 32)
	{
		if (map->count_f == 1)
			puterr("Duplicate color F");
		norm_check_line_f(i, index, map);
		map->count_f++;
		return (0);
	}
	if (map->map[i][j + index] == 'C' && map->map[i][j + index + 1] == 32)
	{
		if (map->count_c == 1)
			puterr("Duplicate color C");
		norm_check_line_c(i, index, map);
		map->count_c++;
		return (0);
	}
	return (1);
}

void	check_path_existe(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		msg_err_file();
	close(fd);
}

int	ft_check_virgule(char *str)
{	
	int	i;
	int	v;

	i = 0;
	v = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ',')
			v += 1;
		i++;
	}
	return (v);
}

void	ft_check_val_f(char *str, t_game *map)
{
	int		i;
	char	**tmp;

	i = 0;
	map->floor.f = ft_split(str, ' ');
	while (map->floor.f[i])
		i++;
	if (i > 2 || i == 1)
		msg_err_color();
	tmp = map->floor.f;
	map->floor.f = ft_split(map->floor.f[1], ',');
	ft_free(tmp);
	if (map->floor.f[0] == NULL)
		msg_err_color();
	if (map->floor.f[1] == NULL)
		msg_err_color();
	if (map->floor.f[2] == NULL)
		msg_err_color();
	map->floor.red = ft_atoi(map->floor.f[0]);
	map->floor.green = ft_atoi(map->floor.f[1]);
	map->floor.blue = ft_atoi(map->floor.f[2]);
	if (!(map->floor.red <= 256 && map->floor.red >= 0) || \
	!(map->floor.green <= 256 && map->floor.green >= 0) \
	|| !(map->floor.blue <= 256 && map->floor.blue >= 0))
		msg_err_val_color();
}

void	ft_check_val_c(char *str, t_game *map)
{
	int		i;
	char	**tmp;

	i = 0;
	map->ceiling.c = ft_split(str, ' ');
	while (map->ceiling.c[i])
		i++;
	if (i > 2 || i == 1)
		msg_err_color();
	tmp = map->ceiling.c;
	map->ceiling.c = ft_split(map->ceiling.c[1], ',');
	ft_free(tmp);
	if (map->ceiling.c[0] == NULL)
		msg_err_color();
	if (map->ceiling.c[1] == NULL)
		msg_err_color();
	if (map->ceiling.c[2] == NULL)
		msg_err_color();
	map->ceiling.red = ft_atoi(map->ceiling.c[0]);
	map->ceiling.green = ft_atoi(map->ceiling.c[1]);
	map->ceiling.blue = ft_atoi(map->ceiling.c[2]);
	if (!(map->ceiling.red <= 256 && map->ceiling.red >= 0) || \
	!(map->ceiling.green <= 256 && map->ceiling.green >= 0) \
	|| !(map->ceiling.blue <= 256 && map->ceiling.blue >= 0))
		msg_err_val_color();
}
