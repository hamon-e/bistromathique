/*
** inf_div.c for bistromathique in /home/morty/rendu/Piscine_C_bistromathique/sources/inf_op
**
** Made by Nicolas Goudal
** Login   <goudal_n@epitech.net>
**
** Started on  Thu Oct 29 23:19:53 2015 Nicolas Goudal
** Last update Sun Nov  1 12:18:04 2015 lin patrick
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
  res = the_malloc(sizeof(t_op_nbr));
  res->length = nbr1->length + 1;
  res->nbr = the_malloc(sizeof(char) * (res->length + 1));
  res->nbr[res->length] = -'0';
  res->fracidx = ACC;
  while (i < res->length)
  {
    res->nbr[i] = '\0';
    ++i;
  }
  if (nbr1->sign * nbr2->sign == MINUS)
    res->nbr[0] = '-' - '0';
  return (res);
}

void		inf_div(t_op_data *ctrl)
{
  if (!*ctrl->nbr2->nbr || !the_strcmp(ctrl->nbr2->nbr, "0"))
    the_exit(-3, ERROR_MSG);
  check_frac(ctrl->nbr1, ctrl->nbr2);
  char_shift_to_the_left(ctrl->nbr1);
  a_to_i(ctrl->nbr1->nbr, ctrl->nbr1->length);
  a_to_i(ctrl->nbr2->nbr, ctrl->nbr2->length);
  ctrl->result = init_divresult(ctrl->result, ctrl->nbr1, ctrl->nbr2);
  div_process(ctrl->result, ctrl->nbr1, ctrl->nbr2, ctrl->tmp);
  remove_zfrac(ctrl->result);
}

void		inf_div_int(t_op_data *ctrl)
{
  if (!*ctrl->nbr2->nbr || !the_strcmp(ctrl->nbr2->nbr, "0"))
    the_exit(-3, ERROR_MSG);
  a_to_i(ctrl->nbr1->nbr, ctrl->nbr1->length);
  a_to_i(ctrl->nbr2->nbr, ctrl->nbr2->length);
  ctrl->result = init_divresult(ctrl->result, ctrl->nbr1, ctrl->nbr2);
  div_process(ctrl->result, ctrl->nbr1, ctrl->nbr2, ctrl->tmp);
}
