/*
** the_read.c for bistromathique in /home/morty/rendu/Piscine_C_bistromathique/lib/sources
**
** Made by Nicolas Goudal
** Login   <goudal_n@epitech.net>
**
** Started on  Thu Oct 29 20:35:24 2015 Nicolas Goudal
** Last update Thu Oct 29 20:36:01 2015 Nicolas Goudal
*/

#include <unistd.h>
#include "the_lib.h"

ssize_t		the_read(int fd, void *buf, size_t count)
{
  ssize_t	rd;

  rd = read(fd, buf, count);
  if (rd == -1)
    the_exit(2 ,ERR_MSG_READ);
  return (rd);
}
