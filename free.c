/*
** free.c for free in /home/maxime/delivery/MUL/wolf3d/
**
** Made by Maxime JENNY
** Login   <maxime.jenny@@epitech.eu>
**
** Started on  Thu Jan 12 18:41:05 2017 Maxime JENNY
** Last update Sun Jan 15 22:44:32 2017 Maxime JENNY
*/

#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>

#include <sys/stat.h>
#include <sys/types.h>

#include <fcntl.h>
#include <math.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

#include "wolf.h"

void	my_destroy(t_wolf *wolf, sfRenderWindow *window, sfSprite *sprite,
		sfTexture *texture)
{
  sfRenderWindow_destroy(window);
  sfSprite_destroy(sprite);
  sfSprite_destroy(wolf->text->sprite1);
  sfSprite_destroy(wolf->text->sprite2);
  sfSprite_destroy(wolf->text->sprite3);
  sfSprite_destroy(wolf->text->sprite4);
  sfSprite_destroy(wolf->text->sprite5);
  sfSprite_destroy(wolf->text->keys);
  sfSprite_destroy(wolf->text->inters);
  sfSprite_destroy(wolf->text->weapfs);
  sfTexture_destroy(wolf->text->texture1);
  sfTexture_destroy(wolf->text->texture2);
  sfTexture_destroy(wolf->text->texture3);
  sfTexture_destroy(wolf->text->texture4);
  sfTexture_destroy(wolf->text->texture5);
  sfTexture_destroy(wolf->text->keyt);
  sfTexture_destroy(wolf->text->intert);
  sfTexture_destroy(wolf->text->weapft);
  sfTexture_destroy(texture);
  sfMusic_destroy(wolf->mseize);
}

void	frite(t_wolf *wolf)
{
  free(wolf->text->buffer1->pixels);
  free(wolf->text->buffer1);
  free(wolf->text->buffer2->pixels);
  free(wolf->text->buffer2);
  free(wolf->text->buffer3->pixels);
  free(wolf->text->buffer3);
  free(wolf->text->buffer4->pixels);
  free(wolf->text->buffer4);
  free(wolf->text->buffer5->pixels);
  free(wolf->text->buffer5);
  free(wolf->text->key->pixels);
  free(wolf->text->key);
  free(wolf->text->inter->pixels);
  free(wolf->text->inter);
  free(wolf->text->weapf->pixels);
  free(wolf->text->weapf);
}

void	my_free(t_wolf *wolf, sfRenderWindow *window, sfSprite *sprite,
		sfTexture *texture)
{
  my_destroy(wolf, window, sprite, texture);
  frite(wolf);
  if (wolf->stele == wolf->nbr_stele)
    {
      write(1, "Congratulations !\nYou Won.\n", 27);
    }
  free(wolf);
}
