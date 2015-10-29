/*
** main.c for sources in /home/hamon_e/Piscine/Piscine_C_bistromathique/sources
** 
** Made by Benoit Hamon
** Login   <hamon_e@epitech.net>
** 
** Started on  Thu Oct 29 16:17:00 2015 Benoit Hamon
** Last update Thu Oct 29 16:17:00 2015 Benoit Hamon
*/

#include "the_lib.h"
#include "peg.h"

int	main(int ac, char const *av[])
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
