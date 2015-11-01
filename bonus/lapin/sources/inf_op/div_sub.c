/*
** div_sub.c for inf_op in /home/hamon_e/Piscine/tmp/Piscine_C_bistromathique/bonus/sources/inf_op
** 
** Made by Benoit Hamon
** Login   <hamon_e@epitech.net>
** 
** Started on  Sun Nov 01 16:08:36 2015 Benoit Hamon
** Last update Sun Nov 01 16:08:36 2015 Benoit Hamon
*/

#include "inf_op.h"

int		div_op(t_op_nbr *div, t_op_nbr *tmp)
{
  int		i;

  i = 0;
  while (42)
  {
    if (check_div(tmp, div) != -1)
    {
      sub_op(tmp, div);
      a_to_i(tmp->nbr, tmp->length);
    }
    else
      break ;
    ++i;
  }
  return (i);
}
