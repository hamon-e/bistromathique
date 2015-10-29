/*
** do_inf_op.c for bistromathique in /home/morty/rendu/Piscine_C_bistromathique/sources/inf_op
**
** Made by Nicolas Goudal
** Login   <goudal_n@epitech.net>
**
** Started on  Thu Oct 29 21:45:55 2015 Nicolas Goudal
** Last update Thu Oct 29 23:43:23 2015 Nicolas Goudal
*/

#include <stdlib.h>
#include "the_lib.h"
#include "parser.h"
#include "inf_op.h"

int			do_inf_op(t_data *ctrl, t_tree *racine)
{
  static t_op_and_fun	dico[] =
  {
    {OP_ADD_IDX, inf_add},
    {OP_SUB_IDX, inf_sub},
    {OP_MULT_IDX, inf_mult},
    {OP_DIV_IDX, inf_div},
    {OP_MOD_IDX, inf_mod},
    {OP_ERROR_IDX, NULL}
  };

  (void)(dico);
  (void)(ctrl);
  if (!racine)
    the_exit(-3, ERROR_MSG);
  return (42);
}
