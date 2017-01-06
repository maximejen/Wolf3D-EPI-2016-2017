/*
** wolf.c for wolf in /home/maxime/delivery/MUL/wolf3d/
**
** Made by Maxime JENNY
** Login   <maxime.jenny@epitech.eu>
**
** Started on  Wed Dec 21 23:25:05 2016 Maxime JENNY
** Last update Fri Jan  6 00:25:46 2017 Maxime JENNY
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <math.h>
#include <stdio.h>
#include "wolf.h"

void		my_draw_ground(t_my_framebuffer *display)
{
  sfVector2i	from;
  sfVector2i	to;
  int		i;
  int		c;

  i = 0;
  c = 75;
  while (i < HEIGHT)
    {
      from.x = 0;
      from.y = HEIGHT / 2 + i;
      to.x = WIDTH;
      to.y = HEIGHT / 2 + i;
      my_draw_line2(display, &from, &to, my_create_color(c, c, c, 255));
      i++;
      (c < 255 & (i % 2) == 0) ? (c++) : (0);
    }
}

void		my_draw_player_in_map(sfVector2f player, float angle,
				      t_my_framebuffer *display, t_wolf *wolf)
{
  sfVector2i	to;
  sfVector2i	from;
  double	dist;
  float		scale;
  float		scale1;

  scale = SCALE / wolf->width;
  scale1 = SCALE / wolf->height;
  from.x = player.x * scale;
  from.y = player.y * scale1;
  from.x = (int)from.x + 0 * (from.y = (int)from.y);
  my_put_pixel(display, player.x * scale, player.y * scale1 + 1, sfRed);
  my_put_pixel(display, player.x * scale + 1, player.y * scale1, sfRed);
  my_put_pixel(display, player.x * scale + 1, player.y * scale1 + 1, sfRed);
  my_put_pixel(display, player.x * scale - 1, player.y * scale1 - 1, sfRed);
  my_put_pixel(display, player.x * scale, player.y * scale1 - 1, sfRed);
  my_put_pixel(display, player.x * scale - 1, player.y * scale1, sfRed);
  my_put_pixel(display, player.x * scale + 1, player.y * scale1 - 1, sfRed);
  my_put_pixel(display, player.x * scale - 1, player.y * scale1 + 1, sfRed);
  my_put_pixel(display, player.x * scale, player.y * scale1, sfRed);
  to.x = wolf->width + 0 * (to.y = wolf->height);
  dist = raycast(player, angle, wolf->map, to);
  to.x = cos(angle * M_PI / 180) * dist * scale + from.x;
  to.y = sin(angle * M_PI / 180) * dist * scale1 + from.y;
  my_draw_line2(display, &from, &to, my_create_color(211, 81, 0, 255));
}

void		my_draw_walls(t_my_framebuffer *display, t_wolf *wolf,
			      sfVector2f player, sfVector2i mapSize)
{
  float		angle;
  double	delt_a;
  float		dist;
  sfVector3f	dist_ang;
  t_raycast	*ray;
  int		i;

  angle = wolf->angle - (FOV / 2) + 0 * (delt_a =
				(float)FOV / (float)WIDTH);
  i = -1;
  while (++i < WIDTH)
    {
      ray = raycast2(&player, &angle, wolf->map, &mapSize);
      if (ray == NULL)
	return ;
      ray->angle = angle;
      if (wolf->tog[1] == 1)
	ray->d = ray->d * cos((angle - wolf->angle) * M_PI / 180);
      shadows(ray, player, i, display);
      angle += delt_a;
    }
}

/*
** tog[0] = sprint | tog[1] = fov | tog[2] = walls | tog[3] = minmap
*/

void		my_draw_sky(t_my_framebuffer *display)
{
  sfVector2i	from;
  sfVector2i	to;
  int		i;
  int		c;

  i = 0;
  c = 255;
  while (i < HEIGHT / 2)
    {
      from.x = 0;
      from.y = i;
      to.x = WIDTH;
      to.y = i;
      my_draw_line2(display, &from, &to, my_create_color(0, 167, 255, c));
      i++;
      (c > 0 & (i % 2) == 0) ? (c--) : (0);
    }
}

void		my_draw_wolf(t_wolf *wolf, t_my_framebuffer *display)
{
  sfVector2f	player;
  sfVector2i	mapSize;

  mapSize.x = wolf->width + 0 * (mapSize.y = wolf->height);
  player.x = wolf->player_x + 0 * (player.y = wolf->player_y);
  my_draw_ground(display);
  my_draw_sky(display);
  (wolf->tog[2] == 0) ? (0) : (my_draw_walls(display, wolf, player, mapSize));
  if (wolf->tog[3] == 1)
    {
      draw_minimap(wolf->map, display, wolf->width, wolf->height);
      my_draw_player_in_map(player, wolf->angle, display, wolf);
    }
}
