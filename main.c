/*
** main.c for main in /home/maxime/Programs/Bootstrap/bswolf3d/
**
** Made by Maxime JENNY
** Login   <maxime.jenny@epitech.eu>
**
** Started on  Tue Dec 13 09:17:17 2016 Maxime JENNY
** Last update Mon Dec 26 16:29:21 2016 Maxime JENNY
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

int	find_size_file(int fd)
{
  int	i;
  int	size;
  char	buf[10];

  i = 1;
  size = 0;
  while (i != 0)
    {
      i = read(fd, buf, 1);
      if (i == -1)
	return (-1);
      size += i;
    }
  close(fd);
  return (size);
}

static void	my_find_wolf(t_wolf **wolf)
{
  int 		i;
  int		g;

  i = 0;
  g = 0;
  (*wolf)->width = 0;
  (*wolf)->height = 0;
  while ((*wolf)->buffer[i] != '\0')
    {
      while ((*wolf)->buffer[i] != '\n')
	{
	  if ((*wolf)->buffer[i] >= '0' && (*wolf)->buffer[i] <= '1' && g != 1)
	    (*wolf)->width += 1;
	  i++;
	}
      if ((*wolf)->buffer[i] == '\n')
	{
	  i++;
	  g = 1;
	  (*wolf)->height += 1;
	}
    }
  (*wolf)->player_x = 1.5;
  (*wolf)->player_y = 1.5;
}

int		my_open_file(int fd, t_wolf **wolf, char *path)
{
  int		rd;
  int		bufsize;
  int		fd2;
  int		buf;

  buf = 0;
  if ((fd2 = open(path, O_RDONLY)) == -1)
    return (-1);
  bufsize = find_size_file(fd2);
  if (((*wolf)->buffer = malloc(bufsize + 1)) == NULL)
    return (-1);
  while ((rd = read(fd, (*wolf)->buffer + buf, bufsize - buf)) > 0)
    buf += rd;
  if (rd == -1)
    return (-1);
  (*wolf)->buffer[bufsize] = '\0';
  my_find_wolf(wolf);
  (*wolf)->angle = 0;
  return (0);
}

static void		window_life(t_wolf **wolf, sfSprite *sprite,
				    sfTexture *texture, sfRenderWindow *window)
{
  t_my_framebuffer	*disp;
  sfEvent		event;

  disp = my_framebuffer_create(WIDTH, HEIGHT);
  sfSprite_setTexture(sprite, texture, sfTrue);
  while (sfRenderWindow_isOpen(window))
    {
      while (sfRenderWindow_pollEvent(window, &event))
	{
	  if (event.type == sfEvtClosed || (is_esc_pressed(&event) == 1))
	    sfRenderWindow_close(window);
	  else if (event.type == sfEvtKeyPressed)
	    what_key_is_pressed(&event, wolf);
	}
      reset_framebuffer(&disp, 0);
      sfRenderWindow_clear(window, my_create_color(0, 167, 255, 255));
      draw_minimap((*wolf)->map, disp, (*wolf)->width, (*wolf)->height);
      my_draw_wolf(*wolf, disp);
      sfTexture_updateFromPixels(texture, disp->pixels, WIDTH, HEIGHT, 0, 0);
      sfRenderWindow_drawSprite(window, sprite, NULL);
      sfRenderWindow_display(window);
    }
  free(disp->pixels);
  free(disp);
}

int			main(int argc, char **argv)
{
  sfRenderWindow	*window;
  sfSprite		*sprite;
  sfVector2i		mapSize;
  sfTexture		*texture;
  int			fd;
  t_wolf		*wolf;

  if (argc >= 2)
    {
      if ((fd = open(argv[1], O_RDONLY)) == -1 || (wolf = malloc(sizeof(
						   t_wolf))) == NULL)
	return (84);
      window = open_window(window);
      texture = sfTexture_create(WIDTH, HEIGHT);
      sprite = sfSprite_create();
      if (my_open_file(fd, &wolf, argv[1]) == -1)
	return (84);
      get_matrice(&wolf);
      window_life(&wolf, sprite, texture, window);
      sfRenderWindow_destroy(window);
      return (0);
    }
  return (84);
}
