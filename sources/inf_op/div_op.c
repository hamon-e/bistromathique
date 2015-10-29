/*
** div_op.c for div_op in /home/lin_p/infinadd2
** 
** Made by lin patrick
** Login   <lin_p@epitech.net>
** 
** Started on  Fri Oct 23 10:35:29 2015 lin patrick
** Last update Thu Oct 29 21:27:20 2015 lin patrick
*/

#include <stdlib.h>
#include "structnumber.h"

int	div_op(t_nbr *div, t_nbr *tmp)
{
  int	a;
  int	i;

  i = 0;
  a = 1;
  while (a == 1)
    {
      if (check_div(tmp, div) != -1)
	{
	  sub_op(tmp, div);
	  a_to_i(tmp->num, tmp->length);
	}
      else
	a = 0;
      i = i + 1;
    }
  return (i - 1);
}

void	*div_process(t_nbr *res, t_nbr *num1, t_nbr *num2, t_nbr *tmp)
{
  int	i;

  i = 0;
  if (!(tmp = malloc(sizeof(t_nbr))))
    return (NULL);
  tmp->length = res->length - 1;
  if (!(tmp->num = malloc(sizeof(char) * tmp->length + 1)))
    return (NULL);
  clear_str(tmp->num, tmp->length);
  a_to_i(tmp->num, tmp->length);
  while (i < num1->length)
    {
      char_shift(tmp->num, tmp->length);
      tmp->num[tmp->length - 1] = num1->num[i];
      res->num[i + 1] = div_op(num2, tmp);
      i = i + 1;
    }
  free(tmp->num);
  free(tmp);
  i_to_a(res->num, res->length);
}

static t_nbr	*init_divresult(t_nbr *res, t_nbr *num1, t_nbr *num2)
{
  int		i;

  i = 0;
  res->length = num1->length + 1;
  if (!(res->num = malloc(sizeof(char) * res->length + 1)))
    return (NULL);
  res->num[res->length] = -'0';
  while (i < res->length)
    {
      res->num[i] = '\0';
      i = i + 1;
    }
  if (num1->sign * num2->sign == -1)
    res->num[0] = '-' - '0';
  return (res);
}

void		divinf(t_op_ctr *op)
{
  if (strcmp(op->num2, "0") == 0)
    {
      my_putstr("Error : Divide by zero");
      return (NULL);
    }
  op->result = init_divresult(op->result, op->num1, op->num2);
  div_process(op->result, op->num1, op->num2, op->tmp);
}
