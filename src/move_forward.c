/*
** move_forward.c for move in /home/maxime/Programs/Bootstrap/bswolf3d/
**
** Made by Maxime JENNY
** Login   <maxime.jenny@epitech.eu>
**
** Started on  Tue Dec 13 09:58:01 2016 Maxime JENNY
** Last update Fri Dec 23 17:30:28 2016 Maxime JENNY
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <math.h>

sfVector2f	move_forward(sfVector2f pos, float direction, float distance)
{
  sfVector2f	pos2;
  float		angle;

  angle = direction * M_PI / 180;
  pos2.x = pos.x + cos(angle) * distance;
  pos2.y = pos.y + sin(angle) * distance;
  return (pos2);
}
