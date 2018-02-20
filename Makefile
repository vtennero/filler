# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vtennero <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/11 17:47:54 by vtennero          #+#    #+#              #
#    Updated: 2018/02/11 17:47:55 by vtennero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = vtennero.filler

FLAGS = -Wall -Werror -Wextra

SANITIZE = -g3 -fsanitize=address

SRC = main.c \
		utilities.c \
		parser.c \
		solver.c

PSRC = $(addprefix src/, $(SRC))

OBJ =  $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@ make -C libft/
	@ gcc -c $(FLAGS) $(PSRC) -I src/
	@ gcc $(FLAGS) $(SANITIZE) $(OBJ) libft/libft.a -o $(NAME)
	@ mv $(NAME) players/

clean:
	@ /bin/rm -f $(OBJ)
	@ make -C libft/ clean

fclean:
	@ make clean
	@ make -C libft/ fclean
	@ /bin/rm -f players/$(NAME)

re:
	@ make fclean
	@ make all

.PHONY: all clean fclean re