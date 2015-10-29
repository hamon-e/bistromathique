/*
** the_atoi.c for bistromathique in /home/morty/rendu/Piscine_C_bistromathique/lib/sources
**
** Made by Nicolas Goudal
** Login   <goudal_n@epitech.net>
**
** Started on  Thu Oct 29 20:35:33 2015 Nicolas Goudal
** Last update Thu Oct 29 20:35:43 2015 Nicolas Goudal
*/

#include <limits.h>

int	the_atoi(char const *str)
{
  int	i;
  int	neg;
  long	res;

  i = -1;
  neg = 1;
  res = 0;
  while (str[++i] == '-' || str[i] == '+')
    if (str[i] == '-')
      neg *= -1;
  while (str[i] >= '0' && str[i] <= '9')
  {
    res = res * 10 + (str[i] - '0') * neg;
    if (res > INT_MAX || res < INT_MIN)
      return (0);
    ++i;
  }
  return (res);
}
