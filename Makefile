# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 20:16:05 by tbouzalm          #+#    #+#              #
#    Updated: 2023/03/31 05:08:07 by tbouzalm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cub3D

CFLAGS =  -Wextra -Wall -Werror

HEADERS =  cub3D.h utils/utils.h parsing/parsing.h includes/initial.h

SRCS = main.c \
srcs/parsing/check_color.c \
srcs/parsing/initialisation.c \
srcs/parsing/check_contenu_map.c \
srcs/parsing/intialise_struct.c \
srcs/parsing/check_map.c \
srcs/parsing/check_n_and_zero.c \
srcs/parsing/get_next_line.c \
srcs/parsing/get_next_line_utils.c \
srcs/parsing/map_contenu.c \
srcs/parsing/msg_err.c \
srcs/parsing/msg_err2.c \
srcs/parsing/msg_norm.c \
srcs/parsing/parse.c \
srcs/parsing/texture_condition.c \
srcs/parsing/to_map.c \
srcs/parsing/utils_check_color.c \
srcs/parsing/utils_map_contenu.c \
utils/check_white_space.c \
utils/create_trgb.c \
utils/degree_to_radian.c \
utils/distance_between_two_points.c \
utils/ft_atoi.c \
utils/ft_bzero.c \
utils/ft_calloc.c \
utils/ft_free.c \
utils/ft_isdigit.c \
utils/ft_memset.c \
utils/ft_putstr_fd.c \
utils/ft_realloc.c \
utils/ft_split.c \
utils/ft_strchr.c \
utils/ft_strdup.c \
utils/ft_strlcpy.c \
utils/ft_strlen.c \
utils/ft_strncmp.c \
utils/ft_substr.c \
utils/puterr.c \
srcs/game/draw.c \
srcs/game/raycast.c \
srcs/game/render_mini_map.c \
# game/render_mini_map.c \
# game/player_init.c \


OBJS = $(SRCS:.c=.o)

all : $(NAME)

	
$(NAME) : $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS)  -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c $(HEADERS)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@ 

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	
re: fclean all

.PHONY: all, clean, fclean, re