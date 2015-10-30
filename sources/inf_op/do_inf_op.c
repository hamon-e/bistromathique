/*
** do_inf_op.c for bistromathique in /home/morty/rendu/Piscine_C_bistromathique/sources/inf_op
**
** Made by Nicolas Goudal
** Login   <goudal_n@epitech.net>
**
** Started on  Fri Oct 30 03:56:05 2015 Nicolas Goudal
** Last update Fri Oct 30 06:56:55 2015 Nicolas Goudal
*/

#include "the_lib.h"
#include "parser.h"
#include "inf_op.h"

static t_op_and_fun const	g_dico[5] =
{
  {OP_ADD_IDX, inf_add},
  {OP_SUB_IDX, inf_sub},
  {OP_MULT_IDX, inf_mult},
  {OP_DIV_IDX, inf_div},
  {OP_MOD_IDX, inf_mod},
};

static t_op_nbr		*format_result(t_op_nbr *result, t_sign sign)
{
  int			i;
  char			*tmp;

  i = 0;
  result->sign = (result->nbr[0] == '-' ? MINUS : PLUS) * sign;
  while ((result->nbr[i] == '0' || result->nbr[i] == '-')
	 && result->nbr[i] && result->nbr[i + 1])
    ++i;
  tmp = the_malloc(sizeof(char)
		   * ((result->length = the_strlen(result->nbr + i)) + 1));
  the_strcpy(tmp, result->nbr + i);
  free(result->nbr);
  result->nbr = tmp;
  return (result);
}

t_op_nbr		*do_inf_op(t_data *ctrl, t_tree *root)
{
  int			i;
  t_op_data		calc;

  i = 0;
  if (!root)
    the_exit(-3, ERROR_MSG);
  if (root->type == OPP)
  {
    calc.nbr1 = do_inf_op(ctrl, root->left);
    calc.nbr2 = do_inf_op(ctrl, root->right);
  }
  else
    return (get_op_nbr(ctrl, root));
  while (((t_op *)(root->data))->op != ctrl->op_base[g_dico[i].op])
    ++i;
  g_dico[i].inf_op(&calc);
  return (format_result(calc.result, root->sign));
}
