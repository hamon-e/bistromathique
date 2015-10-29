/*
** the_write.c for Bistromathique in /home/morty/rendu/Piscine_C_bistromathique/lib/sources
**
** Made by Nicolas Goudal
** Login   <goudal_n@epitech.net>
**
** Started on  Thu Oct 29 02:47:41 2015 Nicolas Goudal
** Last update Thu Oct 29 03:06:10 2015 Nicolas Goudal
*/

#include <unistd.h>
#include "the_lib.h"

ssize_t		the_write(int fd, const void *buf, size_t count)
{
  ssize_t	rw;

  rw = write(fd, buf, count);
  if (rw == -1)
    the_exit(3, ERR_MSG_WRITE);
  return (rw);
}
