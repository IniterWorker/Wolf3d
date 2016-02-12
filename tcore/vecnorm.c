/*
** vecnorm.c for  in /home/bonett_w/Wolf3D/src/
**
** Made by walter bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Mon Dec 14 21:12:21 2015 walter bonetti
** Last update Mon Dec 14 21:12:23 2015 walter bonetti
*/

#include <lapin.h>
#include <math.h>

double		vecnorm(t_bunny_position *coord0,
		t_bunny_position *coord1)
{
  double	norm;

  norm = sqrt(pow((coord1->x - coord0->x), 2)
	      + pow((coord1->y - coord0->y), 2));
  return (norm);
}
