#include "cub3D.h"


void    fill_map(t_data *data, t_game *game)
{
    int i = 0;
    int j = 0;
    data->map_data = (int **)malloc(sizeof(int *) * game->nbr_lines_contenu);
    while(i < game->nbr_lines_contenu)
    {
        data->map_data[i] = (int *)malloc(sizeof(int) * game->nbr_colums);
        while (j < game->nbr_colums)
        {
            if (game->contenu[i][j] >= '0' && game->contenu[i][j] <= '9')
                data->map_data[i][j] = game->contenu[i][j] - '0';
            else
            {
                data->map_data[i][j] = game->contenu[i][j];
                data->view = game->contenu[i][j];
            }
            j++;
        }
        j = 0;
        i++;
    }
}

void check_fill_map(t_data *data, t_game *game)
{
    int i = 0;
    int j = 0;

    while(i < game->nbr_lines_contenu)
    {
        while (j < game->nbr_colums)
        {
            printf("%d\t",data->map_data[i][j]);
            j++;
        }
        printf("\n");
        j = 0;
        i++;
    }
}

void    get_player_position(t_data *data)
{
    int i;
    int j;

    i = 0;
    while (i < data->MAP_WIDTH)
    {
        j = 0;
        while (j < data->MAP_HEIGHT)
        {
            if (data->map_data[i][j] == 'N' || data->map_data[i][j] == 'W'
                || data->map_data[i][j] == 'S' || data->map_data[i][j] == 'E')
            {
                data->pos[X] = i;
                data->pos[Y] = j;
                data->map_data[i][j] = '0';
            }
            j++;
        }
        i++;
    }
}

void    get_player_direction(t_data *data)
{
    if(data->view == 'N')
    {
        data->dir[X] = -1;
        data->dir[Y] = 0;
        data->plane[X] = 0;
        data->plane[Y] = 0.66;
        data->rotSpeed *= -1;
    }
    else if (data->view == 'E')//
    {
        data->dir[X] = 0;
        data->dir[Y] = -1;
        data->plane[X] = 0.66;
        data->plane[Y] = 0;
    }
    else if (data->view == 'S')
    {
        data->dir[X] = 1;
        data->dir[Y] = 0;
        data->plane[X] = 0;
        data->plane[Y] = 0.66;
    }
    else if (data->view == 'W')
    {
        data->dir[X] = 0;
        data->dir[Y] = 1;
        data->plane[X] = -0.66;
        data->plane[Y] = 0;
    }
}
static void game_init(t_data *data, t_game *game)
{
    data->MAP_WIDTH = game->nbr_lines_contenu;
    data->MAP_HEIGHT = game->nbr_colums;
    data->rotSpeed = 0.08;
    data->moveSpeed = 0.9;
    fill_map(data, game);
    get_player_position(data);
    get_player_direction(data);
}

