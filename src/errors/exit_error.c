#include "../../includes/cube3d.h"

void	put_error(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
}

void	exit_error(t_data *data, char *msg, int f)
{
	if_allocated_free(data);
	ft_putstr_fd("Error\n", 2);
	if (msg)
		ft_putstr_fd(msg, 2);
	if (f)
		perror("");
	exit(1);
}
