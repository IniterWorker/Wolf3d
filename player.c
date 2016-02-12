/*
** player.c for  in /home/bonett_w/raycaster/
**
** Made by walter bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Thu Dec 17 13:49:10 2015 walter bonetti
** Last update Sun Dec 27 22:02:13 2015 walter bonetti
*/

#include <stdlib.h>
#include "raycasting.h"
#include "include/my.h"

t_player	*player_create()
{
  t_player	*player;

  player = malloc(sizeof(*player));
  if (player == NULL)
    return (NULL);
  player->pos.x = 1;
  player->pos.y = 1;
  player->dir.x = -1;
  player->dir.y = 0.88;
  player->plane.x = 0.66;
  player->plane.y = 0.66;
  player->rot_speed = 0.2;
  player->move_speed = 0.2;
  return (player);
}

void	player_init_by_map(t_map *map, t_player *player)
{
  player->pos.x = map->pl.x + 0.5;
  player->pos.y = map->pl.y + 0.5;
  player->old_dir_x = map->pl.y + 33;
}

int	player_next_level(t_window *win)
{
  if (win->current_map == NULL)
    return (1);
  win->map = ((t_map *)win->current_map->data);
  my_printf("[Load][Level]\n");
  my_printf("[Level][Name] : %s\n", win->map->name);
  my_printf("[Level][Size] h = %d || w = %d\n",
	    win->map->height, win->map->width);
  player_init_by_map(win->map, win->player);
  win->current_map = N_NEXT(win->current_map);
  return (0);
}
