/*
** raycasting.h for  in /home/bonett_w/raycaster/
**
** Made by walter bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Thu Dec 17 13:45:21 2015 walter bonetti
** Last update Sun Dec 27 21:31:31 2015 walter bonetti
*/

#ifndef RAYCASTING_H_
# define RAYCASTING_H_

# include <math.h>
# include <lapin.h>
# include <stdlib.h>
# include "maping.h"

# define mapWidth 8
# define mapHeight 6

# define WMAX 1920
# define HMAX 1080

# define ABS(x) ((x < 0) ? -x : x)
# define FABS(x) ((x < 0) ? -x : x)
# define RGBA_COLOR(r, g, b, a) ((a << 24) | (b << 16) | (g << 8) | r)

/*
** Position with Double
*/

typedef struct	s_pos
{
  double	x;
  double	y;
}		t_pos;

/*
** RayCasting
*/

typedef struct			s_ray
{
  int 				hit;
  int 				side;
  int 				lineHeight;
  int				h;
  double 			cameraX;
  double 			perpWallDist;
  unsigned int			color;
  t_pos				pos;
  t_pos				dir;
  t_pos				side_dist;
  t_pos				delta_dist;
  t_bunny_position		step;
  t_bunny_position		map;
}				t_ray;

t_ray	*ray_new();
void	draw_wall_at_ray(t_bunny_pixelarray 	*screen,
			 t_ray 			*ray,
			 int 			x,
			 t_map 			*map);
void	ray_delta_calc(t_ray *ray);
void	ray_hit(t_ray *ray, t_map *map);
void	ray_distance_calc(t_ray *ray);

typedef struct	s_texture
{
  t_bunny_pixelarray	*wall;
  t_bunny_pixelarray	*bang;
}		t_texture;

/*
** PLAYER
*/

typedef struct	s_player
{
  t_pos		pos;
  t_pos		dir;
  t_pos		plane;
  t_pos		old_dir;
  double	old_dir_x;
  double	old_plane_x;
  double	move_speed;
  double	rot_speed;
}		t_player;

t_player	*player_create();
void	player_init_by_map(t_map *map, t_player *player);

/*
** VIEW
*/

void	draw_camera_view(t_ray 			*ray,
			 t_player 		*player,
			 t_bunny_pixelarray 	*screen,
			 t_map 			*map);
void	verLine(int x,
		int drawStart,
		int drawEnd,
		unsigned int color,
		t_bunny_pixelarray *pix);

void	draw_wall_at_ray(t_bunny_pixelarray *screen,
			 t_ray *ray,
			 int x,
			 t_map *map);
void	ray_init(t_ray *ray, t_player *player, int x);

/*
** Window
*/

typedef struct		s_window
{

  t_ray			*ray;
  t_map			*map;
  t_player		*player;
  t_bunny_window	*window;
  t_bunny_position	pos;
  t_bunny_pixelarray	*screen;
  t_bunny_pixelarray	*minimap;
  int			toggle_minimap;
  t_texture		texture;
  t_list		*list_map;
  t_node		*current_map;
}			t_window;

/*
** Function to move
*/

void	move(t_map *m, t_player *p, int keysym);
void	rotation(t_player *p, int keysym);

/*
** Minimap
*/

void	draw_minimap(t_window *window);

/*
** Color Lerp
*/

float	lerp(float start, float end, float amout);
t_color		lerp_color(unsigned int color, unsigned int to, float amount);

# define LIGTHEN(c, p) lerp_color(WHITE, c, p)
# define DARKEN(c, p) lerp_color(BLACK, c, p)

void	earth_fill(t_bunny_pixelarray *pix, unsigned int color);
void	color_fill(t_bunny_pixelarray *pix, unsigned int color);

/*
** Scaling
*/

void	stretch(t_bunny_pixelarray 		*pix,
		const t_bunny_pixelarray 	*ori);

/*
** Texture & Scale
*/

int	load_all_textures(t_window *window);

void	tekpixel(t_bunny_pixelarray	*pix,
		 t_bunny_position 	*pos,
		 t_color		*color);

/*
** Level
*/

int	player_next_level(t_window *win);

#endif /* !RAYCASTING_H_ */
