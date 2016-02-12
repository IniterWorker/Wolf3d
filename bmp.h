/*
** bmp.h for  in /home/bonett_w/Documents/rendu/gfx_wolf3d/
**
** Made by walter bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Sun Dec 27 11:24:58 2015 walter bonetti
** Last update Sun Dec 27 11:25:00 2015 walter bonetti
*/

#ifndef BMP_H_
# define BMP_H_

# include <lapin.h>

# define RGBA_C(r, g, b, a) ((a << 24) | (b << 16) | (g << 8) | r)
# define RGBA_G(r, g, b, a) ((r + g + b + a) / 4)

# pragma pack(push, 1)

typedef struct	s_file_header
{
  char		filetype[2];
  unsigned int	filesize;
  short		reserved[2];
  unsigned int	dataoffset;
}		t_file_header;

# pragma pack(pop)

# pragma pack(push, 1)

typedef struct		s_bitmap_header
{
  struct s_file_header	fileheader;
  unsigned int		headersize;
  int			width;
  int			height;
  short			planes;
  short			bitsperpixels;
  unsigned int		compression;
  unsigned int		bitmapsize;
  int			horizontalres;
  int			vertivalres;
  unsigned int		numcolors;
  unsigned int		importantcolos;
}			t_bitmap_header;

typedef struct		s_bgr
{
    unsigned char	blue;
    unsigned char	green;
    unsigned char	red;
    unsigned char	reserved;
}			t_bgr;

# pragma pack(pop)

int	open_bmp(const char *path);
void	bmp_to_pixel(int fd, t_bunny_pixelarray *pix,
		     t_bitmap_header *bitmap);

t_bitmap_header		bmp_header(int fd);
t_bunny_pixelarray	*bmp_loader(const char *path);

#endif /* !BMP_H_ */
