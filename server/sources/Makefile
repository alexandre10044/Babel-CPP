##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC		=	logic/connectionHandler.cpp \
			logic/serverHandler.cpp \
			entity.cpp \
			main.cpp \
			network.cpp \
			server.cpp

CFLAGS	=	-std=gnu11 -Wall -Wextra -pthread -lboost_system -I ../include

OBJ		=	$(SRC:.cpp=.o)

INCLUDE	=	-o

LIB		=	-g -lm -Boost_LIBRARIES

NAME	=	babel_server

all:	$(NAME)

$(NAME):$(OBJ)
	g++ $(OBJ) $(CFLAGS) $(INCLUDE) $(NAME) $(LIB)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re