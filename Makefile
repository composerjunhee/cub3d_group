NAME 		= cub3D

S			= src/
O			= obj/
I			= inc/
LIBFT_I		= libft/includes

CC			= cc
CFLAGS		= -Wall -Werror -Wextra
INCLUDES	= -I$I -I$(LIBFT_I) -Iinclude -I./MLX42/include
LIBRARIES	= -L./libft -lft -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -L./build/ -lmlx42
FSANITIZE	= 

AR			= ar
ARFLAGS		= rcs

SRC 		= \
$S/main.c $S/utils.c $S/map.c  $S/param_utils.c $S/checker_functions.c $S/rendering.c $S/color_functions.c $S/controller.c $S/orientation.c $S/ray.c $S/textures.c

OBJ			= $(SRC:$S%=$O%.o)

RM			= /bin/rm -f
RMDIR		= /bin/rm -rf

LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a
LIBFT_FLAGS	=

.PHONY: all clean fclean re

all: $(NAME)

$O:
	@mkdir $@

$(OBJ): | $O


$(OBJ): $O%.o: $S%
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(LIBFT) $(OBJ)
	cmake -B build MLX42
	cmake --build build -j4
	$(CC) $(OBJ) $(LIBRARIES) $(FSANITIZE) -o $(NAME)

$(LIBFT):
	make FLAGS=$(LIBFT_FLAGS) -C $(LIBFT_DIR)

cleanobjdir: $O
	$(RMDIR) $O

clean: cleanobjdir

fclean: clean
	make fclean -C libft
	$(RM) $(NAME)

re:
	@make fclean
	@make all

run_test: $(LIBFT)
	make CUB3D="$(SRC)" -C test


debug: CFLAGS := $(filter-out -O3,$(CFLAGS))
debug: CFLAGS += -g
debug: LIBFT_FLAGS += -g
debug: $(NAME)

what: FSANITIZE += -fsanitize=address -g
what: $(NAME)