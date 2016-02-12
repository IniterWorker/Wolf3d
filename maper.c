/*
** maper.c for  in /home/bonett_w/Documents/rendu/ini_map_loader/
**
** Made by walter bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Sun Dec 27 14:04:38 2015 walter bonetti
** Last update Sun Dec 27 20:42:46 2015 walter bonetti
*/

#include <stdlib.h>
#include <lapin.h>
#include "include/my.h"
#include "maping.h"

int			load_maps(t_list *list, char *file)
{
  t_bunny_ini_scope	*scope;
  t_bunny_ini		*ini;

  ini = bunny_load_ini(file);
  scope = bunny_ini_first(ini);
  while ((scope = bunny_ini_next(ini, scope)) != NULL)
    list_push(list, new_map(scope));
  return (0);
}

int	put_in_tab(t_bunny_ini_scope 	*scope,
		   t_map 		*map)
{
  unsigned int	i;
  unsigned int	j;
  unsigned int	x;

  j = 0;
  x = 0;
  while (j < map->height)
    {
      i = 0;
      while (i < map->width)
	{
	  map->tab[j][i] =
	      my_getnbr((char *)bunny_ini_scope_get_field(scope, "data", x));
	  i++;
	  x++;
	}
      j++;
    }
  return (0);
}

t_map			*new_map(t_bunny_ini_scope	*scope)
{
  t_map			*map;

  map = malloc(sizeof(t_map));

  map->name = (char *)bunny_ini_scope_get_field(scope, "name", 0);
  map->height = my_getnbr((char *)
			  bunny_ini_scope_get_field(scope, "height", 0));
  map->width = my_getnbr((char *)
			 bunny_ini_scope_get_field(scope, "width", 0));
  map->tab = malloc_2d_array(map->width, map->height);
  map->pl.x = my_getnbr((char *)
		       bunny_ini_scope_get_field(scope, "playerx", 0));
  map->pl.y = my_getnbr((char *)
		       bunny_ini_scope_get_field(scope, "playery", 0));
  put_in_tab(scope, map);
  my_printf("Level name : %s\n", map->name);
  return (map);
}
