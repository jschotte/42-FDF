# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschotte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 10:08:32 by jschotte          #+#    #+#              #
#    Updated: 2016/01/07 12:53:06 by jschotte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = fdf.c

OBJ = $(SRC:.c=.o)

$(NAME):
	make -C libft/ fclean && make -C libft/
	gcc -c $(SRC)
	gcc -o $(NAME) $(OBJ) -L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL -framework AppKit 

all: $(NAME)

clean:
		make -C libft/ clean
		rm -rf $(OBJ)

fclean: clean
		make -C libft/ fclean
		rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re
