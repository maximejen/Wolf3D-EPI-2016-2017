/*
** my_put_pixel.c for putpixel in /home/maxime/delivery/MUL/bswireframe2/
**
** Made by Maxime JENNY
** Login   <maxime.jenny@epitech.eu@epitech.eu>
**
** Started on  Tue Nov 15 11:09:15 2016 Maxime JENNY
** Last update Wed Dec 21 13:26:45 2016 Maxime JENNY
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include "wolf.h"

void	my_put_pixel(t_my_framebuffer *framebuffer, int x, int y, sfColor color)
{
  if (x < 0 || x > framebuffer->width)
    return ;
  if (y < 0 || y > framebuffer->height)
    return ;
  framebuffer->pixels[(framebuffer->width * y + x) * 4] = (int)color.r;
  framebuffer->pixels[(framebuffer->width * y + x) * 4 + 1] = (int)color.g;
  framebuffer->pixels[(framebuffer->width * y + x) * 4 + 2] = (int)color.b;
  framebuffer->pixels[(framebuffer->width * y + x) * 4 + 3] = (int)color.a;
}
