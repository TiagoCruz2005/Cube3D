#include "cube3d.h"

static void	load_width_height(t_game *game)
{
	int		i;
	int		j;
	char	**map;
	int		width;

	j = 0;
	width = 0;
	map = game->map.grid;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
			i++;
		if (i > width)
			width = i;
		j++;
	}
	game->map.height = j;
	game->map.width = width;
}

void	load_color(t_data *data, t_game *game)
{
	t_color	*floor;
	t_color	*ceiling;

	floor = &game->floor;
	ceiling = &game->ceiling;
	game->floor.r = data->textures.fc[0];
	game->floor.g = data->textures.fc[1];
	game->floor.b = data->textures.fc[2];
	game->ceiling.r = data->textures.cc[0];
	game->ceiling.g = data->textures.cc[1];
	game->ceiling.b = data->textures.cc[2];
	floor->value = (floor->r << 16) | (floor->g << 8) | floor->b;
	ceiling->value = (ceiling->r << 16) | (ceiling->g << 8) | ceiling->b;
}

int	load_map(t_data *data, t_game *game)
{
	game->map.grid = ft_vetor_dup(data->map);
	if (!game->map.grid)
	{
		put_error("failure to load the map");
		return (FALSE);
	}
	load_width_height(game);
	return (TRUE);
}

int	load_screen(t_game *game)
{
	game->screen.img_ptr = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->screen.img_ptr)
	{
		put_error("failure to open screen");
		return (FALSE);
	}
	game->screen.addr = mlx_get_data_addr(game->screen.img_ptr,
			&game->screen.bpp, &game->screen.line_len, &game->screen.endian);
	if (!game->screen.addr)
	{
		put_error("failure to load addr image");
		return (FALSE);
	}
	return (TRUE);
}

int	load_components(t_data *data, t_game *game)
{
	if (!open_file(data, data->file))
		return (FALSE);
	load_color(data, game);
	if (!load_map(data, game))
	{
		put_error("failure to load map\n");
		return (FALSE);
	}
	if (!load_textures(*data, game))
	{
		put_error("failure to load textures\n");
		return (FALSE);
	}
	if (!load_screen(game))
		return (FALSE);
	return (TRUE);
}
