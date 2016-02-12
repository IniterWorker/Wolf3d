##
## Makefile for Lib Matrix in /home/bonett_w/rendu/maths/102cipher/matrix
##
## Made by walter bonetti
## Login   <bonett_w@epitech.net>
##
## Started on  Mon Nov 23 10:19:13 2015 walter bonetti
## Last update Tue Dec  8 16:34:48 2015 walter bonetti
##

CC	=	gcc

CFLAGS	=	-W -Wall -Werror -Wextra -I./

SRC	=	list.c \
		tri.c \
		node.c \
		push.c \
		remove.c \
		delete.c

OBJ	=	$(SRC:.c=.o)

NAME	=	liblist.a

TMP	=	$(SRC:.c=.c~) \
		Makefile~

RM	=	rm -f

CP	=	cp $(NAME) ../. && cp list.h ../../include/.

all: $(NAME)

$(NAME): $(SRC)
	$(CC) -c $(SRC) $(CFLAGS)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	$(CP)

clean:
	$(RM) $(OBJ)
	$(RM) $(TMP)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re fclean clean all
