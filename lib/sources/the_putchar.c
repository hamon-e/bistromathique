/*
** the_putchar.c for bistromathique in /home/morty/rendu/Piscine_C_bistromathique/lib/sources
**
** Made by Nicolas Goudal
** Login   <goudal_n@epitech.net>
**
** Started on  Thu Oct 29 20:35:16 2015 Nicolas Goudal
** Last update Thu Oct 29 20:35:42 2015 Nicolas Goudal
*/

#include "the_lib.h"

void	the_putchar(int const fd, char const c)
{
  the_write(fd, &c, 1);
}
