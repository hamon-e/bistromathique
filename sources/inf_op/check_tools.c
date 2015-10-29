/*
** check_tools.c for bistromathique in /home/morty/rendu/Piscine_C_bistromathique/sources/inf_op
**
** Made by Nicolas Goudal
** Login   <goudal_n@epitech.net>
**
** Started on  Thu Oct 29 23:30:09 2015 Nicolas Goudal
** Last update Thu Oct 29 23:49:55 2015 Nicolas Goudal
*/

#include "the_lib.h"
#include "inf_op.h"

int		checkswap(t_op_nbr *nbr1, t_op_nbr *nbr2)
{
  if (nbr1->sign == MINUS && nbr2->sign == PLUS)
  {
    if (nbr1->length > nbr2->length)
      return (0);
    if (nbr1->length == nbr2->length)
      if (the_strcmp(nbr1->nbr, nbr2->nbr) <= 0)
	return (0);
    return (1);
  }
  if (nbr1->sign == PLUS && nbr2->sign == MINUS)
  {
    if (nbr1->length > nbr2->length)
      return (0);
    if (nbr1->length == nbr2->length)
      if (the_strcmp(nbr1->nbr, nbr2->nbr) <= 0)
	return (0);
    return (1);
  }
  if (nbr1->length < nbr2->length)
    return (1);
  return (0);
}

static int	checkdivlen(t_op_nbr *nbr)
{
  int		i;
  int		len;

  len = 0;
  i = 0;
  i_to_a(nbr->nbr, nbr->length);
  while (nbr->nbr[i] == '0')
    ++i;
  while (nbr->nbr[i])
  {
    ++len;
    ++i;
  }
  a_to_i(nbr->nbr, nbr->length);
  return (len);
}

int	check_div(t_op_nbr *nbr1, t_op_nbr *nbr2)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (nbr1->nbr[i] == 0 && nbr1->nbr[i + 1] != -'0')
    ++i;
  while (nbr2->nbr[j] == 0 && nbr2->nbr[j + 1] != -'0')
    ++j;
  if (checkdivlen(nbr1) < checkdivlen(nbr2))
    return (-1);
  if (checkdivlen(nbr1) > checkdivlen(nbr2))
    return (1);
  while (nbr1->nbr[i] != -'0' && nbr2->nbr[j] != -'0')
  {
    if (nbr1->nbr[i] > nbr2->nbr[j])
      return (1);
    if (nbr1->nbr[i] < nbr2->nbr[j])
      return (-1);
    ++i;
    ++j;
  }
  return (0);
}
