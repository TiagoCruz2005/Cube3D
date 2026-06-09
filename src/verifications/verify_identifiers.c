/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_identifiers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 19:35:48 by tide-pau          #+#    #+#             */
/*   Updated: 2026/06/09 19:35:49 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	verify_rgb(t_data *data)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (data->textures.fc[i] >= 0 && data->textures.fc[i] <= 255)
			;
		else
			return (0);
		if (data->textures.cc[i] >= 0 && data->textures.cc[i] <= 255)
			;
		else
			return (0);
		i++;
	}
	return (1);
}

int	verify_duplicate(t_ptex *tex)
{
	if (ft_strcmp(tex->no, tex->so) == 0)
		return (0);
	if (ft_strcmp(tex->no, tex->we) == 0)
		return (0);
	if (ft_strcmp(tex->no, tex->ea) == 0)
		return (0);
	if (ft_strcmp(tex->so, tex->we) == 0)
		return (0);
	if (ft_strcmp(tex->so, tex->ea) == 0)
		return (0);
	if (ft_strcmp(tex->we, tex->ea) == 0)
		return (0);
	return (1);
}

int	verify_image_extension(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len == 0)
		return (FALSE);
	else if (len < 4)
		return (FALSE);
	else if (ft_strcmp(str + len - 4, ".xpm") != 0)
		return (FALSE);
	return (TRUE);
}

int	verify_images(t_data *data)
{
	if (!verify_image_extension(data->textures.no))
		return (FALSE);
	if (!verify_image_extension(data->textures.so))
		return (FALSE);
	if (!verify_image_extension(data->textures.we))
		return (FALSE);
	if (!verify_image_extension(data->textures.ea))
		return (FALSE);
	return (TRUE);
}
