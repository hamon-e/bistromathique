/*
** test.c for peg in /home/hamon_e/Piscine/Piscine_C_bistromathique/peg
**
** Made by Benoit Hamon
** Login   <hamon_e@epitech.net>
**
** Started on  lun. oct. 26 17:58:50 2015 Benoit Hamon
** Last update Thu Oct 29 05:14:32 2015 Nicolas Goudal
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "peg.h"

t_tree		*create_node(t_type type, void *str,
			     t_tree *left, t_tree *right)
{
  t_tree	*new;

  new = malloc(sizeof(t_tree));
  new->type = type;
  new->data = str;
  new->right = right;
  new->left = left;
  return (new);
}

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
    i++;
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

void	the_space_consumer(t_data *ctrl, unsigned int *index)
{
  while (ctrl->str[*index] == ' ')
    ++*index;
}

t_tree		*num(t_data *ctrl, unsigned int *index)
{
  unsigned int	index_save;
  t_tree	*test;
  t_nbr		*nbr;

  index_save = *index;
  the_space_consumer(ctrl, &index_save);
  if (!is_num(ctrl, &index_save))
    return (NULL);
  nbr = malloc(sizeof(t_nbr));
  nbr->nbr = ctrl->str + *index;
  test = create_node(NUM, nbr, NULL, NULL);
  *index = index_save;
  return (test);
}

t_tree		*ope_high(t_data *ctrl, unsigned int *index)
{
  unsigned int	index_save;
  t_tree	*node;
  t_tree	*node1;
  t_op		*op;

  index_save = *index;
  if (!(node = pth(ctrl, &index_save)))
    return (NULL);
  *index = index_save;
  the_space_consumer(ctrl, &index_save);
  while (is_upopp(ctrl, index_save))
  {
    op = malloc(sizeof(t_op));
    op->c = ctrl->str[index_save++];
    node1 = create_node(OPP, op, node, NULL);
    node1->sign = PLUS;
    if (!(node1->right = pth(ctrl, &index_save)))
      return (node);
    *index = index_save;
    the_space_consumer(ctrl, &index_save);
    node = node1;
  }
  return (node);
}

t_tree		*ope_low(t_data *ctrl, unsigned int *index)
{
  unsigned int	index_save;
  t_tree	*node;
  t_tree	*node1;
  t_op		*op;

  index_save = *index;
  if (!(node = ope_high(ctrl, &index_save)))
    return (NULL);
  *index = index_save;
  the_space_consumer(ctrl, &index_save);
  while (is_lowopp(ctrl, index_save))
  {
    op = malloc(sizeof(t_op));
    op->c = ctrl->str[index_save++];
    node1 = create_node(OPP, op, node, NULL);
    node1->sign = PLUS;
    if (!(node1->right = ope_high(ctrl, &index_save)))
      return (NULL);
    *index = index_save;
    the_space_consumer(ctrl, &index_save);
    node = node1;
  }
  the_space_consumer(ctrl, index);
  return (node);
}

t_tree		*pth_1(t_data *ctrl, int *index, int sign, int index_save)
{
  t_tree	*tmp;

  if (ctrl->str[index_save] == ctrl->op_base[0])
  {
    ++index_save;
    if (!(tmp = ope_low(ctrl, &index_save)))
      return (NULL);
    if (ctrl->str[index_save++] == ctrl->op_base[1])
    {
      if (tmp->sign == PLUS)
	tmp->sign = sign;
      else
	tmp->sign = -sign;
      *index = index_save;
      return (tmp);
    }
  }
  return (NULL);
}

t_tree		*pth(t_data *ctrl, int *index)
{
  t_tree	*tmp;
  unsigned int	index_save;
  int		sign;

  sign = 1;
  index_save = *index;
  the_space_consumer(ctrl, &index_save);
  while (is_lowopp(ctrl, index_save) || ctrl->str[index_save] == ' ')
  {
    if (ctrl->str[index_save] == ctrl->op_base[3])
      sign *= -1;
    ++index_save;
  }
  if ((tmp = num(ctrl, &index_save)))
  {
    tmp->sign = sign;
    *index = index_save;
    return (tmp);
  }
  return (pth_1(ctrl, index, sign, index_save));
}

int	calc(t_tree *racine)
{
  char	opp;
  t_op	*op;
  t_nbr *nbr;

  if (!racine)
    exit(4);
  if (racine->type == OPP)
  {
    op = (t_op *)racine->data;
    opp = op->c;
    if (opp == '+')
      return ((calc(racine->left) + calc(racine->right)) * racine->sign);
    if (opp == '-')
      return ((calc(racine->left) - calc(racine->right)) * racine->sign);
    if (opp == '/')
      return ((calc(racine->left) / calc(racine->right)) * racine->sign);
    if (opp == '*')
      return ((calc(racine->left) * calc(racine->right)) * racine->sign);
    if (opp == '%')
      return ((calc(racine->left) % calc(racine->right)) * racine->sign);
  }
  nbr = (t_nbr *)racine->data;
  return (atoi(nbr->nbr) * racine->sign);
}
