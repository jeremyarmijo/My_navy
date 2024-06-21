##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## my_hunter
##

NAME	=	my_navy

CFLAGS	=	-Wall -Wextra -iquote includes

SRC	=	src/main.c	\
		src/base.c	\
		src/my_strcmp.c  \
		src/my_strlens.c	\
		src/tiers.c			\
		src/my_put_nbr.c	\
		src/my_putchar.c	\
		src/enemy.c			\
		src/create_map.c	\
		src/put_boat.c		\
		src/my_getnbr.c		\
		src/signal_management.c	\
		src/print_map.c	\
		src/value_back.c	\
		src/send_attack.c	\
		src/miss_or_hit.c	\
		src/win.c	\
		src/attack.c	\
		src/rocket.c	\
		src/sig_management.c

OBJ	=	$(SRC:.c=.o)

all:	$(OBJ)
	gcc $(OBJ) -o $(NAME) $(CFLAGS) $(CSFML)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
