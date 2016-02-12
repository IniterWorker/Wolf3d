/*
** texture.c for  in /home/bonett_w/rendu/iGraph/gfx_wolf3d/
**
** Made by walter bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Fri Dec 18 16:24:30 2015 walter bonetti
** Last update Fri Dec 25 15:53:42 2015 walter bonetti
*/

#include "raycasting.h"
#include "bmp.h"

int	load_all_textures(t_window *window)
{
  window->texture.wall = bmp_loader("texture/greystone.bmp");
  return (0);
}
