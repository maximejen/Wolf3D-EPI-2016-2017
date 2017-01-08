/*
** draw_minimap->c for draw in /home/maxime/delivery/MUL/wolf3d/
**
** Made by Maxime JENNY
** Login   <maxime->jenny@epitech->eu>
**
** Started on  Wed Dec 21 13:01:20 2016 Maxime JENNY
** Last update Wed Jan 11 17:21:30 2017 Maxime JENNY
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
  from->y *= size->x;
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

void		put_map(int **map, sfVector2i from, sfVector2i size,
			t_my_framebuffer *display)
{
  if (map[from.y][from.x] == 'C')
    draw_square(display, &from, &size, sfRed);
  else if (map[from.y][from.x] == 'O')
    {
      draw_square(display, &from, &size, my_create_color(46, 204, 114,
							 255));
    }
  else if (map[from.y][from.x] == 'U')
    {
      draw_square(display, &from, &size, my_create_color(211, 81, 0,
							 255));
    }
  else if (map[from.y][from.x] != 0 && map[from.y][from.x] != 'O' &&
	   map[from.y][from.x] != 'K')
    {
      draw_square(display, &from, &size, sfBlue);
    }
  else
    draw_square(display, &from, &size, sfWhite);
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
	  put_map(map, from, size, display);
	  from.x++;
	}
      from.y++;
    }
}
