/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_allocs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 19:35:42 by tide-pau          #+#    #+#             */
/*   Updated: 2026/06/09 19:35:43 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	if_allocated_free(t_data *data)
{
	if (data->file)
		free(data->file);
	if (data->map)
		ft_free_vector(&data->map);
	if (data->map_copy)
		ft_free_vector(&data->map_copy);
	if_textures_alloc_free(data);
}

void	if_textures_alloc_free(t_data *data)
{
	if (data->textures.no)
		free(data->textures.no);
	if (data->textures.so)
		free(data->textures.so);
	if (data->textures.we)
		free(data->textures.we);
	if (data->textures.ea)
		free(data->textures.ea);
}

void	if_game_mlx_image_alloc_free(t_game *game)
{
	if (game->mlx)
	{
		if (game->screen.img_ptr)
			mlx_destroy_image(game->mlx, game->screen.img_ptr);
		if (game->tex.east.img.img_ptr)
			mlx_destroy_image(game->mlx, game->tex.east.img.img_ptr);
		if (game->tex.north.img.img_ptr)
			mlx_destroy_image(game->mlx, game->tex.north.img.img_ptr);
		if (game->tex.south.img.img_ptr)
			mlx_destroy_image(game->mlx, game->tex.south.img.img_ptr);
		if (game->tex.west.img.img_ptr)
			mlx_destroy_image(game->mlx, game->tex.west.img.img_ptr);
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game->map.grid)
		ft_free_vector(&game->map.grid);
}
