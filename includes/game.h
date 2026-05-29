#ifndef GAME_H
# define GAME_H

# define WIDTH 1920
# define HEIGHT 960

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define ESC 65307
# define KEY_SHIFT 65505

# define SPEED 0.07
# define ROT_SPEED 0.05
# define PLAYER_RADIUS 0.12

typedef struct s_img
{
	void		*img_ptr;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}				t_img;

typedef struct s_texture
{
	t_img		img;
	int			width;
	int			height;
}				t_texture;

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		pitch;
	int			running;
}				t_player;

typedef struct s_map
{
	char		**grid;
	int			width;
	int			height;
}				t_map;

typedef struct s_keys
{
	int			w;
	int			a;
	int			s;
	int			d;
	int			left;
	int			right;
	int			up;
	int			down;
}				t_keys;

typedef struct s_color
{
	int			r;
	int			g;
	int			b;

	int			value;
}				t_color;

typedef struct s_tex
{
	t_texture	north;
	t_texture	south;
	t_texture	east;
	t_texture	west;
}				t_tex;

typedef struct s_ray
{
	double		camera_x;

	double		ray_dir_x;
	double		ray_dir_y;

	int			map_x;
	int			map_y;

	double		side_dist_x;
	double		side_dist_y;

	double		delta_dist_x;
	double		delta_dist_y;

	double		perp_wall_dist;

	int			step_x;
	int			step_y;
	int			hit;
	int			side;

	int			line_height;
	int			draw_start;
	int			draw_end;

	double		wall_x;
	int			tex_x;

	double		step;
	double		tex_pos;
}				t_ray;

typedef struct s_game
{
	void		*mlx;
	void		*win;

	t_img		screen;
	t_map		map;
	t_player	player;
	t_tex		tex;
	t_keys		keys;
	t_color		floor;
	t_color		ceiling;
	t_ray		ray;
	int			screen_width;
	int			screen_height;
}				t_game;

#endif
