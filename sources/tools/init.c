/*
** init.c for bistromathique in /home/morty/rendu/Piscine_C_bistromathique/sources
**
** Made by Nicolas Goudal
** Login   <goudal_n@epitech.net>
**
** Started on  Thu Oct 29 19:22:00 2015 Nicolas Goudal
** Last update Thu Oct 29 20:23:31 2015 Nicolas Goudal
*/

#include <unistd.h>
#include "the_lib.h"
#include "parser.h"

static char	*init_read(size_t size_read)
{
  char		*res;
  ssize_t	rd;

  res = the_malloc(sizeof(char) * (size_read + 1));
  rd = the_read(0, res, size_read);
  if ((size_t)rd != size_read)
    the_exit(1, ERROR_MSG);
  res[rd] = '\0';
  return (res);
}

void		init(t_data *ctrl, char const *argv[])
{
  ctrl->nbr_base = argv[1];
  ctrl->op_base= argv[2];
  ctrl->str = init_read(the_atoi(argv[3]));
}
