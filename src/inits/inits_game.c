#include "../../includes/cube3d.h"

int	inits(t_data *data, t_game *game)
{
	init_data(data);
	init_struct(game);
	return (TRUE);
}

void	init_struct(t_game *game)
{
	ft_memset(game, 0, sizeof(*game));
	game->mlx = NULL;
	game->win = NULL;
	game->screen.img_ptr = NULL;
	game->screen.addr = NULL;
	game->map.grid = NULL;
	game->tex.north.img.img_ptr = NULL;
	game->tex.north.img.addr = NULL;
	game->tex.south.img.img_ptr = NULL;
	game->tex.south.img.addr = NULL;
	game->tex.east.img.img_ptr = NULL;
	game->tex.east.img.addr = NULL;
	game->tex.west.img.img_ptr = NULL;
	game->tex.west.img.addr = NULL;
	ft_memset(&game->keys, 0, sizeof(game->keys));
}
