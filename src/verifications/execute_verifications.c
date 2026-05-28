#include "../../includes/cube3d.h"

void	execute_verifications(t_data *data)
{
	if (!verify_rgb(data))
		exit_error(data, "Error: invalid color\n", 0);
	if (!verify_duplicate(&data->textures))
		exit_error(data, "Error: duplicate found\n", 0);
}
