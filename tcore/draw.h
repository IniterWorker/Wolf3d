/*
** draw.h for  in /home/bonett_w/Wolf3D/include/
**
** Made by walter bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Mon Dec 14 18:57:07 2015 walter bonetti
** Last update Mon Dec 14 20:31:26 2015 walter bonetti
*/

#ifndef DRAW_H_
# define DRAW_H_

# include <lapin.h>

# define RGBA_COLOR(r, g, b, a) ((a << 24) | (b << 16) | (g << 8) | r)
# define SGN(x) ((x < 0) ? -1 : ((x > 0) ? 1 : 0))
# define ABS(x) ((x < 0) ? -x : x)
# define ABSPOS(a, b, out) ((out.x = ABS(a)) == (out.y = ABS(b)) ? 0 : 1)
# define D_RADIAN(angle) ((angle) / 180.0 * M_PI)
# define R_DEGREE(angle) ((angle) * 180.0 / M_PI)

void	tekpixel(t_bunny_pixelarray	*pix,
		 t_bunny_position	*pos,
		 t_color		*color);

void	tekrectangle(t_bunny_pixelarray *pix,
		     t_bunny_position pos,
		     t_bunny_position size,
		     t_color color);

void	tekgo(t_bunny_position 	*curpos,
	      double 		angle,
	      t_bunny_position 	*newpos,
	      int		move);

void	tekfillcolor(t_bunny_pixelarray 	*pix,
		     t_color			color);

void	tekline(t_bunny_pixelarray	*pix,
		t_bunny_position	*pos,
		t_color			*color);

#endif /* !DRAW_H_ */
