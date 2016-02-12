/*
** view.c for  in /home/bonett_w/raycaster/
**
** Made by walter bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Thu Dec 17 13:51:12 2015 walter bonetti
** Last update Sun Dec 27 21:04:59 2015 walter bonetti
*/

#include "raycasting.h"

void		earth_fill(t_bunny_pixelarray *pix, unsigned int color)
{
  unsigned int	i;
  unsigned int	size;

  i = 0;
  size = pix->clipable.clip_height * pix->clipable.clip_width;
  while (i < size)
    {
      if (i >= size / 2)
	color = RGBA_COLOR(0, 0, 0, 255);
      ((unsigned int *)pix->pixels)[i] = color;
      i++;
    }
}

void		color_fill(t_bunny_pixelarray *pix, unsigned int color)
{
  unsigned int	i;
  unsigned int	size;

  i = 0;
  size = pix->clipable.clip_height * pix->clipable.clip_width;
  while (i < size)
    {
      ((unsigned int *)pix->pixels)[i] = color;
      i++;
    }
}

void	verLine(int x, int drawStart,
		int drawEnd, unsigned int color,
		t_bunny_pixelarray *pix)
{
  while (drawStart < drawEnd)
    {
      ((unsigned int *)pix->pixels)
      [drawStart * pix->clipable.clip_width + x] = color;
      drawStart++;
    }
}

void	draw_wall_at_ray(t_bunny_pixelarray 	*screen,
			 t_ray 			*ray,
			 int 			x,
			 t_map 			*map)
{
  int 	drawStart;
  int 	drawEnd;

  drawStart = -ray->lineHeight / 2 + ray->h / 2;
  if (drawStart < 0)
    drawStart = 0;
  drawEnd = ray->lineHeight / 2 + ray->h / 2;
  if (drawEnd >= ray->h)
    drawEnd = ray->h - 1;
  if (map->tab[ray->map.x][ray->map.y] == 10)
    ray->color = RED;
  if (map->tab[ray->map.x][ray->map.y] == 11)
    ray->color = RGBA_COLOR(0, 255, 122, 255);
  if (map->tab[ray->map.x][ray->map.y] == 12)
    ray->color = RGBA_COLOR(0, 122, 255, 255);
  if (map->tab[ray->map.x][ray->map.y] == 13)
    ray->color = RGBA_COLOR(0,29,89, 255);
  if (ray->side == 1)
    {
      ray->color = DARKEN(ray->color, 0.16).full;
    }
  ray->color = DARKEN(ray->color, 0.11).full;
  verLine(x, drawStart, drawEnd, ray->color, screen);
}

void	draw_camera_view(t_ray 			*ray,
			 t_player 		*player,
			 t_bunny_pixelarray 	*screen,
			 t_map 			*map)
{
  int	x;

  x = 0;
  (void) player;
  (void) map;
  (void) screen;
  earth_fill(screen, RGBA_COLOR(10, 0, 122, 255));
  while (x < WMAX)
    {
      ray_init(ray, player, x);
      ray_delta_calc(ray);
      ray_hit(ray, map);
      ray_distance_calc(ray);
      draw_wall_at_ray(screen, ray, x, map);
      x++;
    }
}
