/*
** the_putchar.c for Bistromathique in /home/morty/rendu/Piscine_C_bistromathique/lib/sources
**
** Made by Nicolas Goudal
** Login   <goudal_n@epitech.net>
**
** Started on  Thu Oct 29 02:39:29 2015 Nicolas Goudal
** Last update Thu Oct 29 03:05:55 2015 Nicolas Goudal
*/

#include "the_lib.h"

void	the_putchar(int const fd, char const c)
{
  the_write(fd, &c, 1);
}
