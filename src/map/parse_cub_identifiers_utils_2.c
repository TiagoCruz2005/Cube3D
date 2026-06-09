/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub_identifiers_utils_2.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 19:35:00 by tide-pau          #+#    #+#             */
/*   Updated: 2026/06/09 19:35:01 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	parse_rgb_value(char *line, int *i, int *out)
{
	int	value;

	value = 0;
	if (!ft_isdigit(line[*i]))
		return (FALSE);
	while (ft_isdigit(line[*i]))
	{
		value = value * 10 + (line[*i] - '0');
		if (value > 255)
			return (FALSE);
		(*i)++;
	}
	*out = value;
	return (TRUE);
}
