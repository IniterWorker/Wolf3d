/*
** maping.h for  in /home/bonett_w/Documents/rendu/ini_map_loader/
**
** Made by walter bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Sun Dec 27 14:05:46 2015 walter bonetti
** Last update Sun Dec 27 17:49:24 2015 walter bonetti
*/

#ifndef MAPING_H_
# define MAPING_H_

# include "include/list.h"

typedef struct	s_player_data
{
  int		x;
  int		y;
  double	or;
  double	speed;
  double	or_speed;
}		t_player_data;

typedef struct	s_map
{
  char		*name;
  int		**tab;
  unsigned int	width;
  unsigned int	height;
  t_player_data	pl;
}		t_map;

/*
** Mallocation Array
*/

int	**malloc_2d_array(unsigned int 	x,
			  unsigned int 	y);

/*
** Map loader
*/

int	load_maps(t_list *list, char 	*file);
t_map	*new_map(t_bunny_ini_scope	*scope);

#endif /* !MAPING_H_ */
