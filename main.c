/*
** main->c for  in /home/bonett_w/raycaster/
**
** Made by walter bonetti
** Login   <bonett_w@epitech->eu>
**
** Started on  Wed Dec 16 19:53:08 2015 walter bonetti
** Last update Sun Dec 27 22:03:40 2015 walter bonetti
*/

#include <stdio.h>
#include "include/my.h"
#include "raycasting.h"

t_bunny_response	callback_key(t_bunny_event_state 	state,
				     t_bunny_keysym 		keysym,
				     void 			*_data)
{
  t_window		*window;
  t_player		*p;
  t_map			*m;

  window = _data;
  p = window->player;
  m = window->map;
  if (keysym == 36)
    return (0);
  if (keysym == 55 && state == 1)
    player_next_level(window);
  if (keysym == 12 && state == 1)
    {
      window->toggle_minimap = !window->toggle_minimap;
    }
  rotation(p, keysym);
  move(m, p, keysym);
  my_printf("Key : %d\n", keysym);
  return (GO_ON);
}

t_bunny_response	mainloop(void *_data)
{
  t_window		*window;

  window = _data;
  if (window->map->tab[(int)window->player->pos.x][(int)window->player->pos.y]
      == 2)
    player_next_level(window);
  bunny_set_key_response(callback_key);
  color_fill(window->minimap, WHITE);
  draw_camera_view(window->ray,
		   window->player,
		   window->screen,
		   window->map);
  bunny_blit(&window->window->buffer,
	     &window->screen->clipable,
	     &window->pos);
  draw_minimap(window);
  bunny_display(window->window);
  return (GO_ON);
}

int 		main()
{
  t_window	window;

  window.pos.x = 0;
  window.pos.y = 0;
  window.player = player_create();
  window.ray = ray_new();
  window.window = bunny_start_style(WMAX, HMAX,
			    TITLEBAR | CLOSE_BUTTON,
			    "World3d");
  window.screen = bunny_new_pixelarray(WMAX, HMAX);
  window.minimap = bunny_new_pixelarray(200, 200);
  window.toggle_minimap = 0;
  load_all_textures(&window);
  window.list_map = list_new();
  load_maps(window.list_map, "basic_format.ini");
  window.current_map = L_FIRST(window.list_map);
  player_next_level(&window);
  bunny_set_loop_main_function(mainloop);
  bunny_loop(window.window, 60, &window);
  bunny_stop(window.window);
  return (0);
}
