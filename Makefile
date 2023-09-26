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
LIBMLX		:= ./inc/mlx
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
                          
OBJS        := $(SRCS:.c=.o)

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
	cmake -B $(LIBMLX)/build -S $(LIBMLX) && make -C $(LIBMLX)/build

$(NAME): $(OBJ)
# gcc main.c ... libmlx42.a -Iinclude -lglfw
	make -C $(libft)
	$(CC) $(C_FLAGS) $(SRCS) $(OBJS) $(LIBFT) -o $(NAME) 

$(OBJ_DIR)/%.o: %.c
	cmake -B $(OBJ_DIR) -S
	$(CC) $(FLAGS) $(INC) -c $< -o $@ && echo "Compiling: $(notdir $<)"

-include $(DEP)

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(LIBMLX)/build

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all, clean, fclean, re, libmlx
