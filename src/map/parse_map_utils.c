#include "cube3d.h"

int	ft_strlen_n(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

void	alloc_map_line(t_data *data, int i, int y)
{
	data->map[y] = malloc(sizeof(char) * (i + 1));
	if (!data->map[y])
	{
		ft_free_failed_vector(&data->map, y);
		exit_error(data, "Malloc Fail\n", 0);
	}
}

int	find_longest_line(t_data *data)
{
	char	*line;
	int		fd;
	int		len;
	int		get_len;

	cub_open(data, &fd, data->file);
	line = skip_to_map_start(fd);
	len = 0;
	get_len = 0;
	while (line)
	{
		if (is_blank_line(line))
		{
			free_line_close_fd(line, &fd);
			exit_error(data, "Emptu line inside or after map\n", 0);
		}
		get_len = ft_strlen_n(line);
		if (len < get_len)
			len = get_len;
		free(line);
		line = ft_gnl(fd);
	}
	close(fd);
	return (len);
}

int	copy_map_line(t_data *data, char *line, int y, int bigest_len)
{
	int	i;

	alloc_map_line(data, bigest_len, y);
	i = 0;
	while (line[i] && line[i] != '\n' && i < bigest_len)
	{
		data->map[y][i] = line[i];
		i++;
	}
	while (i < bigest_len)
		data->map[y][i++] = ' ';
	data->map[y][i] = '\0';
	return (1);
}

void	island_handler(t_data *data, int fd)
{
	int	i;
	int	y;

	y = 0;
	while (data->map_copy[y])
	{
		i = 0;
		while (data->map_copy[y][i])
		{
			if (data->map_copy[y][i] == '0')
			{
				flood_fill(data, y, i, fd);
				i = 0;
			}
			i++;
		}
		y++;
	}
}
