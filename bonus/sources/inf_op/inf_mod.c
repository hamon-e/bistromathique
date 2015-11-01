/*
** inf_mod.c for bistromathique in /home/morty/rendu/Piscine_C_bistromathique/sources/inf_op
**
** Made by Nicolas Goudal
** Login   <goudal_n@epitech.net>
**
** Started on  Thu Oct 29 23:19:50 2015 Nicolas Goudal
** Last update Sun Nov  1 17:39:44 2015 lin patrick
*/

#include "the_lib.h"
#include "inf_op.h"

static void	mod_proc(t_op_nbr *res, t_op_nbr *nbr1, t_op_nbr *nbr2)
{
  int		i;

  i = 0;
  res->length = nbr1->length + 1;
  res->nbr = the_malloc(sizeof(char) * (res->length + 1));
  clear_str(res->nbr, res->length);
  a_to_i(res->nbr, res->length);
  while (i < nbr1->length)
  {
    char_shift(res->nbr, res->length);
    res->nbr[res->length - 1] = nbr1->nbr[i];
    div_op(nbr2, res);
    ++i;
  }
  i_to_a(res->nbr, res->length);
  if (nbr1->sign == -1)
    res->nbr[0] = '-';
}

void		inf_mod(t_op_data *ctrl)
{
  if (!*ctrl->nbr2->nbr || !the_strcmp(ctrl->nbr2->nbr, "0"))
    the_exit(-3, ERROR_MSG);
  if (ctrl->nbr1->fracidx || ctrl->nbr2->fracidx)
    the_exit(-3, ERROR_MSG);
  ctrl->result = the_malloc(sizeof(t_op_nbr));
  a_to_i(ctrl->nbr1->nbr, ctrl->nbr1->length);
  a_to_i(ctrl->nbr2->nbr, ctrl->nbr2->length);
  mod_proc(ctrl->result, ctrl->nbr1, ctrl->nbr2);
}
