/*
** the_putnbr.c for Bistromathique in /home/morty/rendu/Piscine_C_bistromathique/lib/sources
**
** Made by Nicolas Goudal
** Login   <goudal_n@epitech.net>
**
** Started on  Thu Oct 29 02:40:08 2015 Nicolas Goudal
** Last update Thu Oct 29 02:40:57 2015 Nicolas Goudal
*/

#include <limits.h>
#include "the_lib.h"

void	the_putnbr(int const fd, int nbr)
{
  if (nbr == INT_MIN)
  {
    the_write(fd, "-2147483648", 11);
    return ;
  }
  if (nbr < 0)
    nbr = -nbr;
  if (nbr >= '9')
    the_putnbr(fd, nbr / 10);
  the_putchar(fd, nbr % 10 + '0');
}
