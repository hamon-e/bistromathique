/*
** add_op.c for add_op in /home/lin_p/infinadd2
** 
** Made by lin patrick
** Login   <lin_p@epitech.net>
** 
** Started on  Thu Oct 22 17:18:41 2015 lin patrick
** Last update Thu Oct 29 21:35:23 2015 lin patrick
*/

#include <stdlib.h>
#include "structnumber.h"

static t_nbr	*init_addresult(t_nbr *res, t_nbr *num1, t_nbr *num2)
{
  int		i;

  i = 0;
  res->length = num1->length + 2;
  if (!(res->num = malloc(res->length + 1)))
    return (NULL);
  res->num[res->length] = '\0' - '0';
  while (i < res->length)
    {
      res->num[i] = '0' - '0';
      i = i + 1;
    }
  my_strcpy2(num1->num, res->num, num1->length, res->length);
  if (num1->sign == -1)
    {
      if (num1->length != num2->length)
	res->num[0] = '-' - '0';
      else
	if (my_strcmp(num1->num, num2->num) == -1 || num2->sign == -1)
	  res->num[0] = '-' - '0';
    }
  return (res);
}

static void	add_op(t_nbr *res, t_nbr *num2)
{
  int		idxr;
  int		idxn;

  idxn = num2->length - 1;
  idxr = res->length - 1;
  while (idxn >= 0)
    {
      res->num[idxr] = res->num[idxr] + num2->num[idxn];
      res->num[idxr - 1] = res->num[idxr - 1] + res->num[idxr] / 10;
      res->num[idxr] = res->num[idxr] % 10;
      idxn = idxn - 1;
      idxr = idxr - 1;
    }
  while (idxr > 0)
    {
      res->num[idxr - 1] = res->num[idxr - 1] + res->num[idxr] / 10;
      res->num[idxr] = res->num[idxr] % 10;
      idxr = idxr - 1;
    }
  i_to_a(res->num, res->length);
}

void		*addinf(t_op_ctr *op)
{
  t_nbr		*tmp;

  if (checkswap(op->num1, op->num2) == 1)
    {
      tmp = op->num1;
      op->num1 = op->num2;
      op->num2 = tmp;
    }
  op->result = init_addresult(op->result, op->num1, op->num2);
  if (op->num1->sign == -1 && op->num2->sign == 1)
    sub_op(op->result, op->num2);
  else
    if (op->num1->sign == 1 && op->num2->sign == -1)
      sub_op(op->result, op->num2);
    else
      add_op(op->result, op->num2);
}
