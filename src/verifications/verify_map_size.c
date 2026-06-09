/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 19:35:51 by tide-pau          #+#    #+#             */
/*   Updated: 2026/06/09 19:35:52 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	verify_map_size(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
		i++;
	if (data->map_max_col > 255 || i > 255)
		return (FALSE);
	return (TRUE);
}
