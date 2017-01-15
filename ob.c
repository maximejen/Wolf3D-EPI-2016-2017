/*
** ob.c for ob in /home/maxime/delivery/MUL/wolf3d/
**
** Made by Maxime JENNY
** Login   <maxime.jenny@@epitech.eu>
**
** Started on  Fri Jan 13 17:02:49 2017 Maxime JENNY
** Last update Sun Jan 15 14:16:48 2017 Maxime JENNY
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

void		cp_frambuffer(t_my_framebuffer *one, t_my_framebuffer *two)
{
  int		i;

  i = 0;
  while (i < two->width * two->height * 4)
    {
      one->pixels[i] = two->pixels[i];
      i++;
    }
}

sfVector2i	cal_pos(t_my_framebuffer *obj, float angle, sfVector2i height)
{
  sfVector2i	pos;

  pos.x = ((WIDTH / 2) - (obj->width / 2)) + angle * FOV * 10;
  pos.y = HEIGHT / 2 - height.y / 2;
  return (pos);
}

void			draw_textu(sfVector2i dim, sfVector2i pos,
				     t_my_framebuffer *display,
				     t_my_framebuffer *obj)
{
  int			x;
  int			y;
  sfColor		c;
  float			i;
  float			j;

  x = pos.x;
  while (++x < (dim.x + pos.x))
    {
      i = ((x - pos.x) * obj->width / dim.x) * obj->width;
      y = pos.y - 1;
      while (++y < (dim.y + pos.y))
	{
	  j = ((y - (pos.y + dim.y)) * 499 / (dim.y) + 2);
	  c.r = (int)obj->pixels[(int)roundf((j + i) * 4)];
	  c.g = (int)obj->pixels[(int)roundf((j + i) * 4) + 1];
	  c.b = (int)obj->pixels[(int)roundf((j + i) * 4) + 2];
	  c.a = (int)obj->pixels[(int)roundf((j + i) * 4) + 3];
	  my_put_pixel(display, x, y, c);
	}
    }
}
