/*
** textures.c for textures and shadows in /home/maxime/delivery/MUL/wolf3d/
**
** Made by Maxime JENNY
** Login   <maxime.jenny@epitech.eu>
**
** Started on  Mon Jan  2 17:25:22 2017 Maxime JENNY
** Last update Wed Jan  4 14:25:37 2017 Maxime JENNY
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

void		shadows(t_raycast *ray, sfVector2f p, int i,
			t_my_framebuffer *disp)
{
  sfVector2i	from;
  sfVector2i	to;

  from.x = i + 0 * (to.x = i);
  (ray->dist == 0) ? (ray->dist = 1) : (0);
  from.y = HEIGHT / 2 + (HEIGHT / 2 / ray->dist);
  to.y = HEIGHT / 2 - (HEIGHT / 2 / ray->dist);
  if (ray->hor == 1)
    my_draw_line_two(disp, &from, &to, my_create_color(80, 80, 80, 255));
  else
    my_draw_line_two(disp, &from, &to, my_create_color(90, 90, 90, 255));
}
