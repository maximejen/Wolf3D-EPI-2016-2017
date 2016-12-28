/*
** raycast2.c for raycast in /home/maxime/delivery/MUL/wolf3d/
**
** Made by Maxime JENNY
** Login   <maxime.jenny@epitech.eu>
**
** Started on  Wed Jan  4 14:04:31 2017 Maxime JENNY
** Last update Wed Jan  4 14:27:27 2017 Maxime JENNY
*/

#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <wolf.h>

void		my_find_coords2(t_ray *a, t_ray *b, float angle,
				 sfVector2f pos)
{
  sfVector2f	p;

  p.x = (pos.x - ((int)(pos.x)));
  p.y = (pos.y - ((int)(pos.y)));
  (angle >= 0 && angle <= 180 || angle <= -180 && angle >= -359) ?
      (a->u_y = 1 - p.y) : (a->u_y = -p.y);
  (angle == 0 || angle == 180 || angle == -180) ? (a->u_x = 1000) :
      (a->u_x = a->u_y / tan(angle * M_PI / 180) * 1);
  (angle >= 90 && angle <= 270 || angle <= -90 && angle >= -270) ?
      (b->u_x = - p.x) : (b->u_x = 1 - p.x);
  (angle != 90 && angle != 270 && angle != -270) ? (b->u_y =
   b->u_x * tan(angle * M_PI / 180) * 1) : (b->u_y = 1000);
   a->angle = angle;
   b->angle = angle;
}

double		my_find_dist_horizontal2(t_ray a, sfVector2f pos, sfVector2i
					mapSize, int **map)
{
  sfVector2f	distA;
  double	dist;
  float		lol;

  (a.u_y < 0) ? (distA.y = -1) : (distA.y = 1);
  distA.x = distA.y / tan(a.angle * M_PI / 180);
  lol = distA.y * 0.1;
  while ((int)(pos.y + a.u_y + lol) < mapSize.y && (int)(a.u_x + pos.x) <
	 mapSize.x && (int)(pos.y + a.u_y + lol) > 0 &&
	 (int)(a.u_x + pos.x) > 0 &&
	 map[(int)(pos.y + a.u_y + lol)][(int)(a.u_x + pos.x)] != 1)
    {
      a.u_x += distA.x;
      a.u_y += distA.y;
    }
  dist = sqrt((a.u_x * a.u_x) + (a.u_y * a.u_y));
  return (dist);
}

double		my_find_dist_vertical2(t_ray b, sfVector2f pos, sfVector2i
					mapSize, int **map)
{
  sfVector2f	distB;
  double	dist;
  float		lol;

  (b.u_x < 0) ? (distB.x = -1) : (distB.x = 1);
  distB.y = distB.x * tan(b.angle * M_PI / 180);
  lol = distB.x * 0.1;
  while ((int)(b.u_y + pos.y) < mapSize.y && (int)(b.u_x + pos.x + lol) <
	 mapSize.x && (int)(b.u_y + pos.y) > 0 &&
	 (int)(b.u_x + pos.x + lol) > 0 &&
	 map[(int)(b.u_y + pos.y)][(int)(b.u_x + pos.x + lol)] != 1)
    {
      b.u_x += distB.x;
      b.u_y += distB.y;
    }
  dist = sqrt((b.u_x * b.u_x) + (b.u_y * b.u_y));
  return (dist);
}

/*
** a = premier point sur les horizontaux | b = premier point sur les verticaux
*/

t_raycast	*raycast2(sfVector2f pos, float direction, int **map,
			sfVector2i mapSize)
{
  float		dist1;
  float		dist2;
  t_ray		*a;
  t_ray		*b;
  t_raycast	*ray;

  if ((ray = malloc(sizeof(t_raycast))) == NULL ||
      (a = malloc(sizeof(t_ray))) == NULL || (b = malloc(sizeof(*b))) == NULL)
    return NULL;
  (direction > 360) ? (direction -= 360) : (0);
  (direction < -360) ? (direction += 360) : (0);
  my_find_coords2(a, b, direction, pos);
  dist1 = sqrt((a->u_x * a->u_x) + (a->u_y * a->u_y));
  dist2 = sqrt((b->u_x * b->u_x) + (b->u_y * b->u_y));
  if (direction != 0 && direction != 180 && direction != -180)
    dist1 = my_find_dist_horizontal2(*a, pos, mapSize, map);
  if (direction != 90 && direction != 270)
    dist2 = my_find_dist_vertical2(*b, pos, mapSize, map);
  free(a);
  free(b);
  ray->dist = ((dist1 > dist2) ? (dist2) : (dist1));
  ray->hor = ((dist1 > dist2) ? (0) : (1));
  return (ray);
}
