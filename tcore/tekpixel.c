/*
** tekpixel.c for  in /home/bonett_w/Wolf3D/src/draw/
**
** Made by walter bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Mon Dec 14 18:56:35 2015 walter bonetti
** Last update Mon Dec 14 18:57:30 2015 walter bonetti
*/

#include <lapin.h>

void	tekpixel(t_bunny_pixelarray	*pix,
		 t_bunny_position	*pos,
		 t_color		*color)
{
  ((t_color *)(pix->pixels))[(pos->y *
   pix->clipable.clip_width) + pos->x] = *color;
}
