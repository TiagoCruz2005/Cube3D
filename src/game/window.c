/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 19:31:28 by thde-sou          #+#    #+#             */
/*   Updated: 2026/06/12 18:49:24 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_texture	*get_texture(t_game *game)
{
	t_tex	*tex;

	tex = &game->tex;
	if (game->ray.side == 0)
	{
		if (game->ray.ray_dir_x > 0)
			return (&tex->east);
		else
			return (&tex->west);
	}
	else
	{
		if (game->ray.ray_dir_y > 0)
			return (&tex->south);
		else
			return (&tex->north);
	}
}

int	open_window(t_game *game)
{
	game->win = mlx_new_window(game->mlx, 1920, 960, "T_Cube3D");
	if (!game->win)
	{
		put_error("failure to create window\n");
		return (FALSE);
	}
	return (TRUE);
}

void	render_frame(t_game *game)
{
	int	x;

	x = 0;
	ft_memset(game->screen.addr, 0, game->screen.line_len * HEIGHT);
	while (x < WIDTH)
	{
		cast_ray(game, x);
		draw_column(game, x);
		x++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->screen.img_ptr, 0, 0);
}

void	cast_ray(t_game *game, int x)
{
	init_ray(game, x);
	execute_dda(game);
	calc_wall_projection(game);
}
