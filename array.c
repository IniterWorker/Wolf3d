/*
** array.c for  in /home/bonett_w/Wolf3D/src/
**
** Made by walter bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Mon Dec 14 18:13:51 2015 walter bonetti
** Last update Wed Dec 16 12:02:32 2015 walter bonetti
*/

#include <stdlib.h>
#include "my.h"

int		malloc_2d_1d(int 		**tab,
			     unsigned int	height,
			     unsigned int	width)
{
  unsigned int	i;

  i = 0;
  while (i < height)
    {
      tab[i] = malloc(sizeof(int) * width);
      if (tab[i] == NULL)
	return (0);
      i++;
    }
  return (1);
}

int	**malloc_int_2d(unsigned int	height,
			unsigned int	width)
{
  int	**tab;

  tab = malloc(sizeof(int *) * height);
  if (tab == NULL)
    {
      my_printf("Error: malloc: 2D array\n");
      return (NULL);
    }
  malloc_2d_1d(tab, height, width);
  return (tab);
}
