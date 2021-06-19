# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/08 14:35:57 by ugdaniel          #+#    #+#              #
#    Updated: 2021/06/19 08:47:42 by ugdaniel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
OSTYPE = $(shell uname)

SRCS = $(wildcard srcs/*.c srcs/*/*.c)
OBJS = $(SRCS:.c=.o)

CC = @clang
FLAGS = -Wall -Wextra -Werror -fsanitize=address
HEADERS = -I srcs/ -I mlx -I libft

LIBFT = libft/libft.a
LIBFT_PATH = libft/

MLX = mlx/libmlx.a
MLX_PATH = mlx/
LIBS = $(MLX) $(LIBFT) -lm -framework OpenGL -framework AppKit -I. -Imlx

white = \033[39m
green = \033[92m
cyan = \033[96m
magenta = \033[35m
lmagenta = \033[95m
yellow = \033[33m
gray = \033[37m
red = \033[91m
blue = \033[94m

all: $(NAME)

bonus: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	@echo "$(yellow)Source files compiled"
	@echo "$(red)\c"
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBS)
	@echo "$(green)So_long ready!"

.c.o:
	@echo "$(gray)Compiling $<... \c"
	@echo "$(red)\c"
	$(CC) $(FLAGS) $(HEADERS) -c $< -o $@
	@echo "$(cyan)OK!"

$(MLX):
	@echo "$(gray)Compiling MiniLibX... \c"
	@make -s -C mlx
	@echo "$(cyan)OK!\n"
	clear
	@echo "$(yellow)MiniLibX compiled"
	@echo "$(red)\c"

$(LIBFT):
	@echo "$(gray)Compiling Libft... \c"
	@make -s -C $(LIBFT_PATH)
	@echo "$(cyan)OK!\n$(yellow)Libft compiled"
	@echo "$(red)\c"

clean_libft:
	@echo "$(gray)Cleaning Libft"
	@echo "$(red)\c"
	@make -s clean -C $(LIBFT_PATH)

clean_mlx:
	@echo "$(gray)Cleaning MiniLibX"
	@echo "$(red)\c"
	@make -s clean -C $(MLX_PATH)

fclean_mlx: clean_mlx
	@rm -f $(MLX)
	@echo "$(magenta)$(MLX) removed"

clean_objs:
	@echo "$(gray)Cleaning object files"
	@echo "$(red)\c"
	@rm -rf $(OBJS)

clean: clean_mlx clean_libft clean_objs

fclean_exec: clean_objs
	@rm -rf $(NAME)
	@echo "$(lmagenta)Executable removed"
	@echo "$(red)\c"

fclean_libft: clean_libft
	@rm -rf $(LIBFT)
	@echo "$(magenta)$(LIBFT) removed"
	@echo "$(red)\c"

fclean: fclean_mlx fclean_libft fclean_exec

re_nolib: fclean_exec newline all

re: fclean newline all

bonus:

newline:
	@echo ""

.PHONY: all clean_libft clean_objs clean fclean_exec fclean_libft fclean re_nolib re test
