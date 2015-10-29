/*
** inf_mod.c for bistromathique in /home/morty/rendu/Piscine_C_bistromathique/sources/inf_op
**
** Made by Nicolas Goudal
** Login   <goudal_n@epitech.net>
**
** Started on  Thu Oct 29 23:19:50 2015 Nicolas Goudal
** Last update Fri Oct 30 00:46:14 2015 Nicolas Goudal
*/

#include "the_lib.h"
#include "inf_op.h"

static char	*mod_proc(t_op_nbr *res, t_op_nbr *nbr1, t_op_nbr *nbr2)
{
  int		i;

  i = 0;
  res = the_malloc(sizeof(t_op_nbr));
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
  return (res->nbr);
}

void		inf_mod(t_op_data *ctrl)
{
  mod_proc(ctrl->result, ctrl->nbr1, ctrl->nbr2);
}
