/*
** list.c for  in /home/bonett_w/rendu/PSU_2015_my_ls/list
**
** Made by walter bonetti
** Login   <bonett_w@epitech.net>
**
** Started on  Wed Nov 25 14:07:38 2015 walter bonetti
** Last update Tue Dec  8 21:04:27 2015 walter bonetti
*/

#include "list.h"

t_list		*list_new()
{
  t_list	*new;

  new = malloc(sizeof(t_list));
  if (!new)
    {
      write(1, STR_ERROR_MALLOC, 24);
      return (NULL);
    }
  new->first = NULL;
  new->last = NULL;
  new->count = 0;
  return (new);
}

t_node		*node_new()
{
  t_node	*new;

  new = malloc(sizeof(t_node));
  if (!new)
    {
      write(1, STR_ERROR_MALLOC, 24);
      return (NULL);
    }
  new->next = NULL;
  new->prev = NULL;
  new->data = NULL;
  return (new);
}

void	node_delete(t_node *node)
{
  free(node);
}

void	list_delete(t_list *list)
{
  free(list);
}
