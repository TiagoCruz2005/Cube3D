/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_image_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 19:35:15 by tide-pau          #+#    #+#             */
/*   Updated: 2026/06/09 19:35:16 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	image_remove_end_spaces(t_data *data)
{
	remove_end_spaces(data->textures.no);
	remove_end_spaces(data->textures.so);
	remove_end_spaces(data->textures.we);
	remove_end_spaces(data->textures.ea);
}
