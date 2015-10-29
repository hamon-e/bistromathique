/*
** add_inf.c for add_inf in /home/lin_p/infinadd2
** 
** Made by lin patrick
** Login   <lin_p@epitech.net>
** 
** Started on  Thu Oct 22 10:19:01 2015 lin patrick
** Last update Thu Oct 29 04:03:35 2015 lin patrick
*/

#include "structnumber.h"

int	checkswap(t_nbr *num1, t_nbr *num2)
{
  if (num1->sign == -1 && num2->sign == 1)
    {
      if (num1->length > num2->length)
	return (0);
      if (num1->length == num2->length)
	if (my_strcmp(num1->num, num2->num) != 1)
	  return (0);
      return (1);
    }
  if (num1->sign == 1 && num2->sign == -1)
    {
      if (num1->length > num2->length)
	return (0);
      if (num1->length == num2->length)
	if (my_strcmp(num1->num, num2->num) != 1)
	  return (0);
      return (1);
    }
  if (num1->length < num2->length)
    return (1);
  return (0);
}
