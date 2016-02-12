/*
** node.c for  in /home/bonett_w/rendu/PSU_2015_my_ls/list
** 
** Made by walter bonetti
** Login   <bonett_w@epitech.net>
** 
** Started on  Wed Nov 25 14:22:59 2015 walter bonetti
** Last update Wed Nov 25 14:33:02 2015 walter bonetti
*/

#include "list.h"

void	node_swap(t_node *a,
		  t_node *b)
{
  void	*data;

  data = a->data;
  a->data = b->data;
  b->data = data;
}
