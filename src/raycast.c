/*
** raycast.c for raycast in /home/maxime/Programs/Bootstrap/bswolf3d/
**
** Made by Maxime JENNY
** Login   <maxime.jenny@epitech.eu>
**
** Started on  Tue Dec 13 09:46:01 2016 Maxime JENNY
** Last update Fri Dec 23 17:31:30 2016 Maxime JENNY
*/

#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <wolf.h>

void		my_find_coords(t_ray *a, t_ray *b, float angle,
				 sfVector2f pos)
{
  sfVector2f	p;

  p.x = (pos.x - ((int)(pos.x)));
  p.y = (pos.y - ((int)(pos.y)));
  // a->angle = angle;
  // b->angle = angle;
  // if (angle != 0 && angle != 180)
    // {
      (angle >= 0 && angle <= 180) ? (a->u_y = 1 - p.y) : (a->u_y = p.y);
      (angle == 0 || angle == 180) ? (a->u_x = 1000) :
	  (a->u_x = a->u_y / tan(angle * M_PI / 180) * -1);
    // }
  // if (angle != 90 && angle != 270)
    // {
      (angle >= 90 && angle <= 270) ? (b->u_x = p.x) : (b->u_x = 1 - p.x);
      (angle != 90 && angle != 270) ? (b->u_y = b->u_x * tan(angle * M_PI / 180)
       * -1) : (b->u_y = 1000);
    // }
  // a->u_x = a->u_x + pos.x;
  // a->u_y = pos.y + a->u_y;
  // b->u_x = a->u_x + pos.x;
  // b->u_y = pos.y + b->u_y;
}

/*
** a = premier point sur les horizontaux | b = premier point sur les verticaux
*/

float		raycast(sfVector2f pos, float direction, int **map,
			sfVector2i mapSize)
{
  float		dist1;
  float		dist2;
  t_ray		*a;
  t_ray		*b;

  if ((a = malloc(sizeof(a))) == NULL || (b = malloc(sizeof(b))) == NULL)
    return (-1);
  my_find_coords(a, b, direction, pos);
  printf("ax = %f\nay = %f\n", a->u_x, a->u_y);
  printf("bx = %f\nby = %f\n\n", b->u_x, b->u_y);
  dist1 = sqrt((a->u_x * a->u_x) + (a->u_y * a->u_y)); //PA
  dist2 = sqrt((b->u_x * b->u_x) + (b->u_y * b->u_y)); //PB
  // if (direction != 0 && direction != 180)
    // dist1 = my_find_dist_horizontal(a, pos, mapSize, map); // distB
  // if (direction != 90 && direction != 270)
    // dist2 = my_find_dist_vertical(b, pos, mapSize, map); distB
    printf("dist1 = %f\n", dist1);
    printf("dist2 = %f\n", dist2);
  free(a);
  free(b);
  return ((dist1 > dist2) ? (dist2) : (dist1));
}
