# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dfinn <dfinn@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 11:47:50 by dfinn             #+#    #+#              #
#    Updated: 2022/11/18 12:54:47 by dfinn            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = ./libft/libft.a

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c\
			ft_print_hex.c\
			ft_print_unsigned.c\
			ft_utils.c\
			ft_utils_bis.c\
			ft_utils_bis.c\

OBJS = ${SRC:.c=.o}
LIBR 	= ranlib
LIBC 	= ar rc
REMOVE	= rm -f

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean :
	$(RM) $(OBJS)
	$(RM) $(OBJSBON)
	$(RM) $(OBJS_DIR)

fclean : clean
	$(RM) $(NAME)

re : fclean all

			