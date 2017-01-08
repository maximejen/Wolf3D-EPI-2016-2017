/*
** test.c for test in /home/maxime/delivery/MUL/wolf0d/test/
**
** Made by Maxime JENNY
** Login   <maxime.jenny@@epitech.eu>
**
** Started on  Tue Jan 10 10:10:00 0010 Maxime JENNY
** Last update Tue Jan 10 15:40:11 2017 Maxime JENNY
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

int	main(int argc, char **argv)
{
  sfVector2f player;
  t_raycast ray;
  int	**map =
{{1,1,1,1,1,1,1},
{1,0,0,0,0,0,1},
{1,0,0,0,0,0,1},
{1,1,1,1,1,1,1}};

  sfVector2i mapsize;
  mapsize.x = 7;
  mapsize.y = 4;
  player.x = 2.8;
  player.y = 1.9;
  float angle = -90;
  printf("player : x = %f, y = %f\n", player.x, player.y);
  printf("angle = %f\n", angle);
  float dist = raycast(player, angle, map, mapsize);
  printf("valeur de retour du raycast = %f\n", dist);
}
