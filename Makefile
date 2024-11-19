# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mafioron <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 18:30:26 by mafioron          #+#    #+#              #
#    Updated: 2024/11/18 18:30:35 by mafioron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# a modif
SRC = src/ft_printf.c src/ft_printnbr_base.c src/ft_printptr.c src/ft_print_ut.c src/ft_printnbs.c \
      src/ft_printnbs.c src/ft_printunsigned.c

#BSRC = xxx_bonus.c

OBJ = $(SRC:.c=.o)
#BOBJ = $(BSRC:.c=.o)

NAME = libftprintf.a

CFLAGS +=  -I include

all:$(NAME)

.c.o:

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
