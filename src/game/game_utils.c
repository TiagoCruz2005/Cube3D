#include "cube3d.h"

int	is_blocking_tile(t_game *game, double x, double y)
{
	int		map_x;
	int		map_y;
	char	tile;

	if (x < 0 || y < 0)
		return (TRUE);
	map_x = (int)x;
	map_y = (int)y;
	if (map_y >= game->map.height || map_x >= game->map.width)
		return (TRUE);
	if (!game->map.grid || !game->map.grid[map_y])
		return (TRUE);
	tile = game->map.grid[map_y][map_x];
	if (tile == '\0')
		return (TRUE);
	return (tile != '0');
}

int	can_move_to(t_game *game, double x, double y)
{
	if (is_blocking_tile(game, x + PLAYER_RADIUS, y))
		return (FALSE);
	if (is_blocking_tile(game, x - PLAYER_RADIUS, y))
		return (FALSE);
	if (is_blocking_tile(game, x, y + PLAYER_RADIUS))
		return (FALSE);
	if (is_blocking_tile(game, x, y - PLAYER_RADIUS))
		return (FALSE);
	if (is_blocking_tile(game, x + PLAYER_RADIUS, y + PLAYER_RADIUS))
		return (FALSE);
	if (is_blocking_tile(game, x - PLAYER_RADIUS, y + PLAYER_RADIUS))
		return (FALSE);
	if (is_blocking_tile(game, x + PLAYER_RADIUS, y - PLAYER_RADIUS))
		return (FALSE);
	if (is_blocking_tile(game, x - PLAYER_RADIUS, y - PLAYER_RADIUS))
		return (FALSE);
	return (TRUE);
}
