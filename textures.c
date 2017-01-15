/*
** textures.c for textures and shadows in /home/maxime/delivery/MUL/wolf3d/
**
** Made by Maxime JENNY
** Login   <maxime.jenny@epitech.eu>
**
** Started on  Mon Jan  2 17:25:22 2017 Maxime JENNY
** Last update Sun Jan 15 19:30:46 2017 Maxime JENNY
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

void			draw_textures(t_my_framebuffer *disp, t_wolf *wolf,
				      sfVector2i *from, sfVector2i *to)
{
  int			x[2];
  int			hit[2];
  t_my_framebuffer	*buff;
  sfColor		color;
  int			i;
  float			j;

  x[0] = (wolf->ray->offset * 64) + 0 * (i = to->y - 1);
  x[1] = (wolf->ray->hor == 0) ? (15) : (0);
  hit[1] = (int)wolf->ray->hit_y + 0 * (hit[0] = (int)wolf->ray->hit_x);
  (wolf->map[hit[1]][hit[0]] == 1) ? (buff = wolf->text->buffer3) : (0);
  (wolf->map[hit[1]][hit[0]] == 2) ? (buff = wolf->text->buffer1) : (0);
  (wolf->map[hit[1]][hit[0]] == 'C' || wolf->map[hit[1]][hit[0]] == 'U') ?
      (buff = wolf->text->buffer4) : (0);
  (wolf->map[hit[1]][hit[0]] == 4) ? (buff = wolf->text->buffer5) : (0);
  (wolf->map[hit[1]][hit[0]] == 7) ? (buff = wolf->text->wall) : (0);
  while (++i <= from->y)
    {
      j = ((i - to->y) * 63 / (from->y - to->y) + 1) * buff->width;
      color.r = (int)buff->pixels[(int)roundf((j + x[0]) * 4)];
      color.g = (int)buff->pixels[(int)roundf((j + x[0]) * 4) + 1];
      color.b = (int)buff->pixels[(int)roundf((j + x[0]) * 4) + 2];
      color.a = (int)buff->pixels[(int)roundf((j + x[0]) * 4) + 3] - x[1];
      my_put_pixel(disp, from->x, i, color);
    }
}

void		textures(t_raycast *ray, t_wolf *wolf, t_my_framebuffer *disp,
			 int i)
{
  sfVector2i	*from;
  sfVector2i	*to;

  if ((from = malloc(sizeof(sfVector2i))) == NULL ||
      (to = malloc(sizeof(sfVector2i))) == NULL)
      return ;
  (ray->d == 0) ? (ray->d = 1) : (0);
  ray->d *= 1;
  from->x = i + 0 * (to->x = i) + 0 * (to->y = HEIGHT / 2 - (HEIGHT / 2 /
          ray->d));
  from->y = HEIGHT / 2 + (HEIGHT / 2 / ray->d);
  wolf->ray = ray;
  draw_textures(disp, wolf, from, to);
  free(from);
  free(to);
}

void		draw(t_my_framebuffer *disp, sfVector2i *from, sfVector2i *to,
		     t_raycast *ray)
{
  if (ray->hor == 1 && ray->angle <= 180 && ray->angle >= 0)
    my_draw_line_two(disp, from, to, my_create_color(60, 60, 60, 255));
  else if (ray->hor == 1)
    my_draw_line_two(disp, from, to, my_create_color(100, 100, 100, 255));
  if (ray->hor == 0 && ray->angle > 90 && ray->angle <= 270)
    my_draw_line_two(disp, from, to, my_create_color(80, 80, 80, 255));
  else if (ray->hor == 0)
    my_draw_line_two(disp, from, to, my_create_color(120, 120, 120, 255));
}

void		shadows(t_raycast *ray, t_wolf *wolf, int i,
			t_my_framebuffer *disp)
{
  sfVector2i	*from;
  sfVector2i	*to;

  if ((from = malloc(sizeof(sfVector2i))) == NULL ||
      (to = malloc(sizeof(sfVector2i))) == NULL)
      return ;
  from->x = i + 0 * (to->x = i);
  (ray->d == 0) ? (ray->d = 1) : (0);
  ray->d *= 1.3;
  from->y = HEIGHT / 2 + (HEIGHT / 2 / ray->d);
  to->y = HEIGHT / 2 - (HEIGHT / 2 / ray->d);
  (from->y > HEIGHT) ? (from->y = HEIGHT) : (0);
  (to->y < 0) ? (to->y = 0) : (0);
  ray->angle = fmodf(ray->angle, 360);
  if (!wolf->tog[4])
    draw(disp, from, to, ray);
  else
    textures(ray, wolf, disp, i);
  free(from);
  free(to);
}
