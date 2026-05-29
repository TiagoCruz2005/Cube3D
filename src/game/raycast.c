#include "cube3d.h"

static void	calc_wall_collision(t_game *game)
{
	int			tex_x;
	t_texture	*tex;

	tex = get_texture(game);
	if (game->ray.side == 0)
		game->ray.wall_x = game->player.pos_y + game->ray.perp_wall_dist
			* game->ray.ray_dir_y;
	else
		game->ray.wall_x = game->player.pos_x + game->ray.perp_wall_dist
			* game->ray.ray_dir_x;
	game->ray.wall_x -= floor(game->ray.wall_x);
	tex_x = (int)(game->ray.wall_x * tex->width);
	if (game->ray.side == 0 && game->ray.ray_dir_x > 0)
		tex_x = tex->width - tex_x - 1;
	if (game->ray.side == 1 && game->ray.ray_dir_y < 0)
		tex_x = tex->width - tex_x - 1;
	game->ray.tex_x = tex_x;
}

void	calc_wall_projection(t_game *game)
{
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;

	side_dist_x = game->ray.side_dist_x;
	side_dist_y = game->ray.side_dist_y;
	delta_dist_x = game->ray.delta_dist_x;
	delta_dist_y = game->ray.delta_dist_y;
	if (game->ray.side == 0)
		game->ray.perp_wall_dist = side_dist_x - delta_dist_x;
	else
		game->ray.perp_wall_dist = side_dist_y - delta_dist_y;
	game->ray.line_height = (int)(HEIGHT / game->ray.perp_wall_dist);
	game->ray.draw_start = -game->ray.line_height / 2 + HEIGHT / 2
		+ game->player.pitch;
	game->ray.draw_end = game->ray.line_height / 2 + HEIGHT / 2
		+ game->player.pitch;
	calc_wall_collision(game);
}

void	execute_dda(t_game *game)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (game->ray.side_dist_x < game->ray.side_dist_y)
		{
			game->ray.side_dist_x += game->ray.delta_dist_x;
			game->ray.map_x += game->ray.step_x;
			game->ray.side = 0;
		}
		else
		{
			game->ray.side_dist_y += game->ray.delta_dist_y;
			game->ray.map_y += game->ray.step_y;
			game->ray.side = 1;
		}
		if (is_blocking_tile(game, game->ray.map_x, game->ray.map_y))
			hit = 1;
	}
}

static void	calc_step_side_dist(t_game *game)
{
	if (game->ray.ray_dir_x < 0)
	{
		game->ray.step_x = -1;
		game->ray.side_dist_x = (game->player.pos_x - game->ray.map_x)
			* game->ray.delta_dist_x;
	}
	else
	{
		game->ray.step_x = 1;
		game->ray.side_dist_x = (game->ray.map_x + 1.0 - game->player.pos_x)
			* game->ray.delta_dist_x;
	}
	if (game->ray.ray_dir_y < 0)
	{
		game->ray.step_y = -1;
		game->ray.side_dist_y = (game->player.pos_y - game->ray.map_y)
			* game->ray.delta_dist_y;
	}
	else
	{
		game->ray.step_y = 1;
		game->ray.side_dist_y = (game->ray.map_y + 1.0 - game->player.pos_y)
			* game->ray.delta_dist_y;
	}
}

void	init_ray(t_game *game, int x)
{
	game->ray.camera_x = 2 * (x / (double)WIDTH) - 1;
	game->ray.ray_dir_x = game->player.dir_x + game->player.plane_x
		* game->ray.camera_x;
	game->ray.ray_dir_y = game->player.dir_y + game->player.plane_y
		* game->ray.camera_x;
	game->ray.map_x = (int)game->player.pos_x;
	game->ray.map_y = (int)game->player.pos_y;
	game->ray.delta_dist_x = fabs(1 / game->ray.ray_dir_x);
	game->ray.delta_dist_y = fabs(1 / game->ray.ray_dir_y);
	calc_step_side_dist(game);
}
