/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 04:09:29 by tbouzalm          #+#    #+#             */
/*   Updated: 2023/03/31 03:04:25 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>
# include "../../utils/utils.h"

typedef struct s_color
{
	char	**f;
	int		red;
	int		green;
	int		blue;
	int		count_color_f;
	int		trgb;
}t_color;

typedef struct s_celing
{
	char	**c;
	int		red;
	int		green;
	int		blue;
	int		count_color_c;
	int		trgb;
}t_ceiling;

typedef struct s_game
{
	char		*n_texture_xpm;
	char		*s_texture_xpm;
	char		*w_texture_xpm;
	char		*e_texture_xpm;
	t_color		floor;
	t_ceiling	ceiling;
	int			nbr_colums;
	int			nbr_lines;
	int			nbr_lines_contenu;
	char		**map;
	char		**contenu;
	int			first_line_mur;
	int			p;
	int			count;
}t_game;

char		*ft_strjoin(char *s1, char *s2);
int			ft_strlen(char *str);
char		*read_buff_size(int fd, char *lines);
char		*one_line(char *lines);
char		*lines_rest(char *file_line);
char		*get_next_line(int fd);

int			ft_atoi(const	char *str);

void		msg_err_arg(void);
void		msg_err_f(void);
void		msg_err_tab(void);
void		msg_err_texture(void);
void		msg_err_color(void);
void		msg_err_map(void);
void		msg_err_player(void);
void		msg_err_file(void);
void		msg_err_empty(void);
void		msg_err_val_color(void);
void		protection_mall(void *str);

int			ft_read_map(t_game *map, char *av);
int			ft_check_texture(t_game *map);

int			check_extension(char *str);
void		check_extension_xpm(char *str);

int			ft_check_virgule(char *str);
void		norm_check_line_f(int i, int j, t_game *map);
void		ft_check_val_f(char *str, t_game *map);
int			ft_check_line_f(t_game *map);
void		norm_check_line_c(int i, int j, t_game *map);
void		ft_check_val_c(char *str, t_game *map);
int			ft_check_line_c(t_game *map);

int			ft_check_texture_now(t_game *map);
int			check_if_is_first_mur(int i, t_game *map);

int			get_map(t_game *map);

int			nbr_de_line_map(t_game *map);
void		nbr_de_line_contenu(t_game *map);
int			ft_get_max_line(t_game *map);
void		verife_map_avant_allocer(t_game *map);
int			ft_player_or_mur(char c, t_game	*map);
void		norm_function_remplir_contenu(int id, int i, t_game *map, int j);
int			remplire_contenu(t_game *map);

void		last_line_mur(t_game *map);
void		first_and_last_of_line(t_game *map);
void		ft_zero(int i, int j, t_game *map);
int			verifie_player_and_zero(t_game *map);
int			check_map_contenu(t_game *map);
t_game		initialize_struct(void);
int			texture_no(int i, int j, t_game *map);
int			texture_so(int i, int j, t_game *map);
int			texture_wo(int i, int j, t_game *map);
int			texture_ea(int i, int j, t_game *map);

#endif
