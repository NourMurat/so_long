# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: numussan <numussan@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/13 00:31:47 by numussan          #+#    #+#              #
#    Updated: 2022/09/02 01:03:39 by numussan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

OBJS = ${SRCS:.c=.o}

RM = rm -f

CCF = gcc -Wall -Wextra -Werror

LIB = ar -rcs

SRCS = ft_printf.c conversions_1.c conversions_2.c

all: ${NAME}

$(NAME): ${OBJS}
		@${LIB} ${NAME} ${OBJS}

%.o : %.c ft_printf.h
	@${CCF} -c $< -o $@

clean:
		@${RM} ${OBJS}

fclean:	clean
		@${RM} ${NAME}

re:	fclean all

.PHONY: all clean fclean re
