# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: numussan <numussan@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 21:01:55 by numussan          #+#    #+#              #
#    Updated: 2022/09/15 22:11:24 by numussan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

SRCS		= get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
			so_long.c parsing.c parsing2.c render.c valid_path_to_exit.c movement.c movement2.c

OBJS		= $(SRCS:.c=.o)

CCF			= gcc -Wall -Wextra -Werror

MAKEMLX		= cd minilibx && make
MLX			= ./minilibx/libmlx.a

MAKELIBFT	= cd libft && make
MAKEPRINTF	= cd ft_printf && make

LIBFT		= libft/libft.a
PRINTF		= ft_printf/libftprintf.a

RM			= rm -f


all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKELIBFT)
	@$(MAKEPRINTF)
	@$(MAKEMLX)
	@$(CCF) -o $(NAME) $(SRCS) $(LIBFT) $(PRINTF) $(MLX) -framework OpenGL -framework AppKit

# MAKE -sC ./libft/

%.o : %.c so_long.h
	@$(CCF) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@$(MAKELIBFT) clean
	@$(MAKEPRINTF) clean
	@$(MAKEMLX) clean

fclean: clean
	@$(RM) $(NAME)
	@$(MAKELIBFT) fclean
	@$(MAKEPRINTF) fclean
	@$(MAKEMLX) clean

re: fclean all

.PHONY: all clean fclean re libft