/*
** move_foward2.c for move in /home/maxime/delivery/MUL/wolf3d/
**
** Made by Maxime JENNY
** Login   <maxime.jenny@@epitech.eu>
**
** Started on  Thu Jan  5 11:14:37 2017 Maxime JENNY
** Last update Thu Jan  5 22:21:06 2017 Maxime JENNY
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <math.h>
#include "wolf.h"

sfVector2f	move_forward2(sfVector2f pos, float direction, float distance,
				      int **map)
{
  sfVector2f	pos2;
  int		x;
  int		y;
  float		angle;

  angle = direction * M_PI / 180;
  x = (cos(angle) > 0) ? (0.1) : (-0.1);
  y = (sin(angle) > 0) ? (-0.1) : (0.1);
  if (map[(int)((pos.y + cos(angle) * distance) + y)][(int)pos.x])
    pos2.x = pos.x + cos(angle) * distance;
  if (map[(int)pos.y][(int)((pos.x + cos(angle) * distance) + x)])
    pos2.y = pos.y + sin(angle) * distance;
  return (pos2);
}

void	my_draw_line2(t_my_framebuffer *framebuffer, sfVector2i *from,
			     sfVector2i *to, sfColor color)
{
  float xc;
  float yc;
  double count;
  float d;
  float x;
  float y;

  xc = to->x - from->x;
  yc = to->y - from->y;
  count = 1 / sqrt((xc * xc) + (yc * yc));
  d = 0;
  while (d <= 1)
    {
      x = from->x + xc * d;
      y = from->y + yc * d;
      my_put_pixel(framebuffer, x, y, color);
      d += count + 0.0000001;
    }
}
