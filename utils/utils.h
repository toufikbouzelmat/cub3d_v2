/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 20:15:54 by tbouzalm          #+#    #+#             */
/*   Updated: 2023/04/01 07:28:40 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

int		check_tabs(char *str);
int		create_trgb(int t, int r, int g, int b);
int		ft_atoi(const char *str);
void	ft_bzero(void *s, int n);
void	*ft_calloc(int count, int size);
char	**ft_free(char **tab);
int		ft_isdigit(int c);
void	*ft_memset(void *b, int c, int len);
void	ft_putstr_fd(char *s, int fd);
double	dist_between_two_points(double a_x, double a_y, double b_x, double b_y);
void	puterr(char *str);
char	**ft_realloc(char **str, int size);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
int		ft_search(char *s, int c);
char	*ft_strdup(char *s1);
int		ft_strlcpy(char *dst, char *src, int dstsize);
int		ft_strlen(char *s);
int		ft_strlen_const(const char *str);
int		ft_strncmp(const char *s1, const char *s2, int n);
char	*ft_substr(char const *s, int start, int len);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*get_next_line(int fd);
double	degree_to_radian(int degree);

#endif