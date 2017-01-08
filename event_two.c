/*
** event_two.c for event in /home/maxime/delivery/MUL/wolf3d/
**
** Made by Maxime JENNY
** Login   <maxime.jenny@@epitech.eu>
**
** Started on  Sun Jan 15 13:38:13 2017 Maxime JENNY
** Last update Sun Jan 15 13:40:35 2017 Maxime JENNY
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <math.h>
#include <SFML/Audio.h>
#include "wolf.h"

void	find_and_kill_key(int y, int x, t_wolf *wolf)
{
  int	i;

  i = 0;
  while (wolf->key_pos[i][0] != x && wolf->key_pos[i][1] != y)
    {
      i++;
    }
  if (wolf->key_pos[i][0] == x && wolf->key_pos[i][1] == y)
    {
      wolf->key_pos[i][0] = 0;
      wolf->key_pos[i][1] = 0;
    }
}
