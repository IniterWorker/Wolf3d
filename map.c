/*
** map.c for  in /home/bonett_w/Documents/rendu/gfx_wolf3d/
**
** Made by walter bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Fri Dec 25 22:18:05 2015 walter bonetti
** Last update Sun Dec 27 21:38:01 2015 walter bonetti
*/

#include "raycasting.h"
#include "include/my.h"

void	draw_rectangle(t_bunny_pixelarray *pix,
		       t_bunny_position pos,
		       t_bunny_position size,
		       unsigned int color)
{
  t_bunny_position	i;
  t_color		col;

  col.full = color;
  i.y = pos.y;
  while (i.y < (pos.y + size.y))
    {
      i.x = pos.x;
      while (i.x < (pos.x + size.x))
	{
	  tekpixel(pix, &i, &col);
	  i.x++;
	}
      i.y++;
    }
}

void		draw_obj_on_minimap(t_window 		*window,
				    t_bunny_position 	size,
				    t_bunny_position	pos,
				    t_bunny_position	i)
{
  t_player	*player;

  player = window->player;
  if ((int)player->pos.y == i.x &&
      (int)player->pos.x == i.y)
    draw_rectangle(window->minimap, pos, size, RED);
  if (window->map->tab[i.y][i.x] > 0 && window->map->tab[i.y][i.x] < 10)
    draw_rectangle(window->minimap, pos, size, BLUE);
}

void			draw_minimap_call(t_window *window)
{
  t_bunny_position	size;
  t_bunny_position	i;
  t_bunny_position	pos;

  size.x = window->minimap->clipable.clip_width / window->map->width;
  size.y = window->minimap->clipable.clip_height / window->map->height;
  i.y = 0;
  while (i.y < (int)window->map->height)
    {
      i.x = 0;
      pos.y = i.y * size.y;
      while (i.x < (int)window->map->width)
	{
	  pos.x = i.x * size.x;
	  if (window->map->tab[i.y][i.x] > 9)
	    draw_rectangle(window->minimap, pos, size, GREEN);
	  draw_obj_on_minimap(window, size, pos, i);
	  i.x++;
	}
      i.y++;
      bunny_blit(&window->window->buffer,
		 &window->minimap->clipable,
		 &window->pos);
    }
}

void	draw_minimap(t_window *window)
{
  if (window->toggle_minimap)
    {
      draw_minimap_call(window);
    }
}
