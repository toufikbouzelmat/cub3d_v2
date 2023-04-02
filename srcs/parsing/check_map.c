/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 01:09:16 by tbouzalm          #+#    #+#             */
/*   Updated: 2023/04/02 04:14:01 by tbouzalm         ###   ########.fr       */
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

// char *skip_spaces(char* string) {
//     int index = 0;
    
// 	while (string[index] == ' ') {
//         index++;
//     }
//     return string + index;
// }

int	or_other(int i, int j, t_game *map)
{
	// int	caractere;
	
	// caractere = 0;
	// printf("after = [%s]\n",map->map[i]);
	// printf("after = [%c]\n",map->map[i][0]);
	// j = 0;
	// while (map->map[i][j] != '\0')
	// {
	// 	if (is_lower(map->map[i][j]) == 1 || is_upper(map->map[i][j]) == 1 )
	// 		caractere += 1;
	// 	if (caractere >= 2)
	// 	{
	// 		printf("Error\nNo String here!!");
	// 		exit(1);
	// 	}
	// }
	if (map->map[i][j] == '\n')
		return (0);
	int index = 0;
	while (map->map[i][index] == ' ')
	{
		index++;
		if (map->map[i][index] == '\0')
		{
			return (0);
		}	
	}
	// printf("la = [%c]\n",map->map[i][j + index]);
	// while (map->map[i][j + index] != '\0')
	// {
		if (map->map[i][j + index] == 'F' || map->map[i][j + index] == 'C')
		{
			if (map->map[i][j + index + 1] == 32)
				return 0;
			else
				return (1);  
			// printf("i = %d, j = %d\n",i,j);
			// printf("heree = %c\n",map->map[i][j]);
			// printf("[%s]\n",map->map[i]);
		}
		
		// if (map->map[i][index] == ' ')
		// 	j++;
	// 	j += 2;
	// }
	return (1);
}

int	ft_check_texture_now(t_game *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->map[++i])
	{
		j = 0;
		if (i == map->last_line_before_m)
			break ;
		while ((map->map[i][j] != '\0') && (map->map[i][j] != '\t'))
		{
			if (texture_no(i, j, map) == 1)
				break ;
			else if (texture_so(i, j, map) == 1)
				break ;
			else if (texture_wo(i, j, map) == 1)
				break ;
			else if (texture_ea(i, j, map) == 1)
				break ;
			else
			{
				if (or_other(i, j, map) == 1)
					puterr("string or caractere");
				break;	
			}
			j++;
		}
	}
	if (map->count != 4)
		msg_err_texture();
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
