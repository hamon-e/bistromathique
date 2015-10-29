/*
** inf_div.c for bistromathique in /home/morty/rendu/Piscine_C_bistromathique/sources/inf_op
**
** Made by Nicolas Goudal
** Login   <goudal_n@epitech.net>
**
** Started on  Thu Oct 29 23:19:53 2015 Nicolas Goudal
** Last update Thu Oct 29 23:46:46 2015 Nicolas Goudal
*/

#include "the_lib.h"
#include "inf_op.h"

static void	div_process(t_op_nbr *res,
			     t_op_nbr *nbr1,
			     t_op_nbr *nbr2,
			     t_op_nbr *tmp)
{
  int		i;

  i = 0;
  tmp = the_malloc(sizeof(t_op_nbr));
  tmp->length = res->length - 1;
  tmp->nbr = the_malloc(sizeof(char) * (tmp->length + 1));
  clear_str(tmp->nbr, tmp->length);
  a_to_i(tmp->nbr, tmp->length);
  while (i < nbr1->length)
  {
    char_shift(tmp->nbr, tmp->length);
    tmp->nbr[tmp->length - 1] = nbr1->nbr[i];
    res->nbr[i + 1] = div_op(nbr2, tmp);
    ++i;
  }
  free(tmp->nbr);
  free(tmp);
  i_to_a(res->nbr, res->length);
}

static t_op_nbr	*init_divresult(t_op_nbr *res, t_op_nbr *nbr1, t_op_nbr *nbr2)
{
  int		i;

  i = 0;
  res->length = nbr1->length + 1;
  res->nbr = the_malloc(sizeof(char) * (res->length + 1));
  res->nbr[res->length] = -'0';
  while (i < res->length)
  {
    res->nbr[i] = '\0';
    ++i;
  }
  if (nbr1->sign * nbr2->sign == -1)
    res->nbr[0] = '-' - '0';
  return (res);
}

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
  return (i - 1);
}

void		inf_div(t_op_data *ctrl)
{
  if (!the_strcmp(ctrl->nbr2->nbr, "0"))
    the_exit(-3, ERROR_MSG);
  ctrl->result = init_divresult(ctrl->result, ctrl->nbr1, ctrl->nbr2);
  div_process(ctrl->result, ctrl->nbr1, ctrl->nbr2, ctrl->tmp);
}
