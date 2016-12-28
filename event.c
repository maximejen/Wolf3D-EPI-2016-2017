/*
** event.c for event in /home/maxime/delivery/MUL/wolf3d/
**
** Made by Maxime JENNY
** Login   <maxime.jenny@epitech.eu>
**
** Started on  Wed Dec 21 22:46:00 2016 Maxime JENNY
** Last update Wed Dec 28 14:12:45 2016 Maxime JENNY
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdio.h>
#include "wolf.h"

int	is_esc_pressed(sfEvent *event)
{
  if (event->type == sfEvtKeyPressed && event->key.code == sfKeyEscape)
    return (1);
  return (0);
}

void		what_key_is_pressed(sfEvent *event, t_wolf **wolf)
{
  sfVector2f	player;

  player.x = (*wolf)->player_x;
  player.y = (*wolf)->player_y;
  if (event->key.code == sfKeyD || event->key.code == sfKeyRight)
    (*wolf)->angle = (*wolf)->angle + 1;
  else if (event->key.code == sfKeyQ || event->key.code == sfKeyLeft)
    (*wolf)->angle = (*wolf)->angle - 1;
  else if (event->key.code == sfKeyZ)
    player = move_forward(player, (*wolf)->angle, 0.03);
  else if (event->key.code == sfKeyS)
    player = move_forward(player, (*wolf)->angle, -0.03);
  (*wolf)->player_x = player.x;
  (*wolf)->player_y = player.y;
}
