/*
** keyboard.h for  in /home/bonett_w/Wolf3D/include/
**
** Made by walter bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Wed Dec 16 11:07:01 2015 walter bonetti
** Last update Wed Dec 16 11:08:14 2015 walter bonetti
*/

#ifndef KEYBOARD_H_
# define KEYBOARD_H_

# include <lapin.h>
# include "window.h"

t_bunny_response	callback_key(t_bunny_event_state 	state,
				     t_bunny_keysym 		keysym,
				     void 			*_data);
void	window_keyboard(t_window *_win);

#endif /* !KEYBOARD_H_ */
