/*
** my_getnbr_base.c for ex_17 in /home/hamon_e/Piscine/Piscine_C_J06/ex_17
** 
** Made by Benoit Hamon
** Login   <hamon_e@epitech.net>
** 
** Started on  Mon Oct 05 11:44:15 2015 Benoit Hamon
** Last update Mon Oct 05 11:44:15 2015 Benoit Hamon
*/

#include <stdlib.h>
#include "the_lib.h"
#include "parser.h"
#include "inf_op.h"

static int	compare(char const c, char const *base)
{
  int	i;

  i = 0;
  while (base[i])
  {
    if (base[i] == c)
      return (i);
    i++;
  }
  return (-1);
}

static int	count(int nbr)
{
  int	i;

  i = 0;
  while (nbr)
  {
    ++i;
    nbr /= 10;
  }
  return (i);
}

static char	*itoa(int nbr)
{
  char *res;
  int	i;

  i = count(nbr);
  res = malloc(i + 1);
  res[i] = 0;
  while (nbr)
  {
    res[i - 1] = nbr % 10 + '0';
    nbr /= 10;
    i--;
  }
  return (res);
}

static char	*op(char *nbr1, char *nbr2, void (*f)(t_op_data *))
{
  t_op_data	test;

  test.nbr1 = malloc(sizeof(t_op_nbr));
  test.nbr2 = malloc(sizeof(t_op_nbr));
  test.nbr1->nbr = nbr1;
  test.nbr1->sign = PLUS;
  test.nbr1->length = the_strlen(nbr1);
  test.nbr2->nbr = nbr2;
  test.nbr2->length = the_strlen(nbr2);
  test.nbr2->sign = PLUS;
  f(&test);
  while (*test.result->nbr == '0')
      ++test.result->nbr;
  free(test.nbr1);
  free(test.nbr2);
  return (test.result->nbr);
}

t_op_nbr	*get_op_nbr(t_data *ctrl, t_tree *node)
{
  t_op_nbr	*nbr;
  char		*str;
  char		*res;
  char		*tmp;
  int		i;
  int		n;

  str = (char *)((t_nbr *)(node->data))->nbr;
  n = the_strlen(ctrl->op_base);
  res = the_malloc(sizeof(char));
  *res = 0;
  i = -1;
  while (str[++i])
  {
    tmp = op(res, itoa(n), inf_mult);
    free(res);
    res = op(tmp, itoa(compare(str[i], ctrl->op_base)), inf_add);
    free(tmp);
  }
  nbr = malloc(sizeof(t_op_nbr));
  nbr->nbr = res;
  nbr->length = the_strlen(res);
  nbr->sign = node->sign;
  return (nbr);
}
