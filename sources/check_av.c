/*
** check_av.c for Piscine_C_bistromathique in /home/hamon_e/Piscine/Piscine_C_bistromathique
** 
** Made by Benoit Hamon
** Login   <hamon_e@epitech.net>
** 
** Started on  mer. oct. 28 16:57:11 2015 Benoit Hamon
** Last update mer. oct. 28 16:57:11 2015 Benoit Hamon
*/

#include "the_lib.h"

static int	check_base(char const *base)
{
  int	i;
  int	j;

  if (the_strlen(base) < 1)
    return (0);
  i = -1;
  while (base[++i])
  {
    j = -1;
    while (base[++j])
      if (i != j && base[i] == base[j])
	return (0);
  }
  return (1);
}

static int	check_opp(char const *opp)
{
  if (the_strlen(opp) != 7)
    return (0);
  if (!check_base(opp))
    return (0);
  return (1);
}

static int	check_size(char const *size)
{
  if (the_strlen(size) <= 9)
    return (1);
  if (the_strcmp(size, "2147483647") > 0)
    return (0);
  return (1);
}

int	check_av(int ac, char const *av[])
{
  if (ac != 4)
    return (0);
  if (!check_base(av[1]))
    return (0);
  if (!check_opp(av[2]))
    return (0);
  if (!check_size(av[3]))
    return (0);
  return (1);
}
