/*
** parser_checkers.c for bistromathique in /home/morty/rendu/Piscine_C_bistromathique/sources/parser
**
** Made by Nicolas Goudal
** Login   <goudal_n@epitech.net>
**
** Started on  Thu Oct 29 19:30:36 2015 Nicolas Goudal
** Last update Thu Oct 29 19:43:21 2015 Nicolas Goudal
*/

#include <stdbool.h>
#include "parser.h"

bool	is_upopp(t_data *ctrl, unsigned int index)
{
  if (ctrl->str[index] == ctrl->op_base[4])
    return (true);
  if (ctrl->str[index] == ctrl->op_base[5])
    return (true);
  if (ctrl->str[index] == ctrl->op_base[6])
    return (true);
  return (false);
}

bool	is_lowopp(t_data *ctrl, unsigned int index)
{
  if (ctrl->str[index] == ctrl->op_base[2])
    return (true);
  if (ctrl->str[index] == ctrl->op_base[3])
    return (true);
  return (false);
}

bool	is_digit(t_data *ctrl, unsigned int index)
{
  int	i;

  i = 0;
  while (ctrl->nbr_base[i])
  {
    if (ctrl->str[index] == ctrl->nbr_base[i])
      return (true);
    ++i;
  }
  return (false);
}

bool	is_num(t_data *ctrl, unsigned int *index)
{
  if (!is_digit(ctrl, *index))
    return (false);
  while (is_digit(ctrl, *index))
    ++*index;
  return (true);
}
