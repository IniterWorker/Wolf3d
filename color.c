/*
** color.c for  in /home/bonett_w/rendu/iGraph/gfx_wolf3d/
**
** Made by walter bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Fri Dec 18 13:33:43 2015 walter bonetti
** Last update Fri Dec 18 15:47:22 2015 walter bonetti
*/

#include "raycasting.h"

float	lerp(float v1, float v0, float t) {
  return ((1 - t) * v0 + t * v1);
}

t_color		lerp_color(unsigned int color, unsigned int to, float amount)
{
  t_color	_out;
  t_color	_color;
  t_color	_to;

  _to.full = to;
  _color.full = color;
  _out.full = (RGBA_COLOR((int)lerp(_color.argb[0], _to.argb[0], amount),
			  (int)lerp(_color.argb[1], _to.argb[1], amount),
			  (int)lerp(_color.argb[2], _to.argb[2], amount), 255));
  return (_out);
}
