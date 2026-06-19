include includes/colors.mk

CC = cc
FLAGS = -Wall -Werror -Wextra -O3 -Iincludes -Wno-cast-function-type

NAME = cub3D

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
LIBS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lbsd -lm
MLX = minilibx-linux

SRC = main.c src/errors/exit_error.c src/verifications/execute_verifications.c \
src/verifications/file_verifications.c src/verifications/verify_allocs.c \
src/map/parse_cub_identifiers.c src/map/parse_cub_identifiers_utils.c \
src/map/parse_cub_identifiers_utils_2.c \
src/inits/struct_inits.c src/verifications/verify_identifiers.c \
src/map/parse_map.c src/open_utils/open.c src/map/parse_map_utils.c \
src/map/parse_map_lines.c src/inits/inits_game.c src/map/load_game.c\
src/map/load_texture.c src/game/window.c src/game/game.c src/game/player.c\
src/map/parse_map_player.c src/game/raycast.c src/game/draw.c src/game/draw_utils.c\
src/game/keys.c src/game/move.c src/game/rotate.c src/game/close.c\
src/game/game_utils.c \
src/map/parse_image_path.c src/map/parse_file.c src/verifications/verify_map_size.c \
src/main_utils/main_utils.c src/map/parse_map_lines_utils.c \

OBJ_DIR = obj
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

all: $(LIBFT) $(MLX_LIB) $(NAME)

$(NAME): $(OBJ) $(MLX)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) $(LIBS) -o $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) all
	echo -e "📚$(FGCYAN)Libft Compilation Sucessfull$(RESET)📚"

$(MLX_LIB): $(MLX)
	@$(MAKE) -C $(MLX_DIR)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo -e "✨$(FGYELLOW)Object Compilation Sucessfull✨"
	$(CC) $(FLAGS) -c $< -o $@
	@echo -e "$(RESET)"

$(MLX):
	@git clone https://github.com/42paris/minilibx-linux.git

clean:
	rm -rf $(OBJ_DIR)
	@echo -e "$(FGRED)"
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean
	@echo -e "$(RESET)"

fclean: clean
	rm -f $(NAME)
	rm -rf $(MLX)
	@echo -e "$(FGRED)"
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo -e "$(RESET)"

re: fclean all

val:
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all --track-fds=yes ./cub3D resources/maps/maze.cub

.PHONY: all clean fclean re val
