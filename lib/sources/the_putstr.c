/*
** the_putstr.c for bistromathique in /home/morty/rendu/Piscine_C_bistromathique/lib/sources
**
** Made by Nicolas Goudal
** Login   <goudal_n@epitech.net>
**
** Started on  Thu Oct 29 20:35:20 2015 Nicolas Goudal
** Last update Thu Oct 29 20:36:00 2015 Nicolas Goudal
*/

#include "the_lib.h"

void	the_putstr(int const fd, char const *const str)
{
  the_write(fd, str, the_strlen(str));
}
