/*
** do_inf_op.c for bistromathique in /home/morty/rendu/Piscine_C_bistromathique/sources/inf_op
**
** Made by Nicolas Goudal
** Login   <goudal_n@epitech.net>
**
** Started on  Thu Oct 29 21:45:55 2015 Nicolas Goudal
** Last update Fri Oct 30 02:41:28 2015 Nicolas Goudal
*/

#include <stdlib.h>
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

/*
** prend root->data->nbr et utilise ctrl->nbr_base pour retourner l'adress d'un
** t_op_nbr malloc avec nbr en base 10 non signe et bien formate
** (pas de 0 au debut), sign contenant l'enum du sign et length contenant la
** longueur de nbr.
*/
t_op_nbr		*get_op_nbr(t_data *ctrl, t_tree *root)
{
  return (NULL);
}

/*
** epure result->nbr (enleve le sign et les 0 au debut)
** remplis results->sign
** remplis results->length
*/
t_op_nbr		*format_result(t_op_nbr *result, t_tree *root);
{
  return (NULL);
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
  while (root->data->c != ctrl->op_base[g.dico[i].op])
    ++i;
  g_dico[i].inf_op(&calc);
  return (format_result(calc.result, root->sign));
}
