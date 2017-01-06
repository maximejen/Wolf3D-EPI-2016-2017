/*
** draw_minimap->c for draw in /home/maxime/delivery/MUL/wolf3d/
**
** Made by Maxime JENNY
** Login   <maxime->jenny@epitech->eu>
**
** Started on  Wed Dec 21 13:01:20 2016 Maxime JENNY
** Last update Thu Jan  5 19:32:40 2017 Maxime JENNY
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

void	draw_square(t_my_framebuffer *display, sfVector2i *from,
		    sfVector2i *size, sfColor color)
{
  int	x;
  int	y;

  from->x *= size->x;
  from->y *= size->y;
  y = from->y;
  while (y < (size->y + from->y))
    {
      x = from->x;
      while (x < (size->x + from->x))
	{
	  my_put_pixel(display, x, y, color);
	  x++;
	}
      y++;
    }
  from->x /= size->x;
  from->y /= size->y;
}

void		draw_minimap(int **map, t_my_framebuffer *display,
				int mapSize_x, int mapSize_y)
{
  sfVector2i	from;
  sfVector2i	size;
  float		scale;

  from.y = 0;
  scale = SCALE;
  size.x = scale / mapSize_x;
  size.y = scale / mapSize_y;
  while (from.y < mapSize_y)
    {
      from.x = 0;
      while (from.x < mapSize_x)
	{
	  if (map[from.y][from.x] == 1)
	    draw_square(display, &from, &size, sfBlue);
	  else
	    draw_square(display, &from, &size, sfWhite);
	  from.x++;
	}
      from.y++;
    }
}
