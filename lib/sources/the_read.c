/*
** the_read.c for Bistromathique in /home/morty/rendu/Piscine_C_bistromathique/lib/sources
**
** Made by Nicolas Goudal
** Login   <goudal_n@epitech.net>
**
** Started on  Thu Oct 29 02:41:37 2015 Nicolas Goudal
** Last update Thu Oct 29 02:41:57 2015 Nicolas Goudal
*/

#include <unistd.h>
#include "the_lib.h"

ssize_t		safe_read(int fd, void *buf, size_t count)
{
  ssize_t	rd;

  rd = read(fd, buf, count);
  if (rd == -1)
    the_exit(2 ,ERR_MSG_READ);
  return (rd);
}