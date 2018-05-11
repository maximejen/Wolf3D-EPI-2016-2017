##
## Makefile for make in /home/maxime/delivery/MUL/wireframe/
##
## Made by Maxime JENNY
## Login   <maxime.jenny@epitech.eu>
##
## Started on  Tue Nov 22 14:44:48 2016 Maxime JENNY
## Last update Sun Jan 15 22:24:08 2017 Maxime JENNY
##

SRC	=	main.c	\
		my_str_to_wordtab.c	\
		my_getnbr.c	\
		open_window.c	\
		draw_minimap.c	\
		src/my_put_pixel.c	\
		src/my_draw_line.c	\
		src/move_forward.c	\
		src/raycast.c	\
		wolf.c	\
		event.c	\
		utility.c	\
		textures.c	\
		raycast2.c	\
		move_foward2.c	\
		load_textures.c	\
		load_texture2.c	\
		move_mouse.c	\
		load_texture3.c	\
		free.c	\
		obj.c	\
		ob.c	\
		event_two.c	\
		print_numbers.c	\
		my_strcat.c

NAME	=	wolf3d

OBJ	=	$(SRC:.c=.o)

FLAGS	=	-lm -W -Wextra -Wall -Werror -pedantic -lc_graph_prog

CFLAGS	+=	-I./include

all:	$(NAME)

$(NAME): $(OBJ)
		gcc -o $(NAME) $(OBJ) $(FLAGS)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re:	fclean all
