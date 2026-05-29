#include "cube3d.h"

int	close_game(void *param)
{
	t_game *game;

	game = (t_game *)param;
	mlx_loop_end(game->mlx);
	mlx_destroy_image(game->mlx, game->screen.img_ptr);
	mlx_destroy_image(game->mlx, game->tex.east.img.img_ptr);
	mlx_destroy_image(game->mlx, game->tex.north.img.img_ptr);
	mlx_destroy_image(game->mlx, game->tex.south.img.img_ptr);
	mlx_destroy_image(game->mlx, game->tex.west.img.img_ptr);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	ft_free_vector(&game->map.grid);
	exit(EXIT_SUCCESS);
}
