/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 19:35:31 by tide-pau          #+#    #+#             */
/*   Updated: 2026/06/12 18:35:28 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	is_identifier_line(char *line)
{
	if (!line)
		return (0);
	if (!ft_strncmp(line, "NO ", 3))
		return (1);
	if (!ft_strncmp(line, "SO ", 3))
		return (1);
	if (!ft_strncmp(line, "WE ", 3))
		return (1);
	if (!ft_strncmp(line, "EA ", 3))
		return (1);
	if (!ft_strncmp(line, "F ", 2))
		return (1);
	if (!ft_strncmp(line, "C ", 2))
		return (1);
	return (0);
}

void	map_count_lines(t_data *data, int fd)
{
	char	*line;
	int		count;

	count = 0;
	line = ft_gnl(fd);
	while (line && is_empty_line(line))
	{
		free(line);
		line = ft_gnl(fd);
	}
	while (line)
	{
		if (is_blank_line(line))
		{
			free_line_close_fd(line, fd);
			exit_error(data, "Empty line inside or after map\n", 0);
		}
		count++;
		free(line);
		line = ft_gnl(fd);
	}
	data->num_lines = count;
}

char	*skip_to_map_start(int fd)
{
	char	*tmp;
	char	*line;

	line = ft_gnl(fd);
	while (line)
	{
		tmp = trim_lead(line);
		if (is_empty_line(tmp))
		{
			free(line);
			line = ft_gnl(fd);
			continue ;
		}
		if (is_identifier_line(tmp))
		{
			free(line);
			line = ft_gnl(fd);
			continue ;
		}
		return (line);
	}
	return (NULL);
}

int	create_parse_map(t_data *data)
{
	char	*line;
	int		y;
	int		fd;

	cub_open(data, &fd, data->file);
	data->map_max_col = find_longest_line(data);
	data->map = malloc(sizeof(char *) * (data->num_lines + 1));
	if (!data->map)
		return (close(fd), FALSE);
	ft_memset(data->map, 0, sizeof(char *) * (data->num_lines + 1));
	line = skip_to_map_start(fd);
	y = 0;
	while (line)
	{
		if (is_blank_line(line))
		{
			free_line_close_fd(line, &fd);
			exit_error(data, "Empty line inside or after map\n", 0);
		}
		copy_map_line(data, line, y++, data->map_max_col);
		free(line);
		line = ft_gnl(fd);
	}
	free_if_line(data, line, y);
	return (close(fd), TRUE);
}

void	parse_map(t_data *data, int fd)
{
	if (create_parse_map(data) == FALSE)
		exit_error(data, "Failed to allocate map\n", FALSE);
	if (!verify_map_cluster(data) || !verify_line_borders(data)
		|| !verify_top_bottom_lines(data))
	{
		close(fd);
		exit_error(data, "Map is invalid\n", 0);
	}
	if (!verify_map_size(data))
	{
		close(fd);
		exit_error(data, "Map is too big\n", 0);
	}
	data->map_max_rows = ft_size_vetor(data->map);
	locate_player(data, fd);
	data->map_copy = ft_vetor_dup(data->map);
	if (!data->map_copy)
	{
		close(fd);
		exit_error(data, "Malloc Fail\n", 0);
	}
	flood_fill(data, data->game->player.pos_y, data->game->player.pos_x, fd);
	island_handler(data, fd);
	ft_free_vector(&data->map_copy);
}
