# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mafioron <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 15:31:44 by mafioron          #+#    #+#              #
#    Updated: 2024/11/17 18:42:55 by mafioron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = src/*.c

#BSRC = xxx_bonus.c

OBJ = $(SRC:.c=.o)
#BOBJ = $(BSRC:.c=.o)

NAME = libft.a

CFLAGS += -Wall -Werror -Wextra -I include

all:$(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
test:
	cc -o test $(OBJ)
#bonus: $(OBJ) $(BOBJ)

clean:
	rm -f $(OBJ)
fclean: 
	rm -f $(NAME) $(OBJ)

re: fclean all

.PHONY: all clean fclean re
