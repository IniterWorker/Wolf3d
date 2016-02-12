/*
** remove.c for  in /home/bonett_w/rendu/PSU_2015_my_ls/list
**
** Made by walter bonetti
** Login   <bonett_w@epitech.net>
**
** Started on  Wed Nov 25 14:50:56 2015 walter bonetti
** Last update Wed Dec  2 14:47:28 2015 walter bonetti
*/

#include "list.h"

void		list_remove_middle(t_node *node)
{
  t_node	*after;
  t_node	*before;

  after = node->next;
  before = node->prev;
  after->prev = before;
  before->next = after;
}

void	remove_null(t_list *list)
{
  list->first = NULL;
  list->last = NULL;
}

void	remove_first(t_list *list, t_node *node)
{
  if (node == list->first)
    {
      list->first = node->next;
      list->first->prev = NULL;
    }
}

t_node		*list_remove(t_list *list, t_node *node)
{
  t_node	*result;

  result = NULL;
  if (list->count)
    {
      result = (node == list->last) ? node->prev : node->next;
      if (node == list->first && node == list->last)
	remove_null(list);
      else if (node == list->first)
	remove_first(list, node);
      else if (node == list->last)
	{
	  list->last = node->prev;
	  list->last->next = NULL;
	}
      else
	list_remove_middle(node);
      list->count--;
      free(node);
  }
  return (result);
}
