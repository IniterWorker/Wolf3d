/*
** raycaster.c for  in /home/bonett_w/raycaster/
**
** Made by walter bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Thu Dec 17 13:44:43 2015 walter bonetti
** Last update Fri Dec 18 12:14:33 2015 walter bonetti
*/

#include "raycasting.h"

t_ray	*ray_new()
{
  t_ray	*ray;

  ray = malloc(sizeof(t_ray));
  if (ray == NULL)
    return (NULL);
  return (ray);
}

void	ray_init(t_ray *ray, t_player *player, int x)
{
  ray->h = HMAX;
  ray->cameraX = 2 * x / (double)(WMAX) - 1;
  ray->pos.x = player->pos.x;
  ray->pos.y = player->pos.y;
  ray->dir.x = player->dir.x + player->plane.x * ray->cameraX;
  ray->dir.y = player->dir.y + player->plane.y * ray->cameraX;
  ray->map.x = (int)(ray->pos.x);
  ray->map.y = (int)(ray->pos.y);
  ray->delta_dist.x = sqrt(1 + (ray->dir.y * ray->dir.y) /
			(ray->dir.x * ray->dir.x));
  ray->delta_dist.y = sqrt(1 + (ray->dir.x * ray->dir.x) /
			      (ray->dir.y * ray->dir.y));
  ray->hit = 0;
}

void	ray_delta_calc(t_ray *ray)
{
  if (ray->dir.x < 0)
    {
      ray->step.x = -1;
      ray->side_dist.x = (ray->pos.x - ray->map.x) * ray->delta_dist.x;
    }
  else
    {
      ray->step.x = 1;
      ray->side_dist.x = (ray->map.x + 1.0 - ray->pos.x) * ray->delta_dist.x;
    }
  if (ray->dir.y < 0)
    {
      ray->step.y = -1;
      ray->side_dist.y = (ray->pos.y - ray->map.y) * ray->delta_dist.y;
    }
  else
    {
      ray->step.y = 1;
      ray->side_dist.y = (ray->map.y + 1.0 - ray->pos.y) * ray->delta_dist.y;
    }
}

void	ray_hit(t_ray *ray, t_map *map)
{
  while (ray->hit == 0)
    {
      if (ray->side_dist.x < ray->side_dist.y)
	{
	  ray->side_dist.x += ray->delta_dist.x;
	  ray->map.x += ray->step.x;
	  ray->side = 0;
	}
      else
	{
	  ray->side_dist.y += ray->delta_dist.y;
	  ray->map.y += ray->step.y;
	  ray->side = 1;
	}
      if (map->tab[ray->map.x][ray->map.y] > 0)
	ray->hit = 1;
    }
}

void	ray_distance_calc(t_ray *ray)
{
  if (ray->side == 0)
    {
      ray->perpWallDist = FABS((ray->map.x - ray->pos.x + (1 - ray->step.x) / 2)
			       / ray->dir.x);
    }
  else
    {
      ray->perpWallDist = FABS((ray->map.y - ray->pos.y + (1 - ray->step.y) / 2)
			       / ray->dir.y);
    }
  ray->lineHeight = ABS((int)(ray->h / ray->perpWallDist));
}
