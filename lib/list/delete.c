/*
** delete.c for  in /home/bonett_w/rendu/PSU_2015_my_ls/list
**
** Made by walter bonetti
** Login   <bonett_w@epitech.net>
**
** Started on  Wed Nov 25 14:57:57 2015 walter bonetti
** Last update Tue Dec  1 23:10:39 2015 walter bonetti
*/

#include "list.h"

void		list_delete_p(t_list *list)
{
  while (list->count)
    {
      list_remove(list, L_FIRST(list));
    }
}

void		list_delete_func(t_list *list, void (*ftc)(t_node *_node))
{
  while (list->count)
    {
      (ftc)(L_FIRST(list));
      list_remove(list, L_FIRST(list));
    }
}
