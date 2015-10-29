/*
** the_putnbr.c for bistromathique in /home/morty/rendu/Piscine_C_bistromathique/lib/sources
**
** Made by Nicolas Goudal
** Login   <goudal_n@epitech.net>
**
** Started on  Thu Oct 29 20:35:18 2015 Nicolas Goudal
** Last update Thu Oct 29 20:35:58 2015 Nicolas Goudal
*/

#include <limits.h>
#include "the_lib.h"

void		the_putnbr(int const fd, int nb)
{
  int		mem;

  mem = nb == INT_MIN ? 1 : 0;
  if (nb < 0)
    the_putchar(fd, '-');
  if (nb < 0)
    nb = nb == INT_MIN ? INT_MAX : -nb;
  if (nb >= 10)
    the_putnbr(fd, nb / 10);
  if (nb == INT_MAX && mem)
    the_putchar(fd, nb % 10 + '1');
  else
    the_putchar(fd, nb % 10 + '0');
}
