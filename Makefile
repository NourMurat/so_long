# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: numussan <numussan@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 21:01:55 by numussan          #+#    #+#              #
#    Updated: 2022/09/16 17:13:40 by numussan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

SRCS		= get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
			so_long.c mandatory/parsing.c mandatory/parsing2.c mandatory/render.c \
			mandatory/valid_path_to_exit.c mandatory/movement.c mandatory/movement2.c

SRCS_B		= get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
			so_long_b.c bonus/parsing_b.c bonus/parsing2_b.c bonus/render_b.c \
			bonus/valid_path_to_exit_b.c bonus/movement_b.c bonus/movement2_b.c

OBJS		= $(SRCS:.c=.o)
OBJS_B		= $(SRCS_B:.c=.o)

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

bonus: $(OBJS_B)
	@$(MAKELIBFT)
	@$(MAKEPRINTF)
	@$(MAKEMLX)
	@$(CCF) -o $(NAME) $(SRCS_B) $(LIBFT) $(PRINTF) $(MLX) -framework OpenGL -framework AppKit

# MAKE -sC ./libft/

%.o : %.c so_long.h
	@$(CCF) -c $< -o $@

clean:
	@$(RM) $(OBJS) $(OBJS_B)
	@$(MAKELIBFT) clean
	@$(MAKEPRINTF) clean
	@$(MAKEMLX) clean

fclean: clean
	@$(RM) $(NAME)
	@$(MAKELIBFT) fclean
	@$(MAKEPRINTF) fclean
	@$(MAKEMLX) clean

re: fclean all
re_bonus: fclean bonus

.PHONY: all clean fclean re libft ft_printf get_next_line bonus