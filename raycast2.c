/*
** raycast2.c for raycast in /home/maxime/delivery/MUL/wolf3d/
**
** Made by Maxime JENNY
** Login   <maxime.jenny@epitech.eu>
**
** Started on  Wed Jan  4 14:04:31 2017 Maxime JENNY
** Last update Sun Jan 15 18:34:13 2017 Maxime JENNY
*/

#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <wolf.h>

void		my_find_coor(t_ray *a, t_ray *b, float *angle,
				 sfVector2f *pos)
{
  sfVector2f	*p;

  if ((p = malloc(sizeof(sfVector2f))) == NULL)
    return ;
  p->x = (pos->x - ((int)(pos->x)));
  p->y = (pos->y - ((int)(pos->y)));
  (*angle >= 0 && *angle <= 180) ?
      (a->u_y = 1 - p->y) : (a->u_y = -p->y);
  (*angle == 0 || *angle == 180 || *angle == -180) ? (a->u_x = 1000) :
      (a->u_x = a->u_y / tan(*angle * M_PI / 180) * 1);
  (*angle >= 90 && *angle <= 270 || *angle <= -90 && *angle >= -270) ?
      (b->u_x = -p->x) : (b->u_x = 1 - p->x);
  (*angle != 90 && *angle != 270 && *angle != -270) ? (b->u_y =
   b->u_x * tan(*angle * M_PI / 180) * 1) : (b->u_y = 1000);
  a->angle = *angle;
  b->angle = *angle;
  free(p);
}

double		my_find_dist_hori(t_ray *a, sfVector2f *pos, sfVector2i
					*mapSize, int **map)
{
  sfVector2f	*distA;
  double	dist;
  float		lol;

  if ((distA = malloc(sizeof(sfVector2f))) == NULL)
    return (-1);
  (a->u_y < 0) ? (distA->y = -1) : (distA->y = 1);
  distA->x = distA->y / tan(a->angle * M_PI / 180);
  lol = distA->y * 0.1;
  while ((int)(pos->y + a->u_y + lol) < mapSize->y && (int)(a->u_x + pos->x) <
	 mapSize->x && (int)(pos->y + a->u_y + lol) > 0 &&
	 (int)(a->u_x + pos->x) > 0 &&
	 (map[(int)(pos->y + a->u_y + lol)][(int)(a->u_x + pos->x)] == 0 ||
	  map[(int)(pos->y + a->u_y + lol)][(int)(a->u_x + pos->x)] == 'O' ||
	  map[(int)(pos->y + a->u_y + lol)][(int)(a->u_x + pos->x)] == 'K'))
    {
      a->u_x += distA->x;
      a->u_y += distA->y;
    }
  dist = sqrt((a->u_x * a->u_x) + (a->u_y * a->u_y));
  a->x = a->u_x + 0 * (a->y = a->u_y);
  a->u_y = pos->y + a->u_y + lol + 0 * (a->u_x = a->u_x + pos->x);
  free(distA);
  return (dist);
}

double		my_find_dist_vertic(t_ray *b, sfVector2f *pos, sfVector2i
					*mapSize, int **map)
{
  sfVector2f	*distB;
  double	dist;
  float		lol;

  if ((distB = malloc(sizeof(sfVector2f))) == NULL)
    return (-1);
  (b->u_x < 0) ? (distB->x = -1) : (distB->x = 1);
  distB->y = distB->x * tan(b->angle * M_PI / 180);
  lol = distB->x * 0.1;
  while ((int)(b->u_y + pos->y) < mapSize->y && (int)(b->u_x + pos->x + lol) <
	 mapSize->x && (int)(b->u_y + pos->y) > 0 &&
	 (int)(b->u_x + pos->x + lol) > 0 &&
	 (map[(int)(b->u_y + pos->y)][(int)(b->u_x + pos->x + lol)] == 0 ||
	 map[(int)(b->u_y + pos->y)][(int)(b->u_x + pos->x + lol)] == 'O' ||
	 map[(int)(b->u_y + pos->y)][(int)(b->u_x + pos->x + lol)] == 'K'))
    {
      b->u_x += distB->x;
      b->u_y += distB->y;
    }
  dist = sqrt((b->u_x * b->u_x) + (b->u_y * b->u_y));
  b->x = b->u_x + 0 * (b->y = b->u_y);
  b->u_x = pos->x + b->u_x + lol + 0 * (b->u_y = pos->y + b->u_y);
  free(distB);
  return (dist);
}

/*
** a = premier point sur les horizontaux | b = premier point sur les verticaux
*/

int		my_find_position_in_block(t_raycast *ray, sfVector2f *pos,
					  float *angle, t_ray *vect)
{
  ray->hit_x = (int)vect->u_x;
  ray->hit_y = (int)vect->u_y;
  if (ray->hor == 1)
    ray->offset = (vect->x + pos->x) - (int)(vect->x + pos->x);
  else
    ray->offset = (vect->y + pos->y) - (int)(vect->y + pos->y);
}

t_raycast	*raycast2(sfVector2f *pos, float *direct, int **map,
			sfVector2i *mapSize)
{
  float		d1;
  float		d2;
  t_ray		*a;
  t_ray		*b;
  t_raycast	*ray;

  if ((ray = malloc(sizeof(t_raycast))) == NULL ||
      (a = malloc(sizeof(t_ray))) == NULL || (b = malloc(sizeof(*b))) == NULL)
    return (NULL);
  (*direct) = fmodf(*direct, 360);
  (*direct < 0) ? (*direct += 360) : (0);
  my_find_coor(a, b, direct, pos);
  d1 = sqrt((a->u_x * a->u_x) + (a->u_y * a->u_y));
  d2 = sqrt((b->u_x * b->u_x) + (b->u_y * b->u_y));
  if (*direct != 0 && *direct != 180)
    d1 = my_find_dist_hori(a, pos, mapSize, map);
  if (*direct != 90 && *direct != 270)
    d2 = my_find_dist_vertic(b, pos, mapSize, map);
  ray->d = ((d1 > d2) ? (d2) : (d1)) + 0 * (ray->hor = ((d1 > d2) ? (0) : (1)));
  my_find_position_in_block(ray, pos, direct, (ray->hor == 1) ? (a) : (b));
  free(a);
  free(b);
  return (ray);
}
