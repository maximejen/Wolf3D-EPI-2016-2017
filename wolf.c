/*
** wolf.c for wolf in /home/maxime/delivery/MUL/wolf3d/
**
** Made by Maxime JENNY
** Login   <maxime.jenny@epitech.eu>
**
** Started on  Wed Dec 21 23:25:05 2016 Maxime JENNY
** Last update Fri Dec 23 17:29:40 2016 Maxime JENNY
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <math.h>
#include <stdio.h>
#include "wolf.h"

void		my_draw_player_in_map(sfVector2f player, float angle,
				      t_my_framebuffer *display, t_wolf *wolf)
{
  sfVector2i	to;
  sfVector2i	from;
  double	dist;

  from.x = player.x * SCALE;
  from.y = player.y * SCALE;
  from.x = (int)from.x;
  from.y = (int)from.y;
  my_put_pixel(display, player.x * SCALE, player.y * SCALE + 1, sfRed);
  my_put_pixel(display, player.x * SCALE + 1, player.y * SCALE, sfRed);
  my_put_pixel(display, player.x * SCALE + 1, player.y * SCALE + 1, sfRed);
  my_put_pixel(display, player.x * SCALE - 1, player.y * SCALE - 1, sfRed);
  my_put_pixel(display, player.x * SCALE, player.y * SCALE - 1, sfRed);
  my_put_pixel(display, player.x * SCALE - 1, player.y * SCALE, sfRed);
  my_put_pixel(display, player.x * SCALE + 1, player.y * SCALE - 1, sfRed);
  my_put_pixel(display, player.x * SCALE - 1, player.y * SCALE + 1, sfRed);
  my_put_pixel(display, player.x * SCALE, player.y * SCALE, sfRed);
  dist = raycast(player, angle, wolf->map, to);
  printf("angle = %f\n", angle);
  to.x = cos(angle * M_PI / 180) * dist * SCALE + from.x;
  to.y = sin(angle * M_PI / 180) * dist * SCALE + from.y;
  my_draw_line(display, from, to, sfMagenta);
}

void		my_draw_wolf(t_wolf *wolf, t_my_framebuffer *display)
{
  sfVector2f	player;

  player.x = wolf->player_x;
  player.y = wolf->player_y;
  my_draw_player_in_map(player, wolf->angle, display, wolf);
}
