/*
** check_argv.c for bistromathique in /home/morty/rendu/Piscine_C_bistromathique/sources/tools
**
** Made by Nicolas Goudal
** Login   <goudal_n@epitech.net>
**
** Started on  Thu Oct 29 19:46:16 2015 Nicolas Goudal
** Last update Thu Oct 29 19:51:52 2015 Nicolas Goudal
*/

#include "the_lib.h"

static int	check_base(char const *base)
{
  int		i;
  int		j;

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
  if (*size == '-')
    return (0);
  if (the_strlen(size) <= 9)
    return (1);
  if (the_strcmp(size, "2147483647") > 0)
    return (0);
  return (1);
}

static int	check_cmp_base_opp(char const *base, char const *opp)
{
  int		i;
  int		j;

  i = -1;
  while (base[++i])
  {
    j = -1;
    while (opp[++j])
      if (base[i] == opp[j])
	return (0);
  }
  return (1);
}

int		check_argv(int argc, char const *argv[])
{
  if (argc != 4)
    return (0);
  if (!check_base(argv[1]))
    return (0);
  if (!check_opp(argv[2]))
    return (0);
  if (!check_cmp_base_opp(argv[1], argv[2]))
    return (0);
  if (!check_size(argv[3]))
    return (0);
  return (1);
}
