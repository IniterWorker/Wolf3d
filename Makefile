##
## Makefile for  in /home/bonett_w/Wolf3D/
##
## Made by walter bonetti
## Login   <bonett_w@epitech.eu>
##
## Started on  Mon Dec 14 15:22:29 2015 walter bonetti
## Last update Sun Dec 27 17:27:09 2015 walter bonetti
##

CC	=	gcc

RM	=	rm -f

SRC	=	main.c \
  		bmp.c \
		raycaster.c \
		player.c \
		texture.c \
		array.c \
		color.c \
		scale.c \
		move.c \
		view.c \
		tableau.c \
		maper.c \
		map.c

NAME	=	wolf3d

LIB	=	-L/home/${USER}/.froot/lib/ -llapin \
		-L/usr/local/lib \
		-lsfml-audio \
		-lsfml-graphics \
		-lsfml-window \
		-lsfml-system \
		-lstdc++ -ldl \
		-L./lib \
		-lmy \
		-llist \
		-lm

FLAG 	=	-W -Wall -ansi -pedantic \
		-I./include -I/home/${USER}/.froot/include/

OBJ 	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	gcc $(OBJ) $(LIB) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.c.o:
	gcc -c $< -o $@ $(FLAG)

game: all
	./$(NAME)

.PHONY: all re fclean clean game
