/*
** tableau.c for  in /home/bonett_w/Documents/rendu/ini_map_loader/
**
** Made by walter bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Sun Dec 27 13:54:48 2015 walter bonetti
** Last update Sun Dec 27 16:50:15 2015 walter bonetti
*/

#include <stdlib.h>

int	**malloc_2d_array(unsigned int 	x,
			  unsigned int 	y)
{
  int	**tab;
  unsigned int	i;

  tab = malloc(sizeof(int *) * y);
  if (tab == NULL)
    return (NULL);
  i = 0;
  while (i < y)
    {
      tab[i] = malloc(sizeof(int) * x);
      if (tab[i] == NULL)
	return (NULL);
      i++;
    }
  return (tab);
}
