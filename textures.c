/*
** textures.c for textures and shadows in /home/maxime/delivery/MUL/wolf3d/
**
** Made by Maxime JENNY
** Login   <maxime.jenny@epitech.eu>
**
** Started on  Mon Jan  2 17:25:22 2017 Maxime JENNY
** Last update Thu Jan  5 17:52:06 2017 Maxime JENNY
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
  (ray->d == 0) ? (ray->d = 1) : (0);
  ray->d *= 1.2;
  from.y = HEIGHT / 2 + (HEIGHT / 2 / ray->d);
  to.y = HEIGHT / 2 - (HEIGHT / 2 / ray->d);
  (from.y > HEIGHT) ? (from.y = HEIGHT) : (0);
  (to.y < 0) ? (to.y = 0) : (0);
  ray->angle = fmodf(ray->angle, 360);
  if (ray->hor == 0 && ray->angle <= 180 && ray->angle >= 0)
    my_draw_line_two(disp, &from, &to, my_create_color(60, 60, 60, 255));
  else if (ray->hor == 0)
    my_draw_line_two(disp, &from, &to, my_create_color(100, 100, 100, 255));
  if (ray->hor == 1 && ray->angle > 90 && ray->angle <= 270)
    my_draw_line_two(disp, &from, &to, my_create_color(80, 80, 80, 255));
  else if (ray->hor == 1)
    my_draw_line_two(disp, &from, &to, my_create_color(120, 120, 120, 255));
}
