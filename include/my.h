/*
** my.h for  in /home/bonett_w/my_printf
**
** Made by walter bonetti
** Login   <bonett_w@epitech.net>
**
** Started on  Sun Nov 15 09:37:40 2015 walter bonetti
** Last update Wed Dec 16 12:37:33 2015 walter bonetti
*/

#ifndef MY_H_
# define MY_H_
# include <stdarg.h>

typedef int	(*t_flag)(va_list, char **);
int	my_putchar(char);
int	my_putstr(char *);
int	my_put_nbr(int);
int	my_putnbr_base(int, char *);
int	my_strlen(char *);
int	my_putlong(int nb);
int	my_putlong_base(int nb, char *base);
int	my_putdouble(double nb, int p);
int	my_putunbr_base(unsigned int nbr, char *base);
int	my_putulongnbr_base(unsigned long nbr, char *base);
int	display_char(va_list ap, char **format);
int	display_str(va_list ap, char **format);
int	display_int(va_list ap, char **format);
int	display_str_octal(va_list ap, char **format);
int	display_char_octal(va_list ap, char **format);
int	display_hexa_lower(va_list ap, char **format);
int	display_hexa_upper(va_list ap, char **format);
int	display_hexa_pointer(va_list ap, char **format);
int	display_octal(va_list ap, char **format);
int	display_uint(va_list ap, char **format);
int	display_ubin(va_list ap, char **format);
int	display_double(va_list ap, char **format);
int	display_percent(va_list ap, char **format);
void	print_aff(char **, int *);
int	my_printf(char *format, ...);
int	get_function(va_list ap, char **format, int pos);
int	my_isneg(int nb);
int	my_swap(int *a, int *b);
void	my_sort_int_tab(int *tab, int size);
int	my_power_rec(int nb, int power);
int	my_square_root(int nb);
int	my_is_prime(int nombre);
int	my_find_prime_sup(int nb);
char	*my_strcpy(char *dest, char *src);
char	*my_strncpy(char *dest, char *src, int nb);
char	*my_revstr(char *str);
char	*my_strstr(char *str, char *to_find);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int nb);
char	*my_strupcase(char *str);
char	*my_strlowcase(char *str);
char	*my_strcapitalize(char *str);
int	my_str_isalpha(char *str);
int	my_str_isnum(char *str);
int	my_str_islower(char *str);
int	my_str_isupper(char *str);
int	my_str_isprintable(char *str);
int	my_showstr(char *str);
int	my_showmem(char *str, int size);
char	*my_strcat(char *dest, char *src);
char	*my_strncat(char *dest, char *src, int nb);
int	my_getnbr(char *str);

# define BASE_2 "01"
# define BASE_8 "01234567"
# define BASE_10 "0123456789"
# define BASE_16 "0123456789ABCDEF"
# define BASE_16_LOWER "0123456789abcdef"
# define ERROR_NO_ARG "(null)"
# define ERROR_MALLOC "[Error] malloc : no allocated\n"

#endif /* !MY_H_ */
