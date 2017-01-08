/*
** load_texture3.c for load in /home/maxime/delivery/MUL/wolf3d/
**
** Made by Maxime JENNY
** Login   <maxime.jenny@@epitech.eu>
**
** Started on  Wed Jan 11 14:48:51 2017 Maxime JENNY
** Last update Sun Jan 15 13:26:57 2017 Maxime JENNY
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

void		put_in_good_buffer2(t_wolf *wolf, int i, unsigned char tab[],
				   sfVector2i *pos)
{
  if (i == 5)
    {
      my_put_pixel(wolf->text->key, pos->x, pos->y,
		   my_create_color(tab[3], tab[2], tab[1], tab[0]));
    }
  else if (i == 6)
    {
      my_put_pixel(wolf->text->inter, pos->x, pos->y,
		   my_create_color(tab[3], tab[2], tab[1], tab[0]));
    }
  else if (i == 7)
    {
      my_put_pixel(wolf->text->weapf, pos->x, pos->y,
		   my_create_color(tab[3], tab[2], tab[1], tab[0]));
    }
}

void		create_sprites_n_textures2(t_wolf *wolf, t_reader *reader)
{
  wolf->text->keyt = sfTexture_create(500, 500);
  wolf->text->intert = sfTexture_create(1280, 720);
  wolf->text->weapft = sfTexture_create(1280, 720);
  wolf->text->keys = sfSprite_create();
  wolf->text->inters = sfSprite_create();
  wolf->text->weapfs = sfSprite_create();
  sfSprite_setTexture(wolf->text->keys, wolf->text->keyt, sfTrue);
  sfSprite_setTexture(wolf->text->inters, wolf->text->intert, sfTrue);
  sfSprite_setTexture(wolf->text->weapfs, wolf->text->weapft, sfTrue);
  sfTexture_updateFromPixels(wolf->text->texture5, wolf->text->buffer5->pixels,
			     64, 64, 0, 0);
  sfTexture_updateFromPixels(wolf->text->keyt, wolf->text->key->pixels,
			     500, 500, 0, 0);
  sfTexture_updateFromPixels(wolf->text->intert, wolf->text->inter->pixels,
			     1280, 720, 0, 0);
  sfTexture_updateFromPixels(wolf->text->weapft, wolf->text->weapf->pixels,
			     1280, 720, 0, 0);
}

void		set(t_wolf *wolf, t_reader *reader)
{
  sfTexture_updateFromPixels(wolf->text->intert, wolf->text->inter->pixels,
			     1280, 720, 0, 0);
  sfTexture_updateFromPixels(wolf->text->weapft, wolf->text->weapf->pixels,
			     1280, 720, 0, 0);
  sfTexture_updateFromPixels(wolf->text->intert, wolf->text->cp->pixels,
			     1280, 720, 0, 0);
}

void		draw_sprites(sfTexture *texture, sfSprite *sprite, t_wolf *wolf,
			     sfRenderWindow *window)
{
  sfRenderWindow_drawSprite(window, sprite, NULL);
  if (wolf->time > 0)
    {
      sfRenderWindow_drawSprite(window, wolf->text->weapfs, NULL);
      wolf->time--;
    }
  else
    sfRenderWindow_drawSprite(window, wolf->text->sprite2, NULL);
  sfTexture_updateFromPixels(wolf->text->intert, wolf->text->inter->pixels,
			     1280, 720, 0, 0);
  sfRenderWindow_drawSprite(window, wolf->text->inters, NULL);
  sfRenderWindow_display(window);
  cp_frambuffer(wolf->text->inter, wolf->text->cp);
}

void	my_load_music(t_wolf *wolf)
{
  wolf->mseize = malloc(sizeof(sfMusic *));
  wolf->mseize = sfMusic_createFromFile("./resources/M16.ogg");
}
