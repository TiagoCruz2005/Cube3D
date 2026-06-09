/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_lines_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 19:35:19 by tide-pau          #+#    #+#             */
/*   Updated: 2026/06/09 19:35:20 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	is_blank_line(char *line)
{
	if (!line)
		return (1);
	if (line[0] == '\n' && line[1] == '\0')
		return (1);
	if (line[0] == '\0')
		return (1);
	return (0);
}

void	free_line_close_fd(char *line, int *fd)
{
	if (line)
		free(line);
	if (*fd != -1)
	{
		close(*fd);
		*fd = -1;
	}
}
