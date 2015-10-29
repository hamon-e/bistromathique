/*
** checkdiv.c for checkdiv in /home/lin_p/infinadd2
** 
** Made by lin patrick
** Login   <lin_p@epitech.net>
** 
** Started on  Wed Oct 28 19:36:12 2015 lin patrick
** Last update Thu Oct 29 18:36:01 2015 lin patrick
*/

#include "structnumber.h"

static int	checkdivlen(t_nbr *num)
{
  int		i;
  int		b;

  b = 0;
  i = 0;
  i_to_a(num->num, num->length);
  while (num->num[i] == '0')
    i = i + 1;
  while (num->num[i] != '\0')
    {
      b = b + 1;
      i = i + 1;
    }
  a_to_i(num->num, num->length);
  return (b);
}

int     check_div(t_nbr *num1, t_nbr *num2)
{
  int   i;
  int   j;

  i = 0;
  j = 0;
  while (num1->num[i] == 0 && num1->num[i + 1] != -'0')
    i = i + 1;
  while (num2->num[j] == 0 && num2->num[j + 1] != -'0')
    j = j + 1;
  if (checkdivlen(num1) < checkdivlen(num2))
    return (-1);
  if (checkdivlen(num1) > checkdivlen(num2))
    return (1);
  while (num1->num[i] != -'0' && num2->num[j] != -'0')
    {
      if (num1->num[i] > num2->num[j])
        return (1);
      if (num1->num[i] < num2->num[j])
        return (-1);
      i = i + 1;
      j = j + 1;
    }
  return (0);
}
