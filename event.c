/*
** event.c for event in /home/maxime/delivery/MUL/wolf3d/
**
** Made by Maxime JENNY
** Login   <maxime.jenny@epitech.eu>
**
** Started on  Wed Dec 21 22:46:00 2016 Maxime JENNY
** Last update Wed Jan  4 14:39:19 2017 Maxime JENNY
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdio.h>
#include <math.h>
#include "wolf.h"

sfVector2f	move(sfVector2f player, t_wolf *wolf, float distance, int straf)
{
  int		y;
  int		x;
  float		angle;

  (straf == 1) ? (angle = wolf->angle) : (angle = wolf->angle + 90);
  (wolf->tog[0] == 1 && straf == 1) ? (distance = distance * 4) : (0);
  (straf != 1) ? (distance /= 2) : (0);
  x = (int)(player.x + cos(angle * M_PI / 180) * distance);
  y = (int)(player.y + sin(angle * M_PI / 180) * distance);
  if (wolf->map[y][x])
    return (player);
  else
    player = move_forward(player, angle, distance);
  return (player);
}

int	is_esc_pressed(sfEvent *event)
{
  if (event->type == sfEvtKeyPressed && event->key.code == sfKeyEscape)
    return (1);
  return (0);
}

void		what_key_is_pressed2(sfEvent *event, t_wolf **wolf)
{
  if (sfKeyboard_isKeyPressed(sfKeyP))
    ((*wolf)->tog[3] == 1) ? ((*wolf)->tog[3] = 0) : ((*wolf)->tog[3] = 1);
}

/*
** tog[0] = sprint | tog[1] = fov | tog[2] = walls | tog[3] = minmap
*/

void		what_key_is_pressed(sfEvent *event, t_wolf **wolf)
{
  sfVector2f	player;

  player.x = (*wolf)->player_x;
  player.y = (*wolf)->player_y;
  if (sfKeyboard_isKeyPressed(sfKeyRight))
    (*wolf)->angle = (*wolf)->angle + CHANGE_ANGLE;
  if (sfKeyboard_isKeyPressed(sfKeyLeft))
    (*wolf)->angle = (*wolf)->angle - CHANGE_ANGLE;
  if (sfKeyboard_isKeyPressed(sfKeyZ))
    player = move(player, *wolf, 0.05, 1);
  if (sfKeyboard_isKeyPressed(sfKeyS))
    player = move(player, *wolf, -0.05, 1);
  if (sfKeyboard_isKeyPressed(sfKeyD))
    player = move(player, *wolf, 0.05, 0);
  if (sfKeyboard_isKeyPressed(sfKeyQ))
    player = move(player, *wolf, -0.05, 0);
  if (sfKeyboard_isKeyPressed(sfKeyLControl))
    ((*wolf)->tog[0] == 1) ? ((*wolf)->tog[0] = 0) : ((*wolf)->tog[0] = 1);
  if (sfKeyboard_isKeyPressed(sfKeyF))
    ((*wolf)->tog[1] == 1) ? ((*wolf)->tog[1] = 0) : ((*wolf)->tog[1] = 1);
  if (sfKeyboard_isKeyPressed(sfKeyM))
    ((*wolf)->tog[2] == 1) ? ((*wolf)->tog[2] = 0) : ((*wolf)->tog[2] = 1);
  what_key_is_pressed2(event, wolf);
  (*wolf)->player_x = player.x;
  (*wolf)->player_y = player.y;
}
