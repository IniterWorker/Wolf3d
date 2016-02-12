/*
** tekline.c for  in /home/bonett_w/Wolf3D/src/draw/
**
** Made by walter bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Mon Dec 14 20:31:00 2015 walter bonetti
** Last update Mon Dec 14 21:11:56 2015 walter bonetti
*/

#include <lapin.h>
#include "draw.h"

static int	set_tab_drawline(t_bunny_position	c[4],
				 t_bunny_position 	p1,
				 t_bunny_position 	p2)
{
  c[0].x = p2.x - p1.x;
  c[0].y = p2.y - p1.y;
  c[1].x = SGN(c[0].x);
  c[1].y = SGN(c[0].y);
  c[0].x = ABS(c[0].x);
  c[0].y = ABS(c[0].y);
  c[2].x = c[0].y >> 1;
  c[2].y = c[0].x >> 1;
  c[3].x = p1.x;
  c[3].y = p1.y;
  return (0);
}

static void	draw_line_octan(t_bunny_pixelarray	*pix,
				t_bunny_position	c[4],
				t_color	        	*color)
{
  int		i;

  i = 0;
  while (i < c[0].x)
    {
      c[2].y = c[2].y + c[0].y;
      if (c[2].y >= c[0].x)
	{
	  c[2].y = c[2].y - c[0].x;
	  c[3].y = c[3].y + c[1].y;
	}
      c[3].x = c[3].x + c[1].x;
      tekpixel(pix, &c[3], color);
      i = i + 1;
    }
}

static void	draw_line_octan_inf(t_bunny_pixelarray	*pix,
				    t_bunny_position	c[4],
				    t_color		*color)
{
  int		i;

  i = 0;
  while (i < c[0].y)
    {
      c[2].x = c[2].x + c[0].x;
      if (c[2].x >= c[0].y)
	{
	  c[2].x = c[2].x - c[0].y;
	  c[3].x = c[3].x + c[1].x;
	}
      c[3].y = c[3].y + c[1].y;
      tekpixel(pix, &c[3], color);
      i = i + 1;
    }
}
void	tekline(t_bunny_pixelarray	*pix,
		t_bunny_position	*pos,
		t_color			*color)
{
  t_bunny_position	c[4];

  set_tab_drawline(c, pos[0], pos[1]);
  tekpixel(pix, &pos[0], color);
  if (c[0].x >= c[0].y)
    draw_line_octan(pix, c, color);
  else
    draw_line_octan_inf(pix, c, color);
}
