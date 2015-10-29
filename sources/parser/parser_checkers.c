/*
** parser_checkers.c for bistromathique in /home/morty/rendu/Piscine_C_bistromathique/sources/parser
**
** Made by Nicolas Goudal
** Login   <goudal_n@epitech.net>
**
** Started on  Thu Oct 29 19:30:36 2015 Nicolas Goudal
** Last update Thu Oct 29 21:35:23 2015 Nicolas Goudal
*/

#include <stdbool.h>
#include "parser.h"
#include "do_inf_op.h"

bool	is_upopp(t_data *ctrl, unsigned int index)
{
  if (ctrl->str[index] == ctrl->op_base[OP_MULT_IDX])
    return (true);
  if (ctrl->str[index] == ctrl->op_base[OP_DIV_IDX])
    return (true);
  if (ctrl->str[index] == ctrl->op_base[OP_MOD_IDX])
    return (true);
  return (false);
}

bool	is_lowopp(t_data *ctrl, unsigned int index)
{
  if (ctrl->str[index] == ctrl->op_base[OP_ADD_IDX])
    return (true);
  if (ctrl->str[index] == ctrl->op_base[OP_SUB_IDX])
    return (true);
  return (false);
}

bool	is_digit(t_data *ctrl, unsigned int index)
{
  int	i;

  i = 0;
  while (ctrl->nbr_base[i])
  {
    if (ctrl->str[index] == ctrl->nbr_base[i])
      return (true);
    ++i;
  }
  return (false);
}

bool	is_num(t_data *ctrl, unsigned int *index)
{
  if (!is_digit(ctrl, *index))
    return (false);
  while (is_digit(ctrl, *index))
    ++*index;
  return (true);
}
