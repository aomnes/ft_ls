NAME = ls.out
CC = gcc
INCLUDE = header.h
SRC = main.c compte.c print.c acl.c\
      temps.c erreur.c tri.c argv.c

OBJET = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Wall

all:
		gcc -c $(FLAGS) $(SRC)
		gcc -o $(NAME) $(OBJET)

clean:
		rm -rf $(OBJET)

fclean: clean
		rm -rf $(NAME)

re: fclean all
