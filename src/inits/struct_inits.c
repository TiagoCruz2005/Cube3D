/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_inits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thde-sou <thde-sou@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 19:31:52 by thde-sou          #+#    #+#             */
/*   Updated: 2026/06/09 19:31:53 by thde-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	init_textures(t_ptex *text)
{
	ft_memset(text, 0, sizeof(*text));
	text->no = NULL;
	text->so = NULL;
	text->we = NULL;
	text->ea = NULL;
	text->cc_n = 0;
	text->fc_n = 0;
	text->fc[0] = 0;
	text->fc[1] = 0;
	text->fc[2] = 0;
	text->cc[0] = 0;
	text->cc[1] = 0;
	text->cc[2] = 0;
}

void	init_data(t_data *data)
{
	ft_memset(data, 0, sizeof(*data));
	data->file = NULL;
	data->map = NULL;
	data->map_copy = NULL;
	data->map_max_col = 0;
	data->map_max_rows = 0;
	data->num_lines = 0;
	data->fd_load = 0;
	init_textures(&data->textures);
	data->flag_texture[0] = "NO";
	data->flag_texture[1] = "SO";
	data->flag_texture[2] = "WE";
	data->flag_texture[3] = "EA";
	data->flag_texture[4] = NULL;
}
