/*
** mul.c for mult in /home/lin_p/infinadd2
**
** Made by lin patrick
** Login   <lin_p@epitech.net>
**
** Started on  Thu Oct 22 17:37:13 2015 lin patrick
** Last update Thu Oct 29 22:08:16 2015 Nicolas Goudal
*/

#include <stdlib.h>
#include "structnumber.h"

static void	calc_tmp_mul(t_nbr *tmp, t_nbr *num1, t_nbr *num2, int i)
{
  int		rmd;
  int		j;
  int		k;
  int		l;

  rmd = 0;
  l = num2->length - i - 1;
  j = tmp->length - 1;
  k = num1->length - 1;
  clear_str(tmp->num, tmp->length);
  a_to_i(tmp->num, tmp->length);
  while (k >= 0)
    {
      tmp->num[j - l] = num1->num[k] * num2->num[i] + rmd;
      rmd = tmp->num[j - l] / 10;
      tmp->num[j - l] = tmp->num[j - l] % 10;
      k = k - 1;
      j = j - 1;
    }
  tmp->num[j - l] = tmp->num[j - l] + rmd;
}

static void	add_mul(t_nbr *res, t_nbr *tmp, int length)
{
  int		i;

  i = res->length - 1;
  while (length > 0)
    {
      res->num[i] = res->num[i] + tmp->num[length];
      res->num[i - 1] = res->num[i - 1] + res->num[i] / 10;
      res->num[i] = res->num[i] % 10;
      length = length - 1;
      i = i - 1;
    }
}

static void	mul_process(t_nbr *res, t_nbr *num1, t_nbr *num2, t_nbr *tmp)
{
  int		i;

  if (!(tmp = malloc(sizeof(t_nbr))))
    return (NULL);
  tmp->length = res->length;
  if (!(tmp->num = malloc(tmp->length + 1)))
    return (NULL);
  i = num2->length - 1;
  while (i >= 0)
    {
      calc_tmp_mul(tmp, num1, num2, i);
      add_mul(res, tmp, tmp->length - 1);
      i = i - 1;
    }
  free(tmp->num);
  free(tmp);
  i_to_a(res->num, res->length);
}

static t_nbr	*init_mulresult(t_nbr *res, t_nbr *num1, t_nbr *num2)
{
  res->length = num1->length + num2->length + 1;
  if (num1->sign * num2->sign == -1)
    res->length = res->length + 1;
  if (!(res->num = malloc(res->length + 1)))
    return (NULL);
  clear_str(res->num, res->length);
  a_to_i(res->num, res->length);
  if (num1->sign * num2->sign == -1)
    res->num[0] = -3;
  return (res);
}

void		inf_mult(t_op_ctr *op)
{
  t_nbr		*tmp;

  if (checkswap(op->num1, op->num2) == 1)
    {
      tmp = op->num1;
      op->num1 = op->num2;
      op->num2 = tmp;
    }
  op->result = init_mulresult(op->result, op->num1, op->num2);
  mul_process(op->result, op->num1, op->num2, op->tmp);
}
