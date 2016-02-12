/*
** push.c for  in /home/bonett_w/rendu/PSU_2015_my_ls/list
** 
** Made by walter bonetti
** Login   <bonett_w@epitech.net>
** 
** Started on  Wed Nov 25 14:39:36 2015 walter bonetti
** Last update Wed Nov 25 15:35:04 2015 walter bonetti
*/

#include "list.h"

void    list_push_node(t_list *list, t_node *node)
{
  node->next = NULL;
  node->prev = NULL;
  if (!list->first && !list->last)
    {
      list->first = node;
      list->last = node;
    }
  else
    {
      list->last->next = node;
      node->prev = list->last;
      list->last = node;
    }
  list->count++;
}

void		list_push(t_list *list, void *data)
{
  t_node	*node;

  node = node_new();
  node->data = data;
  list_push_node(list, node);
}
