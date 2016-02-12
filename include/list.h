/*
** list.h for  in /home/bonett_w/rendu/PSU_2015_my_ls/list
**
** Made by walter bonetti
** Login   <bonett_w@epitech.net>
**
** Started on  Wed Nov 25 14:08:50 2015 walter bonetti
** Last update Wed Dec  2 14:22:00 2015 walter bonetti
*/

#ifndef LIST_H_
# define LIST_H_

# include <unistd.h>
# include <stdlib.h>

typedef struct	s_node
{
  void		*data;
  struct s_node	*next;
  struct s_node	*prev;
}		t_node;

typedef struct	t_list
{
  unsigned int	count;
  struct s_node	*first;
  struct s_node	*last;
}		t_list;

t_list	*list_new();
t_node	*node_new();

void	list_push(t_list *list, void *data);
void    list_push_node(t_list *list, t_node *node);
void	list_delete(t_list *list);
void	node_swap(t_node *a, t_node *b);
void	node_delete(t_node *node);
void	list_delete_func(t_list *list, void (*ftc)(t_node *_node));
void	list_delete_p(t_list *list);

int	list_tri(t_list *list, int (*fct)(t_node *current, t_node *next));
t_node		*list_remove(t_list *list, t_node *node);
# define N_NEXT(a) a->next
# define N_PREV(a) a->prev
# define L_DATA(a) a->data
# define L_FIRST(a) a->first
# define L_LAST(a) a->last

# define STR_ERROR_MALLOC "error: malloc unstable\n"

#endif /* !LIST_H_ */
