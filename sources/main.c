/*
** main.c for bistromathique in /home/morty/rendu/Piscine_C_bistromathique/sources
**
** Made by Nicolas Goudal
** Login   <goudal_n@epitech.net>
**
** Started on  Thu Oct 29 18:02:28 2015 Nicolas Goudal
** Last update Thu Oct 29 18:03:04 2015 Nicolas Goudal
*/

#include "the_lib.h"
#include "peg.h"

int		main(int ac, char const *av[])
{
  t_data	*ctrl;
  unsigned int	index;

  index = 0;
  if (!check_av(ac, av)) // recuperer a valeur de sortie
    the_exit(1, "erreur");
  ctrl = init(av);
  printf("%s\n", ctrl->op_base);
  printf("%s\n", ctrl->nbr_base);
  printf("%s\n", ctrl->str);
  printf("%d\n", calc(ope_low(ctrl, &index)));
  return (0);
}
