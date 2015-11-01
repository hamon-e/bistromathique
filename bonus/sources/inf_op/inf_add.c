/*
** inf_add.c for bistromathique in /home/morty/rendu/Piscine_C_bistromathique/sources/inf_op
**
** Made by Nicolas Goudal
** Login   <goudal_n@epitech.net>
**
** Started on  Thu Oct 29 22:49:59 2015 Nicolas Goudal
** Last update Sun Nov  1 12:08:42 2015 lin patrick
*/

#include <stdlib.h>
#include "the_lib.h"
#include "inf_op.h"

static t_op_nbr	*init_addresult(t_op_nbr *res, t_op_nbr *nbr1, t_op_nbr *nbr2)
{
  int		i;

  i = 0;
  res = the_malloc(sizeof(t_op_nbr));
  res->length = nbr1->length + 2;
  res->nbr = the_malloc(sizeof(char) * (res->length + 1));
  res->nbr[res->length] = '\0' - '0';
  res->fracidx = nbr1->fracidx;
  while (i < res->length)
  {
    res->nbr[i] = '0' - '0';
    ++i;
  }
  rev_copy_str(nbr1->nbr, res->nbr, nbr1->length, res->length);
  if (nbr1->sign == MINUS)
  {
    if (nbr1->length != nbr2->length)
      res->nbr[0] = '-' - '0';
    else
      if (the_strcmp(nbr1->nbr, nbr2->nbr) > 0 || nbr2->sign == MINUS)
	res->nbr[0] = '-' - '0';
  }
  return (res);
}

static void	add_op(t_op_nbr *res, t_op_nbr *nbr2)
{
  int		idxr;
  int		idxn;

  idxn = nbr2->length - 1;
  idxr = res->length - 1;
  while (idxn >= 0)
  {
    res->nbr[idxr] += nbr2->nbr[idxn];
    if (idxr > 0)
      res->nbr[idxr - 1] += res->nbr[idxr] / 10;
    res->nbr[idxr] %= 10;
    --idxn;
    --idxr;
  }
  while (idxr > 0)
  {
    res->nbr[idxr - 1] += res->nbr[idxr] / 10;
    res->nbr[idxr] %= 10;
    --idxr;
  }
  i_to_a(res->nbr, res->length);
}

void		inf_add(t_op_data *ctrl)
{
  t_op_nbr	*tmp;

  check_frac(ctrl->nbr1, ctrl->nbr2);
  a_to_i(ctrl->nbr1->nbr, ctrl->nbr1->length);
  a_to_i(ctrl->nbr2->nbr, ctrl->nbr2->length);
  if (checkswap(ctrl->nbr1, ctrl->nbr2))
  {
    tmp = ctrl->nbr1;
    ctrl->nbr1 = ctrl->nbr2;
    ctrl->nbr2 = tmp;
  }
  ctrl->result = init_addresult(ctrl->result, ctrl->nbr1, ctrl->nbr2);
  if (ctrl->nbr1->sign == MINUS && ctrl->nbr2->sign == PLUS)
    sub_op(ctrl->result, ctrl->nbr2);
  else
    if (ctrl->nbr1->sign == PLUS && ctrl->nbr2->sign == MINUS)
      sub_op(ctrl->result, ctrl->nbr2);
    else
      add_op(ctrl->result, ctrl->nbr2);
  remove_zfrac(ctrl->result);
}
