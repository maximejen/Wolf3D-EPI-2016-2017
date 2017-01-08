/*
** move_mouse.c for move in /home/maxime/delivery/MUL/wolf3d/
**
** Made by Maxime JENNY
** Login   <maxime.jenny@@epitech.eu>
**
** Started on  Wed Jan 11 10:27:19 2017 Maxime JENNY
** Last update Wed Jan 11 16:25:38 2017 Maxime JENNY
*/

#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>

#include <sys/stat.h>
#include <sys/types.h>

#include <fcntl.h>
#include <math.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

#include "wolf.h"

void		my_move_mouse(sfRenderWindow *window, t_wolf *wolf)
{
  sfVector2i	pos;

  pos = sfMouse_getPosition((sfWindow *)window);
  if ((WIDTH / 2) - pos.x != 0)
    {
      wolf->angle -= ((WIDTH / 2) - pos.x) * 0.05;
      pos.x = WIDTH / 2;
      pos.y = HEIGHT / 2;
      sfMouse_setPosition(pos, ((sfWindow *)window));
    }
}
