/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thde-sou <thde-sou@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 19:31:12 by thde-sou          #+#    #+#             */
/*   Updated: 2026/06/09 19:31:13 by thde-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static int	define_pos_player_ns(t_data *data, t_game *game)
{
	if (data->p_looking_dir == 'N')
	{
		game->player.dir_x = 0;
		game->player.dir_y = -1;
		game->player.plane_x = 0.66;
		game->player.plane_y = 0;
		return (TRUE);
	}
	else if (data->p_looking_dir == 'S')
	{
		game->player.dir_x = 0;
		game->player.dir_y = 1;
		game->player.plane_x = -0.66;
		game->player.plane_y = 0;
		return (TRUE);
	}
	game->player.pitch = 0;
	return (FALSE);
}

static int	define_pos_player_ew(t_data *data, t_game *game)
{
	if (data->p_looking_dir == 'E')
	{
		game->player.dir_x = 1;
		game->player.dir_y = 0;
		game->player.plane_x = 0;
		game->player.plane_y = 0.66;
		return (TRUE);
	}
	else if (data->p_looking_dir == 'W')
	{
		game->player.dir_x = -1;
		game->player.dir_y = 0;
		game->player.plane_x = 0;
		game->player.plane_y = -0.66;
		return (TRUE);
	}
	return (FALSE);
}

int	init_player(t_data *data, t_game *game)
{
	if (define_pos_player_ns(data, game))
		return (TRUE);
	else if (define_pos_player_ew(data, game))
		return (TRUE);
	put_error("failure to position of player");
	return (FALSE);
}
