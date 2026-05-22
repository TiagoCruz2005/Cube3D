#ifndef CUBE3D_H
# define CUBE3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "game.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define FALSE 0
# define TRUE 1

typedef struct s_ptex
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		fc_n;
	int		cc_n;
	int		fc[3];
	int		cc[3];
}			t_ptex;

typedef struct s_data
{
	char	*file;
	char	**map;
	char	**map_copy;
	int		map_max_col;
	int		map_max_rows;
	int		num_lines;
	int		fd_check;
	int		fd_load;
	char	*flag_texture[5];
	char	p_looking_dir;
	t_ptex	textures;
	t_game	*game;
}			t_data;

// src/inits
// struct_inits.c
void		init_data(t_data *data);
void		init_textures(t_ptex *text);
int			inits(t_data *data, t_game *game);
void		init_struct(t_game *game);
int			init_player(t_data *data, t_game *game);

// src/errors
// exit_errors.c
void		exit_error(t_data *data, char *msg, int f);
void		put_error(char *msg);

// src/map
// parse_cub_identifiers.c
char		*trim_lead(char *str);
int			parse_floor_color(t_data *data, char *line);
int			parse_ceilling_color(t_data *data, char *line);
int			line_identifier_parse(t_data *data, char *line);
int			parse_identifiers(t_data *data, int fd);
int			identifiers_utils(t_data *data, char **line, char *orig, int fd);

// parse_file.c
int			if_tab(char *line);
int			contains_tabs(t_data *data);
int			verify_map_exist(t_data *data);

// parse_cub_identifiers_utils.c
char		*ft_strdup_n(char *line);
int			is_empty_line(char *line);
int			if_not_line_identifier_parse(t_data *data, char *line, char *orig,
				int fd);
void		free_if_line(t_data *data, char *line, int y);
void		remove_end_spaces(char *str);

// parse_image_path.c
void		image_remove_end_spaces(t_data *data);

// parse_map.c
int			is_identifier_line(char *line);
char		*skip_to_map_start(int fd);
void		map_count_lines(t_data *data, int fd);
int			create_parse_map(t_data *data);
void		parse_map(t_data *data, int fd);

// parse_map_utils.c
int			ft_strlen_n(char *str);
int			find_longest_line(t_data *data);
void		alloc_map_line(t_data *data, int i, int y);
int			copy_map_line(t_data *data, char *line, int y, int bigest_len);
void		island_handler(t_data *data, int fd);

// parse_map_lines.c
int			is_valid_map_tile(char c);
int			verify_map_cluster(t_data *d);
int			verify_line_borders(t_data *d);
int			verify_top_bottom_lines(t_data *d);
void		flood_fill(t_data *data, int row, int col, int fd);

// parse_map_player.c
void		locate_player(t_data *d, int fd);

// load_textures.c
int			load_textures(t_data data, t_game *game);
int			load_components(t_data *data, t_game *game);
int			load_screen(t_game *game);

// open_utils
// open.c
void		cub_open(t_data *data, int *fd, char *file);
int			open_file(t_data *data, char *path);

// src/verifications
// file_verifications.c
int			verify_file_extension(char *str);
void		verify_empty_file(t_data *data, char *file);
void		verify_onlyspaces_file(t_data *data);

// execute_verifications.c
void		execute_verifications(t_data *data);

// verify_allocs.c
void		if_allocated_free(t_data *data);
void		if_textures_alloc_free(t_data *data);

// verify_identifiers.c
int			verify_rgb(t_data *data);
int			verify_duplicate(t_ptex *tex);
int			verify_image_extension(char *str);
int			verify_images(t_data *data);

// verify_map_size.c
int			verify_map_size(t_data *data);

// load .cub
int			load_textures(t_data data, t_game *game);
int			load_components(t_data *data, t_game *game);
int			load_screen(t_game *game);

// game
// game.c
int			run_game(t_data *data, t_game *game);
int			game_loop(t_game *game);

// window.c
int			open_window(t_game *game);
void		cast_ray(t_game *game, int x);
t_texture	*get_texture(t_game *game);
void		render_frame(t_game *game);

// raycast.c
void		execute_dda(t_game *game);
void		init_ray(t_game *game, int x);
void		calc_wall_projection(t_game *game);

//draw.c
void		draw_ceilling(t_game *game, int x, int *y);
void		draw_wall(t_game *game, int x, int *y);
void		draw_floor(t_game *game, int x, int *y);
void		draw_column(t_game *game, int x);

//draw_utils.c
void		put_pixel(t_img *img, int x, int y, int color);
int			get_texture_pixel(t_texture *tex, int x, int y);

//keys.c
int			key_press(int keycode, t_game *game);
int			key_realease(int keycode, t_game *game);
void		update_player(t_game *game);

//move.c
void		move_forward(t_game *game);
void		move_backward(t_game *game);
void		move_right(t_game *game);
void		move_left(t_game *game);

//rotate.c
void		rotate_right(t_game *game);
void		rotate_left(t_game *game);
void		rotate_up_down(t_game *game, int dir);

//close.c
void		close_game(t_game *game);

// main_utils
// main_utils.c
void    main_arg_inits(t_data *data, t_game *game, int argc);
void    main_verify_file(t_data *data);
void    main_parse_identifiers(t_data *data, int fd);
void    main_verify_images_rgb_dup(t_data *data, t_game *game);
void    main_run_game(t_data *data, t_game *game);

#endif