/*
** wolf.h for wolf in /home/maxime/Programs/Bootstrap/bswolf3d/
**
** Made by Maxime JENNY
** Login   <maxime.jenny@epitech.eu>
**
** Started on  Tue Dec 13 10:05:45 2016 Maxime JENNY
** Last update Sun Jan 15 19:39:36 2017 Maxime JENNY
*/

#ifndef WOLF_H_
# define WOLF_H_

# define SIZE 100
# define WIDTH 1280
# define HEIGHT 720
# define FOV 90
# define SCALE 175
# define CHANGE_ANGLE 2

#include <SFML/Audio.h>

typedef struct		s_my_framebuffer
{
  sfUint8		*pixels;
  int			width;
  int			height;
}			t_my_framebuffer;

typedef struct		s_texture
{
  t_my_framebuffer	*buffer1;
  t_my_framebuffer	*buffer2;
  t_my_framebuffer	*buffer3;
  t_my_framebuffer	*buffer4;
  t_my_framebuffer	*buffer5;
  t_my_framebuffer	*key;
  t_my_framebuffer	*inter;
  t_my_framebuffer	*weapf;
  t_my_framebuffer	*wall;
  t_my_framebuffer	*cp;
  sfTexture		*texture1;
  sfTexture		*texture2;
  sfTexture		*texture3;
  sfTexture		*texture4;
  sfTexture		*texture5;
  sfTexture		*keyt;
  sfTexture		*intert;
  sfTexture		*weapft;
  sfTexture		*wallt;
  sfSprite		*sprite1;
  sfSprite		*sprite2;
  sfSprite		*sprite3;
  sfSprite		*sprite4;
  sfSprite		*sprite5;
  sfSprite		*keys;
  sfSprite		*inters;
  sfSprite		*weapfs;
  sfSprite		*wallss;
}			t_texture;

typedef struct		s_raycast
{
  float			d;
  float			offset;
  int			hor;
  float			angle;
  int			hit_x;
  int			hit_y;
}			t_raycast;

typedef struct		s_ray
{
  double		u_x;
  double		u_y;
  double 		x;
  double		y;
  float			angle;
}			t_ray;

typedef struct		s_reader
{
  unsigned int		offbits;
  int			h;
  int			w;
}			t_reader;

typedef struct		s_wolf
{
  int			**map;
  char			*buffer;
  int			height;
  int			width;
  float			player_x;
  float			player_y;
  float			angle;
  char			tog[5];
  t_texture		*text;
  t_reader		*reader;
  t_raycast		*ray;
  int			keys;
  int			stele;
  int			time;
  float			**key_pos;
  int			nbr_keys;
  sfMusic		*mseize;
  int			nbr_stele;
}			t_wolf;

int		my_get_number(char *str, int *i);
t_my_framebuffer	*my_framebuffer_create(int width, int height);
void		get_matrice(t_wolf *wolf);
void		draw_minimap(int **map, t_my_framebuffer *display,
				int mapSize_x, int mapSize_y);
sfRenderWindow		*open_window(sfRenderWindow *window);
float		raycast(sfVector2f pos, float direction, int **map,
			sfVector2i mapSize);
void		my_put_pixel(t_my_framebuffer *framebuffer, int x, int y,
			     sfColor color);
void		my_draw_line(t_my_framebuffer *framebuffer, sfVector2i from,
			     sfVector2i to, sfColor color);
sfVector2f	move_forward(sfVector2f pos, float direction, float distance);
void		what_key_is_pressed(sfEvent *event, t_wolf *wolf);
void		my_draw_wolf(t_wolf *wolf, t_my_framebuffer *display,
			     sfTexture *);
void		reset_framebuffer(t_my_framebuffer **display, int nbr);
int		is_esc_pressed(sfEvent *event);
sfColor		my_create_color(int r, int g, int b, int a);
void	my_draw_line_two(t_my_framebuffer *framebuffer, sfVector2i *from,
			     sfVector2i *to, sfColor color);
sfVector2i	*my_create_vector(int x, int y);
void	my_draw_square(t_my_framebuffer *display, sfVector2i from,
		       sfVector2i size, sfColor color);
void		my_set_player_pos(t_wolf *wolf);
void		shadows(t_raycast *ray, t_wolf *wolf, int i,
			t_my_framebuffer *display);
t_raycast	*raycast2(sfVector2f *pos, float *direction, int **map,
			  sfVector2i *mapSize);
sfVector2f	move_forward2(sfVector2f pos, float direction, float distance,
			      int **map);
void	my_draw_line2(t_my_framebuffer *framebuffer, sfVector2i *from,
		      sfVector2i *to, sfColor color);
int		load_textures(t_wolf *wolf);
char	**my_str_to_wordtab(char *str);
char		*my_strcat(char *dest, char *src);
int	my_strlen(char *str);
char    *my_strdup(char *src);
int		load(t_wolf *wolf, char **paths, t_reader *rder);
int		create_buffers(t_wolf *wolf, t_reader *reader);
void		my_move_mouse(sfRenderWindow *window, t_wolf *wolf);
void		put_in_good_buffer2(t_wolf *wolf, int i, unsigned char tab[],
				   sfVector2i *pos);
void		create_sprites_n_textures2(t_wolf *wolf, t_reader *reader);
void		set(t_wolf *wolf, t_reader *reader);
void	draw_sprites(sfTexture *texture, sfSprite *sprite, t_wolf *wolf,
		     sfRenderWindow *window);
int		set_object_pos(t_wolf *wolf);
void	my_free(t_wolf *wolf, sfRenderWindow *window, sfSprite *sprite,
		sfTexture *text);
void	my_load_music(t_wolf *wolf);
sfVector2i	cal_pos(t_my_framebuffer *obj, float angle, sfVector2i height);
void			draw_textu(sfVector2i dim, sfVector2i pos,
				     t_my_framebuffer *display,
				     t_my_framebuffer *obj);
void		draw_objects(t_my_framebuffer *display, t_wolf *wolf);
void		cp_frambuffer(t_my_framebuffer *one, t_my_framebuffer *two);
void	find_and_kill_key(int y, int x, t_wolf *wolf);
int		can_do_it(t_wolf *wolf, sfVector2f key, float angle);
void		check_wall(t_wolf *wolf, sfVector2f door);

#endif /* WOLF_H_ */
