/*
** load_textures.c for load in /home/maxime/delivery/MUL/wolf3d/
**
** Made by Maxime JENNY
** Login   <maxime.jenny@@epitech.eu>
**
** Started on  Fri Jan  6 12:52:23 2017 Maxime JENNY
** Last update Sun Jan 15 19:26:02 2017 Maxime JENNY
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

void		create_sprites_n_textures(t_wolf *wolf, t_reader *reader)
{
  wolf->text->texture1 = sfTexture_create(reader->w, reader->h);
  wolf->text->texture2 = sfTexture_create(1280, 720);
  wolf->text->texture3 = sfTexture_create(reader->w, reader->h);
  wolf->text->texture4 = sfTexture_create(reader->w, reader->h);
  wolf->text->texture5 = sfTexture_create(reader->w, reader->h);
  wolf->text->sprite1 = sfSprite_create();
  wolf->text->sprite2 = sfSprite_create();
  wolf->text->sprite3 = sfSprite_create();
  wolf->text->sprite4 = sfSprite_create();
  wolf->text->sprite5 = sfSprite_create();
  sfSprite_setTexture(wolf->text->sprite1, wolf->text->texture1, sfTrue);
  sfSprite_setTexture(wolf->text->sprite2, wolf->text->texture2, sfTrue);
  sfSprite_setTexture(wolf->text->sprite3, wolf->text->texture3, sfTrue);
  sfSprite_setTexture(wolf->text->sprite4, wolf->text->texture4, sfTrue);
  sfSprite_setTexture(wolf->text->sprite5, wolf->text->texture5, sfTrue);
  sfTexture_updateFromPixels(wolf->text->texture1, wolf->text->buffer1->pixels,
			     64, 64, 0, 0);
  sfTexture_updateFromPixels(wolf->text->texture2, wolf->text->buffer2->pixels,
			     1280, 720, 0, 0);
  sfTexture_updateFromPixels(wolf->text->texture3, wolf->text->buffer3->pixels,
			     64, 64, 0, 0);
  sfTexture_updateFromPixels(wolf->text->texture4, wolf->text->buffer4->pixels,
			     64, 64, 0, 0);
  create_sprites_n_textures2(wolf, reader);
}

int		create_buffers(t_wolf *wolf, t_reader *reader)
{
  if ((wolf->text->buffer1 = my_framebuffer_create(reader->w,
						   reader->h)) == NULL)
    return (-1);
  if ((wolf->text->buffer2 = my_framebuffer_create(1280, 720)) == NULL)
    return (-1);
  if ((wolf->text->buffer3 = my_framebuffer_create(reader->w,
						   reader->h)) == NULL)
    return (-1);
  if ((wolf->text->buffer4 = my_framebuffer_create(reader->w,
						   reader->h)) == NULL)
    return (-1);
  if ((wolf->text->buffer5 = my_framebuffer_create(reader->w,
						   reader->h)) == NULL)
    return (-1);
  if ((wolf->text->key = my_framebuffer_create(500, 500)) == NULL)
    return (-1);
  if ((wolf->text->inter = my_framebuffer_create(1280, 720)) == NULL)
    return (-1);
  if ((wolf->text->weapf = my_framebuffer_create(1280, 720)) == NULL)
    return (-1);
  if ((wolf->text->cp = my_framebuffer_create(1280, 720)) == NULL)
    return (-1);
  if ((wolf->text->wall = my_framebuffer_create(64, 64)) == NULL)
    return (-1);
  return (0);
}

char		**concat_str(char **paths)
{
  char		*str;
  char		*str2;
  char		*str3;

  if ((str = malloc(45)) == NULL || (str2 = malloc(45)) == NULL)
    return (NULL);
  str = my_strdup("./resources/wall1.bmp ./resources/weapon.bmp");
  str2 = my_strdup(" ./resources/wall3.bmp ./resources/wall4.bmp");
  str[44] = '\0';
  str2[44] = '\0';
  str3 = str2;
  str = my_strcat(str, str2);
  str2 = my_strdup(" ./resources/wall5.bmp ./resources/KEY.bmp");
  str3 = str2;
  str = my_strcat(str, str2);
  str2 = my_strdup(" ./resources/Interface.bmp ./resources/weapon_fire.bmp");
  str3 = str2;
  str = my_strcat(str, str2);
  str2 = my_strdup(" ./resources/3.bmp\0");
  paths = my_str_to_wordtab(my_strcat(str, str2));
  free(str);
  free(str2);
  free(str3);
  return (paths);
}

int		load_textures(t_wolf *wolf)
{
  char		**paths;
  char		*str;
  t_reader	*reader;

  if ((paths = concat_str(paths)) == NULL)
    return (-1);
  if ((reader = malloc(sizeof(t_reader))) == NULL)
    return (-1);
  load(wolf, paths, reader);
  create_sprites_n_textures(wolf, reader);
  sfTexture_updateFromPixels(wolf->text->texture1, wolf->text->buffer1->pixels,
			     64, 64, 0, 0);
  sfTexture_updateFromPixels(wolf->text->texture2, wolf->text->buffer2->pixels,
			     1280, 720, 0, 0);
  sfTexture_updateFromPixels(wolf->text->texture3, wolf->text->buffer3->pixels,
			     64, 64, 0, 0);
  sfTexture_updateFromPixels(wolf->text->texture4, wolf->text->buffer4->pixels,
			     64, 64, 0, 0);
  sfTexture_updateFromPixels(wolf->text->texture5, wolf->text->buffer5->pixels,
			     64, 64, 0, 0);
  sfTexture_updateFromPixels(wolf->text->keyt, wolf->text->key->pixels,
			     500, 500, 0, 0);
  set(wolf, reader);
  wolf->reader = reader;
  return (0);
}
