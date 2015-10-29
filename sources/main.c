/*
** main.c for bistromathique in /home/morty/rendu/Piscine_C_bistromathique/sources
**
** Made by Nicolas Goudal
** Login   <goudal_n@epitech.net>
**
** Started on  Thu Oct 29 18:02:28 2015 Nicolas Goudal
** Last update Thu Oct 29 21:38:01 2015 Nicolas Goudal
*/

#include "the_lib.h"
#include "parser.h"

int		main(int argc, char const *argv[])
{
  t_data	ctrl;
  unsigned int	index;
  t_tree	*root;

  index = 0;
  if (!check_argv(argc, argv)) // recuperer a valeur de sortie
    the_exit(1, "error");
  init(&ctrl, argv);
  root = ope_low(&ctrl, &index);
  if (the_strlen(ctrl.str) != index)
    the_exit(1, "error");
  do_inf_op(&ctrl, root);
  return (0);
}
