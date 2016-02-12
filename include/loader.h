/*
** loader.h for  in /home/bonett_w/rendu/iGraph/gfx_wolf3d/include/
**
** Made by walter bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Thu Dec 10 17:25:04 2015 walter bonetti
** Last update Sun Dec 13 17:08:55 2015 walter bonetti
*/

#ifndef LOADER_H_
# define LOADER_H_

typedef struct	s_map
{
  char		*name;
  unsigned int	width;
  unsigned int	height;
  int		**tab;
}		t_map;

t_map	*load_map(const char *path,
		  const char *scope);

int	malloc_2d_1d(int 		**tab,
		     unsigned int	height,
		     unsigned int	width);

int	**malloc_int_2d(unsigned int	height,
			unsigned int	width);

void	delete_map(t_map *map);

#endif /* !LOADER_H_ */
