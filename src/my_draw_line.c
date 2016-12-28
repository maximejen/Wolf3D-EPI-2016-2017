/*
** bootstrap.c for bootstrap in /home/maxime/delivery/MUL/bswireframe2/
**
** Made by Maxime JENNY
** Login   <maxime.jenny@epitech.eu@epitech.eu>
**
** Started on  Tue Nov 15 09:11:28 2016 Maxime JENNY
** Last update Sun Dec 25 18:26:57 2016 Maxime JENNY
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <math.h>
#include "wolf.h"

void	my_draw_line(t_my_framebuffer *framebuffer, sfVector2i from,
			     sfVector2i to, sfColor color)
{
  float xc;
  float yc;
  double count;
  float d;

  xc = to.x - from.x;
  yc = to.y - from.y;
  count = 1 / sqrt((xc * xc) + (yc * yc));
  d = 0;
  while (d <= 1)
    {
      float x = from.x + xc * d;
      float y = from.y + yc * d;
      my_put_pixel(framebuffer, x, y, color);
      d += count + 0.000000001;
    }
}
