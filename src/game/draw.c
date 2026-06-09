/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thde-sou <thde-sou@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 19:30:46 by thde-sou          #+#    #+#             */
/*   Updated: 2026/06/09 19:30:47 by thde-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	draw_wall_calcs(t_game *game, t_texture *texture, double sest[4])
{
	sest[0] = (int)game->ray.draw_start;
	sest[1] = (int)game->ray.draw_end;
	if (sest[0] < 0)
		sest[0] = 0;
	if (sest[1] >= HEIGHT)
		sest[1] = HEIGHT - 1;
	sest[2] = (double)texture->height / game->ray.line_height;
	sest[3] = (sest[0] - game->ray.draw_start) * sest[2];
}

void	draw_ceilling(t_game *game, int x, int *y)
{
	int	end;

	end = game->ray.draw_start;
	if (end > HEIGHT)
		end = HEIGHT;
	while (*y < end)
	{
		put_pixel(&game->screen, x, *y, game->ceiling.value);
		(*y)++;
	}
}

void	draw_wall(t_game *game, int x, int *y)
{
	int			color;
	int			tex_y;
	t_texture	*texture;
	double		sest[4];

	texture = get_texture(game);
	draw_wall_calcs(game, texture, sest);
	while (*y <= sest[1])
	{
		tex_y = (int)sest[3];
		sest[3] += sest[2];
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= texture->height)
			tex_y = texture->height - 1;
		color = get_texture_pixel(texture, game->ray.tex_x, tex_y);
		put_pixel(&game->screen, x, *y, color);
		(*y)++;
	}
}

void	draw_floor(t_game *game, int x, int *y)
{
	while (*y < HEIGHT)
	{
		put_pixel(&game->screen, x, *y, game->floor.value);
		(*y)++;
	}
}

void	draw_column(t_game *game, int x)
{
	int	y;

	y = 0;
	draw_ceilling(game, x, &y);
	draw_wall(game, x, &y);
	draw_floor(game, x, &y);
}
