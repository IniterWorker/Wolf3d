/*
** tekgo.c for  in /home/bonett_w/Wolf3D/src/draw/
**
** Made by walter bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Mon Dec 14 19:13:25 2015 walter bonetti
** Last update Mon Dec 14 21:11:05 2015 walter bonetti
*/

#include <lapin.h>
#include <math.h>

void	tekgo(t_bunny_position 	*curpos,
	      double 		angle,
	      t_bunny_position 	*newpos,
	      int		move)
{
  newpos->x = (double)(curpos->x + cos(angle) * move * 10);
  newpos->y = (double)(curpos->y + sin(angle) * move * 10);
}

void	go(t_bunny_position 	*curpos,
	      double 		angle,
	      t_bunny_position 	*newpos,
	      int		move)
{
  newpos->x = (double)(curpos->x + cos(angle) * move * 10);
  newpos->y = (double)(curpos->y + sin(angle) * move * 10);
}
