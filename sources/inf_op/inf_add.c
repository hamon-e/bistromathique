/*
** inf_add.c for bistromathique in /home/morty/rendu/Piscine_C_bistromathique/sources/inf_op
**
** Made by Nicolas Goudal
** Login   <goudal_n@epitech.net>
**
** Started on  Thu Oct 29 22:49:59 2015 Nicolas Goudal
** Last update Fri Oct 30 00:45:42 2015 Nicolas Goudal
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
  while (i < res->length)
  {
    res->nbr[i] = '0' - '0';
    ++i;
  }
  rev_copy_str(nbr1->nbr, res->nbr, nbr1->length, res->length);
  if (nbr1->sign == -1)
  {
    if (nbr1->length != nbr2->length)
      res->nbr[0] = '-' - '0';
    else
      if (the_strcmp(nbr1->nbr, nbr2->nbr) < 0 || nbr2->sign == PLUS)
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
}
