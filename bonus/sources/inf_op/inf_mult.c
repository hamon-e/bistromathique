/*
** inf_mult.c for bistromathique in /home/morty/rendu/Piscine_C_bistromathique/sources/inf_op
**
** Made by Nicolas Goudal
** Login   <goudal_n@epitech.net>
**
** Started on  Thu Oct 29 22:49:53 2015 Nicolas Goudal
** Last update Fri Oct 30 05:12:56 2015 Nicolas Goudal
*/

#include <stdlib.h>
#include "the_lib.h"
#include "inf_op.h"

static void	calc_tmp_mul(t_op_nbr *tmp,
			     t_op_nbr *nbr1,
			     t_op_nbr *nbr2,
			     int i)
{
  int		rmd;
  int		j;
  int		k;
  int		l;

  rmd = 0;
  l = nbr2->length - i - 1;
  j = tmp->length - 1;
  k = nbr1->length - 1;
  clear_str(tmp->nbr, tmp->length);
  a_to_i(tmp->nbr, tmp->length);
  while (k >= 0)
  {
    tmp->nbr[j - l] = nbr1->nbr[k] * nbr2->nbr[i] + rmd;
    rmd = tmp->nbr[j - l] / 10;
    tmp->nbr[j - l] %= 10;
    --k;
    --j;
  }
  tmp->nbr[j - l] += rmd;
}

static void	add_mul(t_op_nbr *res, t_op_nbr *tmp, int length)
{
  int		i;

  i = res->length - 1;
  while (length)
  {
    res->nbr[i] += tmp->nbr[length];
    res->nbr[i - 1] += res->nbr[i] / 10;
    res->nbr[i] %= 10;
    --length;
    --i;
  }
}

static void	mul_process(t_op_nbr *res,
			    t_op_nbr *nbr1,
			    t_op_nbr *nbr2,
			    t_op_nbr *tmp)
{
  int		i;

  tmp = the_malloc(sizeof(t_op_nbr));
  tmp->length = res->length;
  tmp->nbr = the_malloc(tmp->length + 1);
  i = nbr2->length - 1;
  while (i >= 0)
  {
    calc_tmp_mul(tmp, nbr1, nbr2, i);
    add_mul(res, tmp, tmp->length - 1);
    --i;
  }
  free(tmp->nbr);
  free(tmp);
  i_to_a(res->nbr, res->length);
}

static t_op_nbr		*init_mulresult(t_op_nbr *res,
					t_op_nbr *nbr1,
					t_op_nbr *nbr2)
{
  res = the_malloc(sizeof(t_op_nbr));
  res->length = nbr1->length + nbr2->length + 1;
  if (nbr1->sign * nbr2->sign == -1)
    ++res->length;
  if (!(res->nbr = the_malloc(res->length + 1)))
    return (NULL);
  clear_str(res->nbr, res->length);
  a_to_i(res->nbr, res->length);
  if (nbr1->sign * nbr2->sign == -1)
    res->nbr[0] = -3;
  return (res);
}

void		inf_mult(t_op_data *ctrl)
{
  t_op_nbr		*tmp;

  a_to_i(ctrl->nbr1->nbr, ctrl->nbr1->length);
  a_to_i(ctrl->nbr2->nbr, ctrl->nbr2->length);
  if (checkswap(ctrl->nbr1, ctrl->nbr2))
  {
    tmp = ctrl->nbr1;
    ctrl->nbr1 = ctrl->nbr2;
    ctrl->nbr2 = tmp;
  }
  ctrl->result = init_mulresult(ctrl->result, ctrl->nbr1, ctrl->nbr2);
  mul_process(ctrl->result, ctrl->nbr1, ctrl->nbr2, ctrl->tmp);
}
