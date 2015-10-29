/*
** the_exit.c for bistromathique in /home/morty/rendu/Piscine_C_bistromathique/lib/sources
**
** Made by Nicolas Goudal
** Login   <goudal_n@epitech.net>
**
** Started on  Thu Oct 29 20:35:36 2015 Nicolas Goudal
** Last update Thu Oct 29 20:35:46 2015 Nicolas Goudal
*/

#include <stdlib.h>
#include "the_lib.h"

void	the_exit(int const exit_value, char const *str)
{
  the_putstr(2, str);
  exit(exit_value);
}
