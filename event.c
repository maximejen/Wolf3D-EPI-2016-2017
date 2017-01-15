/*
** event.c for event in /home/maxime/delivery/MUL/wolf3d/
**
** Made by Maxime JENNY
** Login   <maxime.jenny@epitech.eu>
**
** Started on  Wed Dec 21 22:46:00 2016 Maxime JENNY
** Last update Sun Jan 15 19:34:34 2017 Maxime JENNY
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <math.h>
#include <SFML/Audio.h>
#include "wolf.h"

sfVector2f	move(sfVector2f *player, t_wolf *wolf, float distance,
		     int straf)
{
  int		y;
  int		x;
  float		angle;

  (straf == 1) ? (angle = wolf->angle) : (angle = wolf->angle + 90);
  (wolf->tog[0] == 1 && straf == 1) ? (distance = distance * 4) : (0);
  (straf != 1) ? (distance /= 2) : (0);
  x = (int)(player->x + cos(angle * M_PI / 180) * distance);
  y = (int)(player->y + sin(angle * M_PI / 180) * distance);
  if (wolf->map[y][x] != 0 && wolf->map[y][x] != 'O' && wolf->map[y][x] != 'K')
    return (*player);
  else
    *player = move_forward(*player, angle, distance);
  return (*player);
}

int	is_esc_pressed(sfEvent *event)
{
  if (event->type == sfEvtKeyPressed && event->key.code == sfKeyEscape)
    return (1);
  return (0);
}

void		door_handling(t_wolf *wolf, sfVector2f p)
{
  sfVector2f	door;
  sfVector2f	key;

 if (sfKeyboard_isKeyPressed(sfKeyE))
    {
      door = move_forward(p, wolf->angle, 1);
      key = move_forward(p, wolf->angle, 0.7);
      if (wolf->map[(int)(door.y)][(int)(door.x)] == 'C')
	{
	  (wolf->keys > 0) ? (wolf->map[(int)door.y][(int)door.x] = 'O') : (0);
	  (wolf->keys > 0) ? (wolf->keys -= 1) : (0);
	}
      else if (wolf->map[(int)(door.y)][(int)(door.x)] == 'O')
	(wolf->map[(int)door.y][(int)door.x] = 'U');
      else if (wolf->map[(int)(door.y)][(int)(door.x)] == 'U')
	(wolf->map[(int)door.y][(int)door.x] = 'O');
      if (wolf->map[(int)(key.y)][(int)(key.x)] == 'K')
	{
	  wolf->map[(int)(key.y)][(int)(key.x)] = 0;
	  find_and_kill_key((int)key.y, (int)key.x, wolf);
	  wolf->keys += 1;
	}
      check_wall(wolf, door);
    }
}

void		what_key_is_press(sfEvent *event, t_wolf *wolf, sfVector2f p)
{
  if (sfKeyboard_isKeyPressed(sfKeyP))
    (wolf->tog[3] == 1) ? (wolf->tog[3] = 0) : (wolf->tog[3] = 1);
  if (sfKeyboard_isKeyPressed(sfKeyO))
    (wolf->tog[4] == 1) ? (wolf->tog[4] = 0) : (wolf->tog[4] = 1);
  if (event->type == sfEvtMouseButtonPressed &&
      event->mouseButton.button == sfMouseLeft && wolf->time == 0)
	{
	  wolf->time = 5;
	  sfMusic_play(wolf->mseize);
	}
  door_handling(wolf, p);
}

/*
** tog[0] = sprint | tog[1] = fov | tog[2] = walls | tog[3] = minmap
*/

void		what_key_is_pressed(sfEvent *event, t_wolf *wolf)
{
  sfVector2f	player;

  player.x = wolf->player_x;
  player.y = wolf->player_y;
  if (sfKeyboard_isKeyPressed(sfKeyRight))
    wolf->angle = wolf->angle + CHANGE_ANGLE;
  else if (sfKeyboard_isKeyPressed(sfKeyLeft))
    wolf->angle = wolf->angle - CHANGE_ANGLE;
  if (sfKeyboard_isKeyPressed(sfKeyF))
    (wolf->tog[1] == 1) ? (wolf->tog[1] = 0) : (wolf->tog[1] = 1);
  if (sfKeyboard_isKeyPressed(sfKeyM))
    (wolf->tog[2] == 1) ? (wolf->tog[2] = 0) : (wolf->tog[2] = 1);
  if (sfKeyboard_isKeyPressed(sfKeyZ))
    player = move(&player, wolf, 0.05, 1);
  else if (sfKeyboard_isKeyPressed(sfKeyS))
    player = move(&player, wolf, -0.05, 1);
  if (sfKeyboard_isKeyPressed(sfKeyD))
    player = move(&player, wolf, 0.05, 0);
  else if (sfKeyboard_isKeyPressed(sfKeyQ))
    player = move(&player, wolf, -0.05, 0);
  if (sfKeyboard_isKeyPressed(sfKeyLControl))
    (wolf->tog[0] == 1) ? (wolf->tog[0] = 0) : (wolf->tog[0] = 1);
  what_key_is_press(event, wolf, player);
  wolf->player_x = player.x;
  wolf->player_y = player.y;
}
