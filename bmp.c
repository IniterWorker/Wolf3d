/*
** bmp.c for  in /home/bonett_w/Documents/bmploader/
**
** Made by walter bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Mon Dec 21 14:04:52 2015 walter bonetti
** Last update Tue Dec 22 15:16:01 2015 Walter Bonetti
** Last update Tue Dec 22 14:07:10 2015 Michel Mancier
*/

#include <lapin.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include "include/my.h"
#include "bmp.h"

void	tekpixel(t_bunny_pixelarray	*pix,
		 t_bunny_position 	*pos,
		 t_color		*color)
{
  ((t_color *)pix->pixels)[pos->y * pix->clipable.clip_width + pos->x] = *color;
}

t_bunny_pixelarray	*bmp_loader(const char *path)
{
  t_bunny_pixelarray	*img;
  t_bitmap_header	bitmap;
  int			fd;

  fd = open_bmp(path);
  bitmap = bmp_header(fd);
  my_printf("[Image][BMP] load...\n");
  if (bitmap.fileheader.filetype[0] == 'B' &&
      bitmap.fileheader.filetype[1] == 'M')
    {
      img = bunny_new_pixelarray(bitmap.width, bitmap.height);
      if (img != NULL)
	my_printf("[Image][BMP] Ok...\n");
      bmp_to_pixel(fd, img, &bitmap);
    }
  else
    my_printf("[Image][BMP] Error...\n");
  return (img);
}

void	aff_header(t_bitmap_header *b)
{
  my_printf("file type: %c %c\n",
	    b->fileheader.filetype[0],
	    b->fileheader.filetype[1]);
  my_printf("file size: %u\n", b->fileheader.filesize);
  my_printf("reserved: %d %d\n",
	    b->fileheader.reserved[0],
	    b->fileheader.reserved[1]);
  my_printf("dataoffset: %u\n", b->fileheader.dataoffset);
  my_printf("headersize: %u\n", b->headersize);
  my_printf("width: %d\n", b->width);
  my_printf("height: %d\n", b->height);
  my_printf("planes: %d\n", b->planes);
  my_printf("bitsperpixels: %d\n", b->bitsperpixels);
  my_printf("compression: %u\n", b->compression);
  my_printf("bitmapsize: %u\n", b->bitmapsize);
  my_printf("horizontalres: %d\n", b->horizontalres);
  my_printf("vertivalres: %d\n", b->vertivalres);
  my_printf("numColors in palette: %u\n", b->numcolors);
  my_printf("importantcolos: %u\n", b->importantcolos);

}

void		bmp_to_pixel(int 			fd,
			     t_bunny_pixelarray 	*pix,
			     t_bitmap_header 		*bitmap)
{
  t_color	color;
  t_bunny_position	pos;

  pos.y = pix->clipable.clip_height - 1;
  while (pos.y >= 0)
    {
      pos.x = 0;
      while (pos.x < pix->clipable.clip_width)
	{
          read(fd, &color.argb[2], sizeof(unsigned char));
          read(fd, &color.argb[1], sizeof(unsigned char));
          read(fd, &color.argb[0], sizeof(unsigned char));
	  if (bitmap->bitsperpixels == 32)
	    read(fd, &color.argb[3], sizeof(unsigned char));
          tekpixel(pix, &pos, &color);
	  ++pos.x;
	}
      --pos.y;
    }
  aff_header(bitmap);
}

t_bitmap_header		bmp_header(int fd)
{
  t_bitmap_header	header;

  my_printf("[Image][BMP] read header...\n");
  read(fd, &header, sizeof(t_bitmap_header));
  my_printf("Sizeof read: %u\n", sizeof(t_bitmap_header));
  return (header);
}

int	open_bmp(const char *path)
{
  int	fd;

  fd = open(path, O_RDONLY);
  return (fd);
}
