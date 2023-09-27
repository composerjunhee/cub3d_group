#  |  |  ___ \    \  |         |
#  |  |     ) |  |\/ |   _  |  |  /   _ 
# ___ __|  __/   |   |  (   |    <    __/ 
#    _|  _____| _|  _| \__,_| _|\_\ \___|
#                              by RUSH
################################################################################
#                                     CONFIG                                   #
################################################################################

NAME        := cub3D
CC        := gcc
VPATH = src:libft:inc
FLAGS    := -Wall -Wextra -Werror -Ofast
MAC_FLAGS    := -framework Cocoa -framework OpenGL -framework IOKit
LIBMLX		:= /inc/mlx
SRC_DIR	:= ./src
OBJ_DIR	:= ./obj
LIBFT_DIR := ./libft
LIBFT := $(LIBFT_DIR)/libft.a
HEADER := ./inc
INC		:= -I $(HEADER) -I $(LIBMLX)/include

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        := main.c
                          
OBJS := $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

DEP := $(OBJS:.o=.d)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

################################################################################
#                                  Makefile  objs                              #
################################################################################


CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m

all: $(NAME)

libmlx:
	@echo "$(GREEN)Making the build folder in mlx and the Makefile for it.$(CLR_RMV)"
	@cmake -B $(LIBMLX)/build -S $(LIBMLX) && make -C $(LIBMLX)/build

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	@echo "$(GREEN)Making the cub3D program.$(CLR_RMV)"
	@$(CC) $(C_FLAGS) $(OBJS) $(LIBFT) -o $(NAME) 

$(OBJ_DIR)/%.o: %.c
	@echo "$(GREEN)Building the obj folder.$(CLR_RMV)"
	@mkdir -p $(OBJ_DIR)
	@echo "$(GREEN)Cooking up object files.$(CLR_RMV)"
	@$(CC) $(FLAGS) $(INC) -c $< -o $@

-include $(DEP)

clean:
	@echo "$(RED)Cleaning up obj directory and build folder in inc/mlx.$(CLR_RMV)"
	@rm -rf $(OBJ_DIR)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@echo "$(RED)Deep cleaning program and folders.$(CLR_RMV)"
	@rm -rf $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all, clean, fclean, re, libmlx
