/*
** move.c for  in /home/bonett_w/raycaster/
**
** Made by walter bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Thu Dec 17 19:51:24 2015 walter bonetti
** Last update Sun Dec 27 20:10:06 2015 walter bonetti
*/

#include "raycasting.h"

void		move(t_map *m, t_player *p, int keysym)
{
  double	mspeed;

  mspeed = p->move_speed;
  if (keysym == 73)
    {
      if (m->tab[(int)(p->pos.x + p->dir.x * mspeed)][(int)(p->pos.y)] < 10 &&
	  m->tab[(int)(p->pos.x + p->dir.x * mspeed)][(int)(p->pos.y)] >= 0)
	p->pos.x += p->dir.x * mspeed;
      if (m->tab[(int)(p->pos.x)][(int)(p->pos.y + p->dir.y * mspeed)] < 10 &&
	  m->tab[(int)(p->pos.x)][(int)(p->pos.y + p->dir.y * mspeed)] >= 0)
	p->pos.y += p->dir.y * mspeed;
    }
  if (keysym == 74)
    {
      if (m->tab[(int)(p->pos.x - p->dir.x * mspeed)][(int)(p->pos.y)] < 10 &&
	  m->tab[(int)(p->pos.x)][(int)(p->pos.y + p->dir.y * mspeed)] >= 0)
	p->pos.x -= p->dir.x * mspeed;
      if (m->tab[(int)(p->pos.x)][(int)(p->pos.y - p->dir.y * mspeed)] < 10 &&
	  m->tab[(int)(p->pos.x)][(int)(p->pos.y + p->dir.y * mspeed)] >= 0)
	p->pos.y -= p->dir.y * mspeed;
    }
}

void		rotation(t_player *p, int keysym)
{
  double	speedrot;

  speedrot = p->rot_speed;
  if (keysym == 72)
    {
      p->old_dir_x = p->dir.x;
      p->dir.x = p->dir.x * cos(-speedrot) - p->dir.y * sin(-speedrot);
      p->dir.y = p->old_dir_x * sin(-speedrot) + p->dir.y * cos(-speedrot);
      p->old_plane_x = p->plane.x;
      p->plane.x = p->plane.x * cos(-speedrot) - p->plane.y * sin(-speedrot);
      p->plane.y = p->old_plane_x * sin(-speedrot)
	  + p->plane.y * cos(-speedrot);
    }
  if (keysym == 71)
    {
      p->old_dir_x = p->dir.x;
      p->dir.x = p->dir.x * cos(speedrot) - p->dir.y * sin(speedrot);
      p->dir.y = p->old_dir_x * sin(speedrot) + p->dir.y * cos(speedrot);
      p->old_plane_x = p->plane.x;
      p->plane.x = p->plane.x * cos(speedrot) - p->plane.y * sin(speedrot);
      p->plane.y = p->old_plane_x * sin(speedrot) + p->plane.y * cos(speedrot);
    }
}
