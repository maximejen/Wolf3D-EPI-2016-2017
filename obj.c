/*
** obj.c for obj in /home/maxime/delivery/MUL/wolf3d/
**
** Made by Maxime JENNY
** Login   <maxime.jenny@@epitech.eu>
**
** Started on  Wed Jan 11 23:19:59 2017 Maxime JENNY
** Last update Sun Jan 15 19:44:44 2017 Maxime JENNY
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

int		nbr_key(t_wolf *wolf)
{
  int		x;
  int		y;
  int		c;

  y = 0;
  c = 0;
  while (y < wolf->height)
    {
      x = 0;
      while (x < wolf->width)
	{
	  if (wolf->map[y][x] == 'K')
	    c++;
	  x++;
	}
      y++;
    }
  return (c);
}

int		set_object_pos(t_wolf *wolf)
{
  int		x;
  int		y;
  int		i;

  y = -1 + 0 * (i = 0);
  wolf->nbr_keys = nbr_key(wolf);
  if ((wolf->key_pos = malloc(sizeof(float *) * wolf->nbr_keys)) == NULL)
    return (-1);
  while (++y < wolf->height)
    {
      x = -1;
      while (++x < wolf->width)
	{
	  if (wolf->map[y][x] == 'K')
	    {
	      if ((wolf->key_pos[i] = malloc(sizeof(float) * 3)) == NULL)
		return (-1);
	      wolf->key_pos[i][0] = x + 0.5;
              wolf->key_pos[i][1] = y + 0.5 + 0 * (wolf->key_pos[i++][2] = 1);
	    }
	  else if (wolf->map[y][x] == 2)
	    wolf->nbr_stele += 1;
	}
    }
  return (0);
}

sfVector2i	calcs(sfVector2f key, t_my_framebuffer *obj)
{
  sfVector2i	size;
  float		dist;

  dist = sqrt((key.x * key.x) + (key.y * key.y));
  size.x = obj->width / dist;
  size.y = obj->height / dist;
  return (size);
}

void		draw_objects(t_my_framebuffer *display, t_wolf *wolf)
{
  sfVector2f	key;
  sfVector2i	ve;
  float		angle;
  float		angle1;
  int		i;

  i = -1;
  while (++i < wolf->nbr_keys)
    {
      if (wolf->key_pos[i][0] != 0 && wolf->key_pos[i][1] != 0)
	{
	  key.x = wolf->key_pos[i][0] - wolf->player_x;
	  key.y = wolf->key_pos[i][1] - wolf->player_y;
	  angle1 = atan2(key.y, key.x);
	  angle = (float)(angle1 - (wolf->angle * M_PI / 180));
	  ve = calcs(key, wolf->text->key);
	//   if (can_do_it(wolf, key, angle) == 1)
	    draw_textu(ve, (cal_pos(wolf->text->key, angle, ve)),
		       wolf->text->inter, wolf->text->key);
	}
    }
}
