/*
** main.c for bistromathique in /home/morty/rendu/Piscine_C_bistromathique/sources
**
** Made by Nicolas Goudal
** Login   <goudal_n@epitech.net>
**
** Started on  Thu Oct 29 18:02:28 2015 Nicolas Goudal
** Last update Fri Oct 30 04:05:42 2015 Nicolas Goudal
*/

#include "the_lib.h"
#include "parser.h"
#include "inf_op.h"

/*
** prend un t_op_nbr bien formate et en base 10 et retourne
** une chaine malloc final bien formate, avec le signe,
** dans la base demande et sans \n
*/

int		main(int argc, char const *argv[])
{
  t_data	ctrl;
  unsigned int	index;
  t_tree	*root;
  t_op_nbr	*result;
  char		*final_result;

  index = 0;
  if (!check_argv(argc, argv)) // recuperer a valeur de sortie
    the_exit(1, ERROR_MSG);
  init(&ctrl, argv);
  root = ope_low(&ctrl, &index);
  if (the_strlen(ctrl.str) != index)
    the_exit(1, ERROR_MSG);
  result = do_inf_op(&ctrl, root);
  if (result->sign == MINUS)
    the_putchar(1, '-');
  final_result = get_final_result(result, &ctrl, 0);
  free_tree(root);
  return (0);
}
