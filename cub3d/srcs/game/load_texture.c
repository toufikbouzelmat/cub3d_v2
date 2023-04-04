/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 02:02:06 by tbouzalm          #+#    #+#             */
/*   Updated: 2023/04/03 08:19:15 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	load_texture_n(t_data *data, t_game *game)
{
	data->texture_no = mlx_xpm_file_to_image(data->mlx_ptr, \
	game->n_texture_xpm, &data->tex_w_no, &data->tex_h_no);
	if (data->texture_no == NULL)
		puterr("mlx_xpm_file_to_image failed1");
	data->img_color_no = (int *)mlx_get_data_addr(data->texture_no, \
	&data->tex_bbp_no, &data->tex_size_line_no, &data->tex_endian_no);
	if (!data->img_color_no)
		puterr("mlx_get_data_addr failed1");
}

void	load_texture_s(t_data *data, t_game *game)
{
	data->texture_so = mlx_xpm_file_to_image(data->mlx_ptr, \
	game->s_texture_xpm, &data->tex_w_so, &data->tex_h_so);
	if (data->texture_so == NULL)
		puterr("mlx_xpm_file_to_image failed2");
	data->img_color_so = (int *)mlx_get_data_addr(data->texture_so, \
	&data->tex_bbp_so, &data->tex_size_line_so, &data->tex_endian_so);
	if (!data->img_color_so)
		puterr("mlx_get_data_addr failed2");
}

void	load_texture_w(t_data *data, t_game *game)
{
	data->texture_we = mlx_xpm_file_to_image(data->mlx_ptr, \
	game->w_texture_xpm, &data->tex_w_we, &data->tex_h_we);
	if (data->texture_we == NULL)
		puterr("mlx_xpm_file_to_image failed3");
	data->img_color_we = (int *)mlx_get_data_addr(data->texture_we, \
	&data->tex_bbp_we, &data->tex_size_line_we, &data->tex_endian_we);
	if (!data->img_color_we)
		puterr("mlx_get_data_addr failed3");
}

void	load_texture_e(t_data *data, t_game *game)
{
	data->texture_ea = mlx_xpm_file_to_image(data->mlx_ptr, \
	game->e_texture_xpm, &data->tex_w_ea, &data->tex_h_ea);
	if (data->texture_ea == NULL)
		puterr("mlx_xpm_file_to_image failed4");
	data->img_color_ea = (int *)mlx_get_data_addr(data->texture_ea, \
	&data->tex_bbp_ea, &data->tex_size_line_ea, &data->tex_endian_ea);
	if (!data->img_color_ea)
		puterr("mlx_get_data_addr failed4");
}

void	load_texture(t_data *data, t_game *game)
{
	load_texture_n(data, game);
	load_texture_s(data, game);
	load_texture_w(data, game);
	load_texture_e(data, game);
}
