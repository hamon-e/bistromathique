/*
** get_op_nbr.c for bistromathique in /home/morty/rendu/Piscine_C_bistromathique/sources/inf_op
**
** Made by Nicolas Goudal
** Login   <goudal_n@epitech.net>
**
** Started on  Fri Oct 30 03:54:41 2015 Nicolas Goudal
** Last update Fri Oct 30 06:23:30 2015 Nicolas Goudal
*/

#include "the_lib.h"
#include "parser.h"
#include "inf_op.h"

static int	compare(char const c, char const *base)
{
  int		i;

  i = 0;
  while (base[i])
  {
    if (base[i] == c)
      return (i);
    ++i;
  }
  return (-1);
}

static char	*op(char *nbr1, char *nbr2, void (*f)(t_op_data *))
{
  t_op_data	test;

  test.nbr1 = the_malloc(sizeof(t_op_nbr));
  test.nbr2 = the_malloc(sizeof(t_op_nbr));
  test.nbr1->nbr = nbr1;
  test.nbr1->sign = PLUS;
  test.nbr1->length = the_strlen(nbr1);
  test.nbr2->nbr = nbr2;
  test.nbr2->length = the_strlen(nbr2);
  test.nbr2->sign = PLUS;
  f(&test);
  while (*test.result->nbr == '0' && *test.result->nbr && test.result->nbr[1])
    ++test.result->nbr;
  i_to_a(test.nbr1->nbr, test.nbr1->length);
  free(test.nbr1);
  free(test.nbr2);
  return (test.result->nbr);
}

t_op_nbr	*get_op_nbr(t_data *ctrl, t_tree *node)
{
  t_op_nbr	*nbr;
  char		*str;
  char		*res;
  int		i;
  int		n;

  str = (char *)((t_nbr *)(node->data))->nbr;
  n = the_strlen(ctrl->nbr_base);
  res = the_malloc(sizeof(char) * 1);
  nbr = the_malloc(sizeof(t_op_nbr));
  *res = '\0';
  nbr->fracidx = 0;
  i = 0;
  while (compare(str[i], ctrl->nbr_base) != -1 || str[i] == '.')
  {
    if (str[i] == '.' && i++)
    {
      nbr->fracidx = i;
      continue ;
    }
    res = op(res, the_itoa(n), inf_mult);
    res = op(res, the_itoa(compare(str[i], ctrl->nbr_base)), inf_add);
    ++i;
  }
  nbr->fracidx = nbr->fracidx ? i - nbr->fracidx : 0;
  nbr->nbr = res;
  nbr->length = the_strlen(res);
  nbr->sign = node->sign;
  return (nbr);
}

void		get_final_result(t_op_nbr *result, t_data *ctrl, int rec)
{
  char	*str;
  int	n;

  str = result->nbr;
  n = the_strlen(ctrl->nbr_base);
  if (rec && rec == nbr->fracidx)
    the_putchar(1, '.');
  if (*str && *str != '0')
  {
    result->nbr = op(str, the_itoa(n), inf_div);
    get_final_result(result, ctrl, rec + 1);
    the_putchar(1, ctrl->nbr_base[the_atoi(op(str, the_itoa(n), inf_mod))]);
  }
  else if (!rec)
    the_putchar(1, ctrl->nbr_base[the_atoi(op(str, the_itoa(n), inf_mod))]);
}
