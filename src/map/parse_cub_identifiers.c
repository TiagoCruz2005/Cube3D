#include "cube3d.h"

char	*trim_lead(char *str)
{
	if (!str)
		return (NULL);
	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	return (str);
}

int	parse_floor_color(t_data *data, char *line)
{
	int	i;
	int	k;

	if (!line || !*line)
		return (0);
	i = 0;
	k = 0;
	while (line[i] && k < 3)
	{
		if (!parse_rgb_value(line, &i, &data->textures.fc[k]))
			return (0);
		k++;
		if (k < 3 && line[i] == ',')
			i++;
		else if (k < 3 && line[i] != ',')
			return (0);
	}
	while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
		i++;
	return (k == 3 && line[i] == '\0');
}

int	parse_ceilling_color(t_data *data, char *line)
{
	int	i;
	int	k;

	if (!line || !*line)
		return (0);
	i = 0;
	k = 0;
	while (line[i] && k < 3)
	{
		if (!parse_rgb_value(line, &i, &data->textures.cc[k]))
			return (0);
		k++;
		if (k < 3 && line[i] == ',')
			i++;
		else if (k < 3 && line[i] != ',')
			return (0);
	}
	while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
		i++;
	return (k == 3 && line[i] == '\0');
}

int	line_identifier_parse(t_data *data, char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0 && !data->textures.no)
		data->textures.no = ft_strdup_n(line + 3);
	else if (ft_strncmp(line, "SO ", 3) == 0 && !data->textures.so)
		data->textures.so = ft_strdup_n(line + 3);
	else if (ft_strncmp(line, "WE ", 3) == 0 && !data->textures.we)
		data->textures.we = ft_strdup_n(line + 3);
	else if (ft_strncmp(line, "EA ", 3) == 0 && !data->textures.ea)
		data->textures.ea = ft_strdup_n(line + 3);
	else if (ft_strncmp(line, "F ", 2) == 0)
	{
		data->textures.fc_n++;
		if (data->textures.fc_n != 1 || !parse_floor_color(data, line + 2))
			return (0);
	}
	else if (ft_strncmp(line, "C ", 2) == 0)
	{
		data->textures.cc_n++;
		if (data->textures.cc_n != 1 || !parse_ceilling_color(data, line + 2))
			return (0);
	}
	else
		return (0);
	return (1);
}

int	parse_identifiers(t_data *data, int fd)
{
	char	*orig;
	char	*line;
	int		count;

	count = 0;
	while (1)
	{
		line = ft_gnl(fd);
		if (line == NULL)
			break ;
		if (is_empty_line(line))
		{
			free(line);
			continue ;
		}
		orig = line;
		if (!identifiers_utils(data, &line, orig, fd))
			return (0);
		count++;
		if (count == 6)
			break ;
	}
	image_remove_end_spaces(data);
	map_count_lines(data, fd);
	return (1);
}
