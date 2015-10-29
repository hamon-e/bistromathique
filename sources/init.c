/*
** init.c for before in /home/hamon_e/Piscine/Piscine_C_bistromathique/before
** 
** Made by Benoit Hamon
** Login   <hamon_e@epitech.net>
** 
** Started on  mer. oct. 28 17:14:49 2015 Benoit Hamon
** Last update mer. oct. 28 17:14:49 2015 Benoit Hamon
*/

#include <stdlib.h>
#include "the_lib.h"
#include "peg.h"

static char	*init_read(size_t size_read)
{
  char		*res;
  ssize_t	rd;

  res = the_malloc(sizeof(char) * size_read);
  rd = the_read(0, res, size_read);
  if (rd != size_read)
    the_exit(1, "erreur");
  return (res);
}

t_data		*init(const char *av[])
{
  t_data	*ctrl;

  ctrl = the_malloc(sizeof(t_data));
  ctrl->nbr_base = av[1];
  ctrl->op_base= av[2];
  ctrl->str = init_read(atoi(av[3]));
  return (ctrl);
}
