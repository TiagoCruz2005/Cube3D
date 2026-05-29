#include "../../includes/cube3d.h"

int	game_loop(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	update_player(game);
	render_frame(game);
	return (0);
}

int	run_game(t_data *data, t_game *game)
{
	if (!open_window(game))
		return (FALSE);
	if (!init_player(data, game))
		return (FALSE);
	mlx_hook(game->win, 2, 1L << 0, (int (*)())key_press, game);
	mlx_hook(game->win, 3, 1L << 1, (int (*)())key_realease, game);
	mlx_hook(game->win, 17, 0, (int (*)())close_game, game);
	mlx_loop_hook(game->mlx, (int (*)())game_loop, game);
	mlx_loop(game->mlx);
	return (TRUE);
}
