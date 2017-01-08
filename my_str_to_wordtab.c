/*
** my_str_to_wordtab.c for to word in tab in /home/Maxime/delivery/CPool_Day08/task04
**
** Made by Maxime JENNY
** Login   <Maxime@epitech.net>
**
** Started on  Wed Oct 12 16:43:25 2016 Maxime JENNY
** Last update Sat Jan  7 21:26:55 2017 Maxime JENNY
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

void		get_matrice(t_wolf *wolf)
{
  int		x;
  int		y;
  int		i;

  i = 0;
  y = 0;
  wolf->map = malloc(sizeof(int *) * (wolf->height));
  while (y < wolf->height)
    {
      x = 0;
      wolf->map[y] = malloc(sizeof(int) * (wolf->width));
      while (x < wolf->width)
	{
	  wolf->map[y][x] = my_get_number(wolf->buffer, &i);
	  i++;
	  x++;
	}
      y++;
    }
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    i++;
  return (i);
}

int	my_word_lengts(char *str, int i)
{
  int	count;

  count = 0;
  while (str[i + count] != ' ' && str[i + count] != 0)
    count += 1;
  return (count);
}

void	my_cut(char *str, char **table, int i, int word)
{
  int	l;

  while (str[i] != '\0')
    {
      l = 0;
      if (str[i] != ' ' && str[i] != '\0')
	{
	  table[word] = malloc(sizeof(char) * (my_word_lengts(str, i) + 1));
	  while (str[i] != ' ' && str[i] != '\0')
	    {
	      table[word][l] = str[i];
	      l = l + 1;
	      i = i + 1;
	    }
	  table[word][l] = '\0';
	  i += 1;
	  word = word + 1;
	}
      else
	i = i + 1;
    }
}

char	**my_str_to_wordtab(char *str)
{
  char	**table;

  table = malloc(sizeof(char) * (my_strlen(str) * 2));
  my_cut(str, table, 0, 0);
  return (table);
}
