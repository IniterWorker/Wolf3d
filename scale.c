/*
** scale.c for  in /home/bonett_w/rendu/iGraph/gfx_wolf3d/
**
** Made by walter bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Fri Dec 18 14:11:52 2015 walter bonetti
** Last update Sun Dec 27 11:24:02 2015 walter bonetti
*/

#include "raycasting.h"

void	tekset(t_bunny_pixelarray 	*pix,
	       int 			x,
	       int			y,
	       unsigned int		color)
{
  ((unsigned int *)pix->pixels)[y * pix->clipable.clip_width + x] = color;
}

unsigned int	tekget(t_bunny_pixelarray 	*pix,
		       int 			x,
		       int			y)
{
  return (((unsigned int *)pix->pixels)[y * pix->clipable.clip_width + x]);
}

void	stretch(t_bunny_pixelarray 		*pix,
		const t_bunny_pixelarray 	*ori)
{
  float	w_ratio;
  float	h_ratio;
  int	i;
  int	j;

  (void) w_ratio;
  (void) h_ratio;
  w_ratio = ori->clipable.clip_width / pix->clipable.clip_width;
  h_ratio = ori->clipable.clip_height / pix->clipable.clip_height;
  j = 0;
  while (j < pix->clipable.clip_height)
    {
      i = 0;
      while (i < pix->clipable.clip_width)
	{
	  tekset(pix, i, j, tekget(pix, (int)i * w_ratio, (int)j * h_ratio));
	  i++;
	}
      j++;
    }
}
