#include "cube3d.h"

void	main_arg_inits(t_data *data, t_game *game, int argc)
{
	if (argc != 2)
	{
		put_error("Invalid number of arguments\n");
		exit(EXIT_FAILURE);
	}
	if (!inits(data, game))
		exit_error(data, "Structs initialization error\n", 0);
}

void	main_verify_file(t_data *data)
{
	if (verify_file_extension(data->file))
		exit_error(data, "File is invalid\n", 0);
	verify_empty_file(data, data->file);
	if (contains_tabs(data))
		exit_error(data, "File contains tabs\n", 0);
	verify_onlyspaces_file(data);
}

void	main_parse_identifiers(t_data *data, int fd)
{
	if (!parse_identifiers(data, fd))
		exit_error(data, "Identifiers are incorrect\n", 0);
}

void	main_verify_images_rgb_dup_mlx_init(t_data *data, t_game *game)
{
	if (!verify_images(data))
		exit_error(data, "Incorrect extension\n", 0);
	execute_verifications(data);
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_error(data, "Failure to init mlx\n", 0);
	if (!load_components(data, game))
	{
		if_game_mlx_image_alloc_free(game);
		if_allocated_free(data);
		exit(EXIT_FAILURE);
	}
	if_allocated_free(data);
}

void	main_run_game(t_data *data, t_game *game)
{
	if (!run_game(data, game))
	{
		if_game_mlx_image_alloc_free(game);
		if_allocated_free(data);
		exit(EXIT_FAILURE);
	}
}
