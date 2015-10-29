/*
** inf_add.c for bistromathique in /home/morty/rendu/Piscine_C_bistromathique/sources/inf_op
**
** Made by Nicolas Goudal
** Login   <goudal_n@epitech.net>
**
** Started on  Thu Oct 29 22:18:23 2015 Nicolas Goudal
** Last update Thu Oct 29 22:34:05 2015 Nicolas Goudal
*/

#include <stdlib.h>
#include "inf_op.h"

static t_op_nbr	*init_addresult(t_op_nbr *res, t_op_nbr *nbr1, t_op_nbr *nbr2)
{
  int		i;

  i = 0;
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

void		*inf_add(t_op_ctr *op)
{
  t_op_nbr	*tmp;

  if (checkswap(op->nbr1, op->nbr2))
  {
    tmp = op->nbr1;
    op->nbr1 = op->nbr2;
    op->nbr2 = tmp;
  }
  op->result = init_addresult(op->result, op->nbr1, op->nbr2);
  if (op->nbr1->sign == MINUS && op->nbr2->sign == PLUS)
    sub_op(op->result, op->nbr2);
  else
    if (op->nbr1->sign == PLUS && op->nbr2->sign == MINUS)
      sub_op(op->result, op->nbr2);
    else
      add_op(op->result, op->nbr2);
}
