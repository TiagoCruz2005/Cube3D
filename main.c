#include "cube3d.h"

int	main(int argc, char *argv[])
{
	t_data	data;
	t_game	game;
	int		fd;

	fd = 0;
	main_arg_inits(&data, &game, argc);
	data.game = &game;
	data.file = ft_strdup(argv[1]);
	main_verify_file(&data);
	cub_open(&data, &fd, data.file);
	main_parse_identifiers(&data, fd);
	parse_map(&data, fd);
	close(fd);
	main_verify_images_rgb_dup_mlx_init(&data, &game);
	main_run_game(&data, &game);
	return (0);
}
