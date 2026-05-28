#include "../../includes/cube3d.h"

void	execute_verifications(t_data *data)
{
	if (!verify_rgb(data))
		exit_error(data, "Error: invalid color\n", 0);
	if (!verify_duplicate(&data->textures))
		exit_error(data, "Error: duplicate found\n", 0);
}

/*int	verify_size(t_game *game)
{
	int	width;
	int	height;

	width = game->tex.north.width;
	height = game->tex.north.height;
	if (width <= 0 || height <= 0)
		return (put_error("wrong size image\n"), FALSE);
	if (game->tex.east.width != width || game->tex.east.height != height)
	{
		put_error("wrong size image\n");
		return (FALSE);
	}
	if (game->tex.south.width != width || game->tex.south.height != height)
	{
		put_error("wrong size image\n");
		return (FALSE);
	}
	if (game->tex.west.width != width || game->tex.west.height != height)
	{
		put_error("wrong size image\n");
		return (FALSE);
	}
	game->texture_width = width;
	game->texture_height = height;
	return (TRUE);
}
*/