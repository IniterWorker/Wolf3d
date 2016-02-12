/*
** window.h for  in /home/bonett_w/Wolf3D/include/
**
** Made by walter bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Mon Dec 14 15:33:27 2015 walter bonetti
** Last update Mon Dec 14 18:24:15 2015 walter bonetti
*/

#ifndef WINDOW_H_
# define WINDOW_H_

# include <lapin.h>

typedef struct		s_window
{
  t_bunny_window	*window;
  unsigned int		height;
  unsigned int		width;
  unsigned int		middle;
  void			*data;
}			t_window;

t_window	*window_create(unsigned int 	height,
			       unsigned int 	width,
			       const char 	*name);

t_window	*window_init(t_window 	*win,
			     void 	*data);

void	window_delete(t_window *window);

int		view_init();

void	window_keyboard(t_window *_win);

#endif /* !WINDOW_H_ */
