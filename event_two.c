/*
** event_two.c for event in /home/maxime/delivery/MUL/wolf3d/
**
** Made by Maxime JENNY
** Login   <maxime.jenny@@epitech.eu>
**
** Started on  Sun Jan 15 13:38:13 2017 Maxime JENNY
** Last update Sun Jan 15 19:39:24 2017 Maxime JENNY
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <SFML/Audio.h>
#include "wolf.h"

void	find_and_kill_key(int y, int x, t_wolf *wolf)
{
  int	i;

  i = 0;
  while (i < wolf->nbr_keys && wolf->key_pos[i][0] - 0.5 != x &&
	 wolf->key_pos[i][1] - 0.5 != y)
    {
      i++;
    }
  if (wolf->key_pos[i][0] - 0.5 == x && wolf->key_pos[i][1] - 0.5 == y)
    {
      wolf->key_pos[i][0] = 0;
      wolf->key_pos[i][1] = 0;
    }
}

void		check_wall(t_wolf *wolf, sfVector2f door)
{
  if (wolf->map[(int)(door.y)][(int)(door.x)] == 2)
    {
      wolf->map[(int)(door.y)][(int)(door.x)] = 7;
      wolf->stele += 1;
    }
}

int		can_do_it(t_wolf *wolf, sfVector2f key, float angle)
{
  sfVector2i	mapSize;
  sfVector2f	player;
  sfVector2f	dist;
  t_raycast	*ray;

  mapSize.x = wolf->width;
  mapSize.y = wolf->height;
  player.x = wolf->player_x;
  player.y = wolf->player_y;
  dist.x = key.x - 0.5;
  dist.y = key.y - 0.5;
  angle = angle * 180 / M_PI;
  ray = raycast2(&player, &angle, wolf->map, &mapSize);
  if ((ray->d) < sqrt((dist.x * dist.x) + (dist.y * dist.y)))
    {
      free(ray);
      return (0);
    }
  free(ray);
  return (1);
}
