/*
** check_frac.c for check_frac in /home/lin_p/tt/sources/inf_op
** 
** Made by lin patrick
** Login   <lin_p@epitech.net>
** 
** Started on  Fri Oct 30 13:27:47 2015 lin patrick
** Last update Sun Nov  1 12:19:47 2015 lin patrick
*/

#include "the_lib.h"
#include "inf_op.h"

static void	frac_format(t_op_nbr *nbr1, t_op_nbr *nbr2, char *tmp)
{
  int		i;

  i = 0;
  while (i < nbr1->length)
  {
    tmp[i] = nbr1->nbr[i];
    ++i;
  }
  nbr1->length += nbr2->fracidx - nbr1->fracidx;
  nbr1->fracidx += nbr2->fracidx - nbr1->fracidx;
  while (i < nbr1->length)
  {
    tmp[i] = '0';
    ++i;
  }
  tmp[i] = '\0';
}

void		char_shift_to_the_left(t_op_nbr *nbr)
{
  char		*tmp;
  int		i;

  i = 0;
  tmp = the_malloc(sizeof(char) * (nbr->length + ACC) + 1);
  while (i <nbr->length)
  {
    tmp[i] = nbr->nbr[i];
    ++i;
  }
  while (i < nbr->length + ACC)
  {
    tmp[i] = '0';
    ++i;
  }
  tmp[i] = '\0';
  nbr->nbr = tmp;
  nbr->length = nbr->length + ACC;
}

void		remove_zfrac(t_op_nbr *res)
{
  int		a;
  int		b;
  int		idx;
  char		*str;

  idx = the_strlen(res->nbr) - 1;
  b = idx - res->fracidx;
  a = 0;
  while (res->fracidx > 0 && res->nbr[idx] == '0')
  {
    ++a;
    --idx;
  }
  res->fracidx -= a;
  str = the_malloc(sizeof(char) * (the_strlen(res->nbr) - a + 1));
  str[the_strlen(res->nbr) - a] = '\0';
  copy_str(res->nbr, str, the_strlen(res->nbr) - a - 1, 0);
  free(res->nbr);
  res->nbr = str;
}

void		check_frac(t_op_nbr *nbr1, t_op_nbr *nbr2)
{
  char		*tmp;

  if (nbr1->fracidx < nbr2->fracidx)
  {
    tmp = the_malloc(sizeof(char)
		     * (nbr1->length + nbr2->fracidx - nbr1->fracidx + 1));
    frac_format(nbr1, nbr2, tmp);
    nbr1->nbr = tmp;
  }
  else if (nbr1->fracidx > nbr2->fracidx)
  {
    tmp = the_malloc(sizeof(char)
		     * (nbr2->length + nbr1->fracidx - nbr2->fracidx + 1));
    frac_format(nbr2, nbr1, tmp);
    nbr2->nbr = tmp;
  }
}
