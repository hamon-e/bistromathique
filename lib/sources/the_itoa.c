/*
** the_itoa.c for sources in /home/hamon_e/Piscine/Piscine_C_bistromathique/lib/sources
** 
** Made by Benoit Hamon
** Login   <hamon_e@epitech.net>
** 
** Started on  Sun Nov 01 12:25:31 2015 Benoit Hamon
** Last update Sun Nov 01 12:25:31 2015 Benoit Hamon
*/

#include "the_lib.h"

static int	count(int nbr)
{
  int		i;

  i = 0;
  while (nbr)
  {
    ++i;
    nbr /= 10;
  }
  return (i);
}

char		*the_itoa(int nbr)
{
  char		*res;
  int		i;

  i = count(nbr);
  res = the_malloc(sizeof(char) * (i + 1));
  res[i] = '\0';
  while (nbr)
  {
    res[i - 1] = nbr % 10 + '0';
    nbr /= 10;
    --i;
  }
  return (res);
}

