/*
** tri.c for  in /home/bonett_w/rendu/PSU_2015_my_ls/list
** 
** Made by walter bonetti
** Login   <bonett_w@epitech.net>
** 
** Started on  Wed Nov 25 14:29:39 2015 walter bonetti
** Last update Sat Nov 28 16:41:14 2015 walter bonetti
*/

#include "list.h"

int	list_tri(t_list *list, int (*fct)(t_node *current, t_node *next))
{
  t_node	*_node;
  int		i;

  i = 0;
  _node = list->first;
  while (_node->next)
    {
      if ((fct)(_node, _node->next))
	{
	  i++;
	  node_swap(_node, _node->next);
	}
      _node = _node->next;
    }
  return (i);
}
