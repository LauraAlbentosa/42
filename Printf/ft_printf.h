#ifdef FT_RPINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>

int ft_putchar(char c);
int ft_putnbr(int n);
int ft_putstr(char *s);
int ft_printf(char const *str, ...);

#endif