#include "cube3d.h"

static void	locate_player_helper(t_data *d, int y, char *line, int *p_found)
{
	int		i;
	char	c;

	i = 0;
	while (line[i])
	{
		c = line[i];
		if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		{
			if (*p_found == TRUE)
				exit_error(d, "Map contains more than 1 player\n", 0);
			else if (*p_found == FALSE)
			{
				d->game->player.pos_x = i + 0.5;
				d->game->player.pos_y = y + 0.5;
				d->p_looking_dir = c;
				d->map[y][i] = '0';
				*p_found = TRUE;
			}
		}
		i++;
	}
}

void	locate_player(t_data *d, int fd)
{
	int	y;
	int	player_found;

	player_found = FALSE;
	y = 0;
	while (d->map[y])
	{
		locate_player_helper(d, y, d->map[y], &player_found);
		y++;
	}
	if (player_found == FALSE)
	{
		close(fd);
		exit_error(d, "Player not found\n", 0);
	}
}
