/*
** load_texture2.c for laod in /home/maxime/delivery/MUL/wolf3d/
**
** Made by Maxime JENNY
** Login   <maxime.jenny@@epitech.eu>
**
** Started on  Fri Jan  6 15:01:41 2017 Maxime JENNY
** Last update Sun Jan 15 19:25:22 2017 Maxime JENNY
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
#include <string.h>

#include "wolf.h"

int		read_bfHeader(int fd, t_reader *reader)
{
  char		*buffer;

  if ((buffer = malloc(54)) == NULL)
    return (-1);
  if ((read(fd, buffer, 10)) == -1)
    return (-1);
  if ((read(fd, &(reader->offbits), 4)) == -1)
    return (-1);
  free(buffer);
  return (0);
}

int		read_biHeader(int fd, t_reader *reader)
{
  char		*buffer;
  unsigned char	lel;

  if ((buffer = malloc(reader->offbits - 26)) == NULL)
    return (-1);
  if ((read(fd, buffer, 4)) == -1)
    return (-1);
  if ((read(fd, &(reader->w), 4)) == -1)
    return (-1);
  if ((read(fd, &(reader->h), 4)) == -1)
    return (-1);
  if (read(fd, buffer, reader->offbits - 26) == -1)
    return (-1);
  free(buffer);
  return (0);
}

/*
** un bmp contient ses couleur dans l'ordre suivant :
**
** alpha | blue | green | red
**
** je veux obtenir l'ordre suivant :
**
** red | green | blue | alpha
*/

void		put_in_good_buffer(t_wolf *wolf, int i, unsigned char tab[],
				   sfVector2i *pos)
{
  if (i == 0)
    {
      my_put_pixel(wolf->text->buffer1, pos->x, pos->y,
		   my_create_color(tab[3], tab[2], tab[1], tab[0]));
    }
  else if (i == 1)
    {
      my_put_pixel(wolf->text->buffer2, pos->x, pos->y,
		   my_create_color(tab[3], tab[2], tab[1], tab[0]));
    }
  else if (i == 2)
    {
      my_put_pixel(wolf->text->buffer3, pos->x, pos->y,
		   my_create_color(tab[3], tab[2], tab[1], tab[0]));
    }
  else if (i == 3)
    {
      my_put_pixel(wolf->text->buffer4, pos->x, pos->y,
		   my_create_color(tab[3], tab[2], tab[1], tab[0]));
    }
  else if (i == 4)
    my_put_pixel(wolf->text->buffer5, pos->x, pos->y,
		 my_create_color(tab[3], tab[2], tab[1], tab[0]));
    else
	put_in_good_buffer2(wolf, i, tab, pos);
}

int		read_pixeltab(int fd, t_wolf *wolf, t_reader *reader, int i)
{
  sfVector2i	*pos;
  unsigned char	t[4];

  if ((pos = malloc(sizeof(sfVector2i))) == NULL)
    return (-1);
  pos->y = reader->h;
  while (pos->y >= 0)
    {
      pos->x = 0;
      while (pos->x < reader->w)
	{
	  if ((read(fd, &t[0], 1)) == -1 || (read(fd, &t[1], 1)) == -1 ||
	      (read(fd, &t[2], 1)) == -1 || (read(fd, &t[3], 1)) == -1)
	    return (-1);
	  put_in_good_buffer(wolf, i, t, pos);
	  pos->x++;
	}
      pos->y--;
    }
}

int		load(t_wolf *wolf, char **paths, t_reader *rder)
{
  int		y;
  int		fd;
  int		good;

  y = 0;
  good = 0;
  while (y < 9)
    {
      if ((fd = open(paths[y], O_RDONLY)) == -1)
	return (-1);
      if ((read_bfHeader(fd, rder)) == -1 || (read_biHeader(fd, rder)) == -1)
	return (-1);
      if (good == 0)
	{
	  good = 1;
	  if ((create_buffers(wolf, rder)) == -1)
	    return (-1);
	}
      read_pixeltab(fd, wolf, rder, y);
      y++;
      close(fd);
    }
}
