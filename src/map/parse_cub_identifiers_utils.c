/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub_identifiers_utils.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 19:35:05 by tide-pau          #+#    #+#             */
/*   Updated: 2026/06/09 19:35:06 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	is_empty_line(char *line)
{
	if (!line)
		return (1);
	while (*line)
	{
		if (*line != ' ' && *line != '\t' && *line != '\n')
			return (0);
		line++;
	}
	return (1);
}

int	if_not_line_identifier_parse(t_data *data, char *line, char *orig, int fd)
{
	if (!line_identifier_parse(data, line))
	{
		free(orig);
		close(fd);
		return (0);
	}
	return (1);
}

char	*ft_strdup_n(char *line)
{
	char	*new;
	int		i;

	new = malloc(sizeof(char) * (ft_strlen_n(line) + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		new[i] = line[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

void	free_if_line(t_data *data, char *line, int y)
{
	if (line)
		free(line);
	data->map[y] = NULL;
}

void	remove_end_spaces(char *str)
{
	int	len;

	if (!str)
		return ;
	len = ft_strlen(str) - 1;
	while (len >= 0 && (str[len] == ' ' || str[len] == '\t'))
	{
		str[len] = '\0';
		len--;
	}
}
