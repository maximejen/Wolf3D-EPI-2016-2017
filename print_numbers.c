/*
** print_numbers.c for pri in /home/maxime/delivery/MUL/wolf3d/
**
** Made by Maxime JENNY
** Login   <maxime.jenny@@epitech.eu>
**
** Started on  Sun Jan 15 20:47:44 2017 Maxime JENNY
** Last update Sun Jan 15 22:07:17 2017 Maxime JENNY
*/

#include <SFML/System.h>
#include <SFML/Graphics.h>

#include <sys/stat.h>
#include <sys/types.h>

#include <fcntl.h>
#include <math.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

#include "wolf.h"

void		my_print_nbr(int **nbr, t_my_framebuffer *disp, sfVector2i pos)
{
  sfVector2i	from;
  sfVector2i	size;
  int		x;
  int		y;

  from.y = pos.y;
  size.x = 10;
  size.y = 10;
  y = 0;
  while (y < 6)
    {
      x = 0;
      from.x = pos.x;
      while (x < 6)
	{
	  if (nbr[y][x] == 1)
	    my_draw_square(disp, from, size, sfWhite);
	  from.x += 10;
	  x++;
	}
      from.y += 10;
      y++;
    }
}

void		my_print(t_wolf *wolf, t_my_framebuffer *display)
{
  sfVector2i	pos;

  pos.x = 1180 + 0 * (pos.y = 600);
  (wolf->keys == 0) ? (my_print_nbr(wolf->n->zero, display, pos)) : (0);
  (wolf->keys == 1) ? (my_print_nbr(wolf->n->one, display, pos)) : (0);
  (wolf->keys == 2) ? (my_print_nbr(wolf->n->two, display, pos)) : (0);
  (wolf->keys == 3) ? (my_print_nbr(wolf->n->three, display, pos)) : (0);
  (wolf->keys == 4) ? (my_print_nbr(wolf->n->four, display, pos)) : (0);
  (wolf->keys == 5) ? (my_print_nbr(wolf->n->five, display, pos)) : (0);
  (wolf->keys == 6) ? (my_print_nbr(wolf->n->six, display, pos)) : (0);
  (wolf->keys == 7) ? (my_print_nbr(wolf->n->seven, display, pos)) : (0);
  (wolf->keys == 8) ? (my_print_nbr(wolf->n->eight, display, pos)) : (0);
  (wolf->keys == 9) ? (my_print_nbr(wolf->n->nine, display, pos)) : (0);
  pos.x = 90 + 0 * (pos.y = 635);
  (wolf->stele == 0) ? (my_print_nbr(wolf->n->zero, display, pos)) : (0);
  (wolf->stele == 1) ? (my_print_nbr(wolf->n->one, display, pos)) : (0);
  (wolf->stele == 2) ? (my_print_nbr(wolf->n->two, display, pos)) : (0);
  (wolf->stele == 3) ? (my_print_nbr(wolf->n->three, display, pos)) : (0);
  (wolf->stele == 4) ? (my_print_nbr(wolf->n->four, display, pos)) : (0);
  (wolf->stele == 5) ? (my_print_nbr(wolf->n->five, display, pos)) : (0);
  (wolf->stele == 6) ? (my_print_nbr(wolf->n->six, display, pos)) : (0);
  (wolf->stele == 7) ? (my_print_nbr(wolf->n->seven, display, pos)) : (0);
  (wolf->stele == 8) ? (my_print_nbr(wolf->n->eight, display, pos)) : (0);
  (wolf->stele == 9) ? (my_print_nbr(wolf->n->nine, display, pos)) : (0);
}

int		**my_load_numbers(char *buffer, int **number)
{
  int		x;
  int		y;
  int		i;

  i = 0;
  y = 0;
  number = malloc(sizeof(int *) * (6));
  while (y < 6)
    {
      x = 0;
      number[y] = malloc(sizeof(int) * (6));
      while (x < 6)
	{
	  number[y][x] = my_get_number(buffer, &i);
	  i++;
	  x++;
	}
      y++;
    }
  return (number);
}

void		folowing(t_wolf *wolf, int fd, char *str)
{
  fd = open("./resources/four.txt", O_RDONLY);
  read(fd, str, 42);
  wolf->n->four = my_load_numbers(str, wolf->n->four);
  close (fd);
  fd = open("./resources/five.txt", O_RDONLY);
  read(fd, str, 42);
  wolf->n->five = my_load_numbers(str, wolf->n->five);
  close (fd);
  fd = open("./resources/six.txt", O_RDONLY);
  read(fd, str, 42);
  wolf->n->six = my_load_numbers(str, wolf->n->six);
  close (fd);
  fd = open("./resources/seven.txt", O_RDONLY);
  read(fd, str, 42);
  wolf->n->seven = my_load_numbers(str, wolf->n->seven);
  close (fd);
  fd = open("./resources/eight.txt", O_RDONLY);
  read(fd, str, 42);
  wolf->n->eight = my_load_numbers(str, wolf->n->eight);
  close (fd);
  fd = open("./resources/nine.txt", O_RDONLY);
  read(fd, str, 42);
  wolf->n->nine = my_load_numbers(str, wolf->n->nine);
  close (fd);
}

void		load_n(t_wolf *wolf)
{
  char		*str;
  int		fd;

  if ((wolf->n = malloc(sizeof(t_nbrs))) == NULL || (str = malloc(43)) == NULL)
    return ;
  fd = open("./resources/zero.txt", O_RDONLY);
  read(fd, str, 42);
  str[42] = '\0';
  wolf->n->zero = my_load_numbers(str, wolf->n->zero);
  close (fd);
  fd = open("./resources/one.txt", O_RDONLY);
  read(fd, str, 42);
  wolf->n->one = my_load_numbers(str, wolf->n->one);
  close (fd);
  fd = open("./resources/two.txt", O_RDONLY);
  read(fd, str, 42);
  wolf->n->two = my_load_numbers(str, wolf->n->two);
  close (fd);
  fd = open("./resources/three.txt", O_RDONLY);
  read(fd, str, 42);
  wolf->n->three = my_load_numbers(str, wolf->n->three);
  close (fd);
  folowing(wolf, fd, str);
}
