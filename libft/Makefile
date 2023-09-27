NAME = libft.a

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
OBJ_DIR = obj

VPATH = gnl:ft_printf:libft

SRC = \
ft_bzero.c				ft_isalnum.c		ft_isalpha.c	ft_isascii.c 		\
ft_isdigit.c			ft_isprint.c		ft_memcpy.c		ft_memmove.c 		\
ft_memset.c				ft_memchr.c			ft_memcmp.c		ft_strlcpy.c 		\
ft_strlen.c				ft_strncmp.c		ft_tolower.c	ft_toupper.c		\
ft_calloc.c				ft_putchar_fd.c		ft_putstr_fd.c	ft_putendl_fd.c 	\
ft_strchr.c				ft_strrchr.c		ft_strdup.c		ft_strlcat.c		\
ft_strnstr.c			ft_atoi.c			ft_substr.c		ft_strjoin.c		\
ft_strtrim.c			ft_putnbr_fd.c		ft_itoa.c		ft_strmapi.c		\
ft_striteri.c			ft_split.c			ft_hexbig.c		ft_hexsmol.c		\
ft_printf_utils1.c		ft_printf_utils2.c	ft_printf.c		ft_putchar_print.c	\
ft_putnbr_print.c		ft_putstr_print.c	ft_putusnbr.c	ft_putvoid.c		\
ft_strchrint.c			ft_strjoinfree.c	get_next_line.c	ft_strlenexclude.c

CFLAGS = -Wall -Wextra -Werror -MMD -g
INCFLAGS = -Iincludes

DEP = $(OBJ:.o=.d)

all:  $(NAME)

CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m

$(NAME): $(OBJ)
	@echo "$(GREEN)Building libft library.$(CLR_RMV)"
	@ar rc $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@echo "$(GREEN)Making libft .o files.$(CLR_RMV)"
	@cc $(CFLAGS) $(INCFLAGS) -c $< -o $@

-include $(DEP)

clean:
	@echo "$(RED)Cleaning the obj folder.$(CLR_RMV)"
	@rm -rf $(OBJ_DIR) 

fclean: clean
	@echo "$(RED)Removing the library.$(CLR_RMV)"
	@rm -f $(NAME)
re: fclean all
