/*
** the_malloc.c for bistromathique in /home/morty/rendu/Piscine_C_bistromathique/lib/sources
**
** Made by Nicolas Goudal
** Login   <goudal_n@epitech.net>
**
** Started on  Thu Oct 29 20:35:38 2015 Nicolas Goudal
** Last update Thu Oct 29 20:35:56 2015 Nicolas Goudal
*/

#include <stdlib.h>
#include "the_lib.h"

void	*the_malloc(size_t size)
{
  void	*res;

  res = malloc(size);
  if (!res)
    the_exit(1, ERR_MSG_MALLOC);
  return (res);
}
