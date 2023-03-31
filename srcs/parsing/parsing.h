/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 04:09:29 by tbouzalm          #+#    #+#             */
/*   Updated: 2023/03/29 21:19:05 by tbouzalm         ###   ########.fr       */
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

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	int		window_width;
	int		window_heigth;
}t_mlx;

typedef struct s_ray
{
	double	begin_x;
	double	begin_y;
	double	end_x;
	double	end_y;
	double	h_intrsct_x;
	double	h_intrsct_y;
	double	v_intrsct_x;
	double	v_intrsct_y;
	double	v_dist;
	double	h_dist;
	int		nbr_rays;
	double	angle_speed;
	double	angle;
}t_ray;

typedef struct s_parse
{
	char	*line;
	int		fd;
	char	**map_str;
}t_parse;

typedef struct s_wall
{
	int		start;
	int		end;
	double	height;
}t_wall;

typedef struct s_player
{
	double	x;
	double	y;
	char	view;
	double	field_of_view;
	int		move_horizontaly;
	int		move_verticaly;
	int		rotate;
	double	rotation_angle;
	double	move_speed;
	double	rotation_speed;
	int		mouse;
	int		mouse_rotate;
	int		sign;
}t_player;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		*addr_int;
	int		addr_int_size;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		size;
}t_img;

typedef struct s_game
{
	char		*n_texture_xpm;
	char		*s_texture_xpm;
	char		*w_texture_xpm;
	char		*e_texture_xpm;
	t_img		n_texture;
	t_img		s_texture;
	t_img		w_texture;
	t_img		e_texture;
	t_ray		ray;
	t_color		floor;
	t_ceiling	ceiling;
	t_mlx		mlx;
	t_player	player;
	t_img		img;
	t_wall		wall;
	t_parse		parse;
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
