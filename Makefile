##
## Makefile for make in /home/maxime/delivery/MUL/wireframe/
##
## Made by Maxime JENNY
## Login   <maxime.jenny@epitech.eu>
##
## Started on  Tue Nov 22 14:44:48 2016 Maxime JENNY
## Last update Mon Dec 26 17:54:31 2016 Maxime JENNY
##

SRC = main.c	\
			my_str_to_wordtab.c	\
			my_getnbr.c	\
			open_window.c	\
			draw_minimap.c	\
			src/my_put_pixel.c	\
			src/my_draw_line.c	\
			src/move_forward.c	\
			src/raycast.c	\
			wolf.c	\
			event.c

NAME	=	wolf3d

OBJ	=	$(SRC:.c=.o)

FLAGS	=	-lm -lc_graph_prog -W -Wextra -Wall -Werror -pedantic

CFLAGS += -I./include -g

all:	$(NAME)

$(NAME): $(OBJ)
		gcc -o $(NAME) $(OBJ) $(FLAGS)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re:	fclean all
