/*
** do_inf_op.c for bistromathique in /home/morty/rendu/Piscine_C_bistromathique/sources/inf_op
**
** Made by Nicolas Goudal
** Login   <goudal_n@epitech.net>
**
** Started on  Thu Oct 29 21:45:55 2015 Nicolas Goudal
** Last update Thu Oct 29 21:47:12 2015 Nicolas Goudal
*/

#include "the_lib.h"
#include "parser.h"
#include "do_inf_op.h"

void			inf_add(t_op_ctr *arg)
{
  (void)arg;
}
void			inf_sub(t_op_ctr *arg)
{
  (void)arg;
}
void			inf_mult(t_op_ctr *arg)
{
  (void)arg;
}
void			inf_div(t_op_ctr *arg)
{
  (void)arg;
}
void			inf_mod(t_op_ctr *arg)
{
  (void)arg;
}

int			do_inf_op(t_data *ctrl, t_tree *racine)
{
  t_op			*op;
  t_nbr			*nbr;
  static t_op_and_fun	dico[] =
  {
    {OP_ADD_IDX, inf_add},
    {OP_SUB_IDX, inf_sub},
    {OP_MULT_IDX, inf_mult},
    {OP_DIV_IDX, inf_div},
    {OP_MOD_IDX, inf_mod},
    {OP_ERROR_IDX, NULL}
  };

  if (!racine)
    the_exit(4, "error lol\n");
  nbr = (t_nbr *)racine->data;
  return (the_atoi(nbr->nbr) * racine->sign);
}
