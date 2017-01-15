/*
** utility.c for utility in /home/maxime/delivery/MUL/wolf3d/
**
** Made by Maxime JENNY
** Login   <maxime.jenny@epitech.eu>
**
** Started on  Wed Dec 28 22:29:55 2016 Maxime JENNY
** Last update Sun Jan 15 14:28:52 2017 Maxime JENNY
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "wolf.h"

void		my_set_player_pos(t_wolf *wolf)
{
  int		x;
  int		y;

  y = 0;
  x = 0;
  while (wolf->map[y][x] != 0 && y++ < wolf->height)
    {
      x = 0;
      while (x < wolf->width && wolf->map[y][x] != 0)
	x++;
    }
  wolf->player_x = x + 0.5;
  wolf->player_y = y + 0.5;
  (wolf->map[y][x + 1] == 0) ? (wolf->angle = 0) : (0);
  (wolf->map[y + 1][x] == 0) ? (wolf->angle = 90) : (0);
  (wolf->map[y][x - 1] == 0) ? (wolf->angle = 180) : (0);
  (y != 0 && wolf->map[y - 1][x] == 0) ? (wolf->angle = 270) : (0);
}

sfVector2i	*my_create_vector(int x, int y)
{
  sfVector2i	*vector;

  if (vector = malloc(sizeof(sfVector2i)))
    return (NULL);
  vector->x = x;
  vector->y = y;
  return (vector);
}

sfColor		my_create_color(int r, int g, int b, int a)
{
  sfColor	color;

  color.r = r;
  color.g = g;
  color.b = b;
  color.a = a;
  return (color);
}

void	my_draw_square(t_my_framebuffer *display, sfVector2i from,
		       sfVector2i size, sfColor color)
{
  int	x;
  int	y;

  y = from.y;
  while (y < (size.y + from.y))
    {
      x = from.x;
      while (x < (size.x + from.x))
	{
	  my_put_pixel(display, x, y, color);
	  x++;
	}
      y++;
    }
}

void	my_draw_line_two(t_my_framebuffer *framebuffer, sfVector2i *from,
			     sfVector2i *to, sfColor color)
{
  int	i;

  i = from->y;
  while (i != to->y)
    {
      (from->y > to->y) ? (i--) : (i++);
      my_put_pixel(framebuffer, from->x, i, color);
    }
}
