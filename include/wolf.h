/*
** wolf.h for wolf in /home/maxime/Programs/Bootstrap/bswolf3d/
**
** Made by Maxime JENNY
** Login   <maxime.jenny@epitech.eu>
**
** Started on  Tue Dec 13 10:05:45 2016 Maxime JENNY
** Last update Mon Dec 26 17:53:06 2016 Maxime JENNY
*/

#ifndef WOLF_H_
# define WOLF_H_

# define SIZE 100
# define WIDTH 1280
# define HEIGHT 720
# define FOV 80
# define SCALE 30

typedef struct		s_ray
{
  double		u_x;
  double		u_y;
  float			hyp;
  float			angle;
}			t_ray;

typedef struct		s_wolf
{
  int			**map;
  char			*buffer;
  int			height;
  int			width;
  float			player_x;
  float			player_y;
  float			angle;
}			t_wolf;

typedef struct		s_my_framebuffer
{
  sfUint8		*pixels;
  int			width;
  int			height;
}			t_my_framebuffer;

int		my_get_number(char *str, int *i);
t_my_framebuffer	*my_framebuffer_create(int width, int height);
void		get_matrice(t_wolf **wolf);
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
void		what_key_is_pressed(sfEvent *event, t_wolf **wolf);
void		my_draw_wolf(t_wolf *wolf, t_my_framebuffer *display);
void		reset_framebuffer(t_my_framebuffer **display, int nbr);
int		is_esc_pressed(sfEvent *event);
sfColor		my_create_color(int r, int g, int b, int a);

#endif /* WOLF_H_ */
