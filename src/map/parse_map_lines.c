#include "cube3d.h"

int	is_valid_map_tile(char c)
{
	if (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E'
		|| ft_isspace(c))
		return (1);
	else
		return (0);
}

int	verify_map_cluster(t_data *d)
{
	int	i;
	int	y;

	y = 0;
	while (d->map[y])
	{
		i = 0;
		while (ft_isspace(d->map[y][i]))
			i++;
		while (is_valid_map_tile(d->map[y][i]))
			i++;
		while (ft_isspace(d->map[y][i]))
			i++;
		if (d->map[y][i] != '\0' && !ft_isspace(d->map[y][i]))
			return (0);
		y++;
	}
	return (1);
}

int	verify_line_borders(t_data *d)
{
	int	i;
	int	y;

	y = 0;
	while (d->map[y])
	{
		i = 0;
		while (ft_isspace(d->map[y][i]))
			i++;
		if (d->map[y][i] == '\0')
		{
			y++;
			continue ;
		}
		if (d->map[y][i] != '1')
			return (0);
		i = ft_strlen(d->map[y]) - 1;
		while (ft_isspace(d->map[y][i]))
			i--;
		if (d->map[y][i] != '1')
			return (0);
		y++;
	}
	return (1);
}

int	verify_top_bottom_lines(t_data *d)
{
	int	i;
	int	y;

	if (!d->map[0] || !d->map)
		return (0);
	i = 0;
	while (d->map[0] && d->map[0][i])
	{
		if (d->map[0][i] != '1' && !ft_isspace(d->map[0][i]))
			return (0);
		i++;
	}
	y = d->num_lines - 1;
	i = 0;
	while (d->map[y] && d->map[y][i])
	{
		if (d->map[y][i] != '1' && !ft_isspace(d->map[y][i]))
			return (0);
		i++;
	}
	return (1);
}

void	flood_fill(t_data *data, int row, int col, int fd)
{
	char	c;

	if (row < 0 || row >= data->map_max_rows || col < 0
		|| col >= data->map_max_col)
	{
		if (fd != -1)
			close(fd);
		exit_error(data, "The map is not closed\n", 0);
	}
	c = data->map_copy[row][col];
	if (c == ' ')
	{
		if (fd != -1)
			close(fd);
		exit_error(data, "The map is not closed\n", 0);
	}
	if (c == '1' || c == 'F')
		return ;
	if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		data->map_copy[row][col] = 'F';
	flood_fill(data, row + 1, col, fd);
	flood_fill(data, row - 1, col, fd);
	flood_fill(data, row, col + 1, fd);
	flood_fill(data, row, col - 1, fd);
}
