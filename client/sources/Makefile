##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC		=	logic/callHandler.cpp \
			logic/clientHandler.cpp \
			logic/entityHandler.cpp \
			logic/serverHandler.cpp \
			actions.cpp \
			entity.cpp \
			audio.cpp \
			client.cpp \
			main.cpp \
			network.cpp \
			server.cpp

CFLAGS	=	libportaudio.a -std=gnu11 -Wall -Wextra -pthread -lboost_system -lportaudio -I ../include

OBJ		=	$(SRC:.cpp=.o)

INCLUDE	=	-o

LIB		=	-g -lm

NAME	=	babel_client

all:	$(NAME)

$(NAME):$(OBJ)
	g++ $(OBJ) $(CFLAGS) $(INCLUDE) $(NAME) $(LIB)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re