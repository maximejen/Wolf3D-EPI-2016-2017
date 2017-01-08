/*
** my_strcat.c for strcat in /home/maxime/delivery/MUL/wolf3d/
**
** Made by Maxime JENNY
** Login   <maxime.jenny@@epitech.eu>
**
** Started on  Fri Jan  6 13:54:44 2017 Maxime JENNY
** Last update Fri Jan  6 14:21:18 2017 Maxime JENNY
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

char    *my_strdup(char *src)
{
  char  *resp;
  int   count;

  count = 0;
  resp = malloc(sizeof(char) * (my_strlen(src) + 1));
  if (resp == NULL)
    return (NULL);
  while (src[count] != '\0')
    {
      resp[count] = src[count];
      count = count + 1;
    }
  resp[count] = '\0';
  return (resp);
}

char		*my_strcat(char *dest, char *src)
{
  int		i;
  int		m;
  char		*string;

  i = 0 + 0 * (m = 0);
  if ((string = malloc(my_strlen(dest) + my_strlen(src) + 1)) == NULL)
    return (NULL);
  while (dest != NULL && dest[i] != '\0')
    {
      string[i] = dest[i];
      i++;
    }
  while (src[m] != '\0')
    {
      string[i] = src[m];
      i = i + 1;
      m = m + 1;
    }
  string[i] = '\0';
  return (string);
}
