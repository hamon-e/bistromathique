/*
** modinf.c for modinf in /home/lin_p/Piscine_C_bistromathique
** 
** Made by lin patrick
** Login   <lin_p@epitech.net>
** 
** Started on  Thu Oct 29 04:22:58 2015 lin patrick
** Last update Thu Oct 29 21:32:14 2015 lin patrick
*/

#include <stdlib.h>
#include "structnumber.h"

static char	*mod_proc(t_nbr *res, t_nbr *num1, t_nbr *num2)
{
  int		i;

  i = 0;
  res->length = num1->length + 1;
  if (!(res->num = malloc(sizeof(char) * (res->length + 1))))
    return (NULL);
  clear_str(res->num, res->length);
  a_to_i(res->num, res->length);
  while (i < num1->length)
    {
      char_shift(res->num, res->length);
      res->num[res->length - 1] = num1->num[i];
      div_op(num2, res);
      i = i + 1;
    }
  i_to_a(res->num, res->length);
  if (num1->sign == -1)
    res->num[0] = '-';
  return (res->num);
}

void		modinf(t_op_ctr *op)
{
  mod_proc(op->result, op->num1, op->num2);
}
