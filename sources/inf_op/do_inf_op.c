/*
** do_inf_op.c for bistromathique in /home/morty/rendu/Piscine_C_bistromathique/sources/inf_op
**
** Made by Nicolas Goudal
** Login   <goudal_n@epitech.net>
**
** Started on  Thu Oct 29 19:39:41 2015 Nicolas Goudal
** Last update Thu Oct 29 20:20:05 2015 Nicolas Goudal
*/

#include "the_lib.h"
#include "parser.h"

int		calc(t_tree *racine)
{
  t_op		*op;
  t_nbr		*nbr;

  if (!racine)
    exit(4);
  if (racine->type == OPP)
  {
    op = (t_op *)racine->data;
    if (op->c == '+')
      return ((calc(racine->left) + calc(racine->right)) * racine->sign);
    if (op->c == '-')
      return ((calc(racine->left) - calc(racine->right)) * racine->sign);
    if (op->c == '/')
      return ((calc(racine->left) / calc(racine->right)) * racine->sign);
    if (op->c == '*')
      return ((calc(racine->left) * calc(racine->right)) * racine->sign);
    if (op->c == '%')
      return ((calc(racine->left) % calc(racine->right)) * racine->sign);
  }
  nbr = (t_nbr *)racine->data;
  return (the_atoi(nbr->nbr) * racine->sign);
}
