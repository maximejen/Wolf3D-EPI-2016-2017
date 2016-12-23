/*
** my_str_to_wordtab.c for to word in tab in /home/Maxime/delivery/CPool_Day08/task04
**
** Made by Maxime JENNY
** Login   <Maxime@epitech.net>
**
** Started on  Wed Oct 12 16:43:25 2016 Maxime JENNY
** Last update Tue Dec 13 11:10:08 2016 Maxime JENNY
*/

#include <SFML/Audio/SoundStatus.h>
#include <SFML/System/Vector3.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/Types.h>
#include <SFML/System/InputStream.h>
#include <SFML/System/Time.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <unistd.h>
#include <stdlib.h>

#include "wolf.h"

void		get_matrice(t_wolf **wolf)
{
  int		x;
  int		y;
  int		i;

  i = 0;
  y = 0;
  (*wolf)->map = malloc(sizeof(int *) * ((*wolf)->height));
  while (y < (*wolf)->height)
    {
      x = 0;
      (*wolf)->map[y] = malloc(sizeof(int) * ((*wolf)->width));
      while (x < (*wolf)->width)
	{
	  (*wolf)->map[y][x] = my_get_number((*wolf)->buffer, &i);
	  i++;
	  x++;
	}
      y++;
    }
}
