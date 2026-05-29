#include "cube3d.h"

int	key_press(int keycode, void *game)
{
	if (keycode == KEY_W)
		((t_game *)game)->keys.w = TRUE;
	if (keycode == KEY_S)
		((t_game *)game)->keys.s = TRUE;
	if (keycode == KEY_A)
		((t_game *)game)->keys.a = TRUE;
	if (keycode == KEY_D)
		((t_game *)game)->keys.d = TRUE;
	if (keycode == KEY_LEFT)
		((t_game *)game)->keys.left = TRUE;
	if (keycode == KEY_RIGHT)
		((t_game *)game)->keys.right = TRUE;
	if (keycode == KEY_UP)
		((t_game *)game)->keys.up = TRUE;
	if (keycode == KEY_DOWN)
		((t_game *)game)->keys.down = TRUE;
	if (keycode == ESC)
		close_game(game);
	if (keycode == KEY_SHIFT)
		((t_game *)game)->player.running = TRUE;
	return (0);
}

int	key_realease(int keycode, void *game)
{
	if (keycode == KEY_W)
		((t_game *)game)->keys.w = FALSE;
	if (keycode == KEY_S)
		((t_game *)game)->keys.s = FALSE;
	if (keycode == KEY_A)
		((t_game *)game)->keys.a = FALSE;
	if (keycode == KEY_D)
		((t_game *)game)->keys.d = FALSE;
	if (keycode == KEY_LEFT)
		((t_game *)game)->keys.left = FALSE;
	if (keycode == KEY_RIGHT)
		((t_game *)game)->keys.right = FALSE;
	if (keycode == KEY_UP)
		((t_game *)game)->keys.up = FALSE;
	if (keycode == KEY_DOWN)
		((t_game *)game)->keys.down = FALSE;
	if (keycode == KEY_SHIFT)
		((t_game *)game)->player.running = FALSE;
	return (0);
}

void	update_player(t_game *game)
{
	if (game->keys.w)
		move_forward(game);
	if (game->keys.s)
		move_backward(game);
	if (game->keys.a)
		move_left(game);
	if (game->keys.d)
		move_right(game);
	if (game->keys.right)
		rotate_right(game);
	if (game->keys.left)
		rotate_left(game);
	if (game->keys.up)
		rotate_up_down(game, 1);
	if (game->keys.down)
		rotate_up_down(game, -1);
}
