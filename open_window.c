/*
** open_window.c for open a window in /home/maxime/delivery/
**
** Made by Maxime JENNY
** Login   <maxime.jenny@epitech.eu@epitech.eu>
**
** Started on  Thu Nov 10 13:07:19 2016 Maxime JENNY
** Last update Fri Dec 23 00:24:56 2016 Maxime JENNY
*/

#include <SFML/Audio/SoundStatus.h>
#include <SFML/System/Vector3.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/Types.h>
#include <SFML/System/InputStream.h>
#include <SFML/System/Time.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "wolf.h"

/*
** width = Largueur de la fenêtre | height = hauteur de la fenêtre
*/

sfRenderWindow		*open_window(sfRenderWindow *window)
{
  sfVideoMode		mode;

  mode.bitsPerPixel = 32;
  mode.width = WIDTH;
  mode.height = HEIGHT;
  window = sfRenderWindow_create(mode, "Wolf3D", sfClose, NULL);
  return (window);
}

t_my_framebuffer	*my_framebuffer_create(int width, int height)
{
  int			i;
  t_my_framebuffer	*display;

  display = malloc(sizeof(t_my_framebuffer));
  display->pixels = malloc(width * height * 4 * sizeof(display->pixels));
  i = 0;
  while (i < width * height * 4)
    {
      display->pixels[i] = 0;
      i++;
    }
  display->width = WIDTH;
  display->height = HEIGHT;
  return (display);
}

void		reset_framebuffer(t_my_framebuffer **display, int nbr)
{
  int		i;

  i = 0;
  while (i < (*display)->width * (*display)->height * 4)
    {
      (*display)->pixels[i] = nbr;
      i++;
    }
}