int	keypress(int keycode,t_data *data)
{
    double oldDir;
    double oldPlan;

	if (keycode == 53 && data)
		exit(0);
	if (keycode == 13)
	{
        if(!(data->map_data[(int)(data->pos[X] + data->dir[X] * data->moveSpeed)][(int)data->pos[Y]]))
            data->pos[X] += data->dir[X] * data->moveSpeed;
        if(!(data->map_data[(int)data->pos[X]][(int)(data->pos[Y] + data->dir[Y] * data->moveSpeed)]))
            data->pos[Y] += data->dir[Y] * data->moveSpeed;
    }
	if (keycode == 1)
	{
        if(!(data->map_data[(int)(data->pos[X] - data->dir[X] * data->moveSpeed)][(int)data->pos[Y]]))
            data->pos[X] -= data->dir[X] * data->moveSpeed;
        if(!(data->map_data[(int)data->pos[X]][(int)(data->pos[Y] - data->dir[Y] * data->moveSpeed)]))
            data->pos[Y] -= data->dir[Y] * data->moveSpeed;
    }
    if (keycode == 2)
    {
        if(!(data->map_data[(int)(data->pos[X] + data->plane[X] * data->moveSpeed)][(int)data->pos[Y]]))
            data->pos[X] += data->plane[X] * data->moveSpeed;
        if(!(data->map_data[(int)data->pos[X]][(int)(data->pos[Y] + data->plane[Y] * data->moveSpeed)]))
            data->pos[Y] += data->plane[Y] * data->moveSpeed;
    }
    if (keycode == 0)
    {
        if(!(data->map_data[(int)(data->pos[X] - data->plane[X] * data->moveSpeed)][(int)data->pos[Y]]))
            data->pos[X] -= data->plane[X] * data->moveSpeed;
        if(!(data->map_data[(int)data->pos[X]][(int)(data->pos[Y] - data->plane[Y] * data->moveSpeed)]))
            data->pos[Y] -= data->plane[Y] * data->moveSpeed;
    }
    if(keycode == 123)
    {
        oldDir = data->dir[X];
        data->dir[X] = data->dir[X] * cos(-(data->rotSpeed)) - data->dir[Y] * sin(-(data->rotSpeed));
        data->dir[Y] = oldDir * sin(-(data->rotSpeed)) + data->dir[Y] * cos(-(data->rotSpeed));
        oldPlan = data->plane[X];
        data->plane[X] = data->plane[X] * cos(-(data->rotSpeed)) - data->plane[Y] * sin(-(data->rotSpeed));
        data->plane[Y] = oldPlan * sin(-(data->rotSpeed)) + data->plane[Y] * cos(-(data->rotSpeed));
    }
    if(keycode == 124)
    {
        oldDir = data->dir[X];
        data->dir[X] = data->dir[X] * cos(data->rotSpeed) - data->dir[Y] * sin(data->rotSpeed);
        data->dir[Y] = oldDir * sin(data->rotSpeed) + data->dir[Y] * cos(data->rotSpeed);
        oldPlan = data->plane[X];
        data->plane[X] = data->plane[X] * cos(data->rotSpeed) - data->plane[Y] * sin(data->rotSpeed);
        data->plane[Y] = oldPlan * sin(data->rotSpeed) + data->plane[Y] * cos(data->rotSpeed);
    }
    mlx_clear_window(data->mlx_ptr, data->win_ptr);
    raycast(data);
	return (0);
}

void    load_texture(t_data *data)
{
    char *xpm = "textures/wall.xpm";
    data->texture = mlx_xpm_file_to_image(data->mlx_ptr, xpm, &data->tex_w, &data->tex_h);
    if(data->texture == NULL)
        return;
    data->img_color = (int *)mlx_get_data_addr(data->texture, &data->tex_bbp, &data->tex_size_line, &data->tex_endian);
}

int main(int argc, char **argv)
{
    t_data  data;
    t_game  game;

    if (argc != 2)
		puterr("enter the valid arguments!!\n");
	game = initialize_struct();
	check_extension(argv[1]);
	ft_read_map(&game, argv[1]);
	ft_check_texture(&game);
	remplire_contenu(&game);
	check_map_contenu(&game);
    game_init(&data, &game);
    printf("n_text = %s\n",game.n_texture_xpm);// exemple where is path texture
    data.mlx_ptr = mlx_init();
    load_texture(&data);
    data.win_ptr = mlx_new_window(data.mlx_ptr,  WIN_WIDTH,  WIN_HEIGHT,  "cub3d");
    data.img_ptr = mlx_new_image(data.mlx_ptr,  WIN_WIDTH,  WIN_HEIGHT);
    data.data_addr = mlx_get_data_addr(data.img_ptr, 
            &data.bits_per_pixel,  &data.size_line,  &data.endian);
    raycast(&data);
	mlx_hook(data.win_ptr, 2, 0, keypress, (void *)&data);
    mlx_loop(data.mlx_ptr);
}
