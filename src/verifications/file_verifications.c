/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_verifications.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 19:35:40 by tide-pau          #+#    #+#             */
/*   Updated: 2026/06/09 19:35:41 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	verify_file_extension(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len < 4)
		return (1);
	return (ft_strcmp(str + len - 4, ".cub"));
}

void	verify_empty_file(t_data *data, char *file)
{
	int		fd;
	char	c;

	fd = 0;
	cub_open(data, &fd, file);
	if (read(fd, &c, 1) == 0)
	{
		close(fd);
		exit_error(data, "Empty file\n", 0);
	}
	close(fd);
}

void	verify_onlyspaces_file(t_data *data)
{
	int		fd;
	char	c;
	int		rret;

	fd = 0;
	cub_open(data, &fd, data->file);
	rret = read(fd, &c, 1);
	while (rret > 0)
	{
		if (c != ' ' && c != '\n' && c != '\t')
		{
			close(fd);
			return ;
		}
		rret = read(fd, &c, 1);
	}
	close(fd);
	exit_error(data, "File contains only spaces\n", 0);
}
