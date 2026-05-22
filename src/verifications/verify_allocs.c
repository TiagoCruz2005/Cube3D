#include "cube3d.h"

void	if_allocated_free(t_data *data)
{
	if (data->file)
		free(data->file);
	if (data->map)
		ft_free_vector(&data->map);
	if (data->map_copy)
		ft_free_vector(&data->map_copy);
	if_textures_alloc_free(data);
}

void	if_textures_alloc_free(t_data *data)
{
	if (data->textures.no)
		free(data->textures.no);
	if (data->textures.so)
		free(data->textures.so);
	if (data->textures.we)
		free(data->textures.we);
	if (data->textures.ea)
		free(data->textures.ea);
}
