/*
** inf_sub.c for bistromathique in /home/morty/rendu/Piscine_C_bistromathique/sources/inf_op
**
** Made by Nicolas Goudal
** Login   <goudal_n@epitech.net>
**
** Started on  Thu Oct 29 22:11:28 2015 Nicolas Goudal
** Last update Thu Oct 29 22:29:53 2015 Nicolas Goudal
*/

#include "inf_op.h"

static void	sub_op_rmd(t_op_nbr *res)
{
  int		idx;

  idx = res->length - 1;
  while (idx > 1)
  {
    if (res->nbr[idx] < 0)
    {
      res->nbr[idx] += 10;
      res->nbr[idx - 1] -= 1;
    }
    --idx;
  }
}

char		*sub_op(t_op_nbr *res, t_op_nbr *nbr2)
{
  int		idxr;
  int		idxn;

  idxr = res->length - 1;
  idxn = nbr2->length - 1;
  while (idxn >= 0)
  {
    if (res->nbr[idxr] < nbr2->nbr[idxn])
    {
      res->nbr[idxr] -= nbr2->nbr[idxn] + 10;
      res->nbr[idxr - 1] -= 1;
    }
    else
      res->nbr[idxr] -= nbr2->nbr[idxn];
    --idxr;
    --idxn;
  }
  sub_op_rmd(res);
  i_to_a(res->nbr, res->length);
  return (res->nbr);
}

void		inf_sub(t_op_ctrl *ctrl)
{
  ctrl->nbr2->sign = -ctrl->nbr2->sign;
  inf_add(ctrl);
}
