/*
** peg_rules.c for bistromathique in /home/morty/rendu/Piscine_C_bistromathique/sources/parser
**
** Made by Nicolas Goudal
** Login   <goudal_n@epitech.net>
**
** Started on  Thu Oct 29 19:38:59 2015 Nicolas Goudal
** Last update Thu Oct 29 21:35:39 2015 Nicolas Goudal
*/

#include <stdlib.h>
#include <stdbool.h>
#include "the_lib.h"
#include "parser.h"
#include "do_inf_op.h"

t_tree		*pth(t_data *ctrl,
		     unsigned int *index,
		     int sign,
		     unsigned int index_save)
{
  t_tree	*tmp;

  if (ctrl->str[index_save] == ctrl->op_base[OP_OPEN_PARENT_IDX])
  {
    ++index_save;
    if (!(tmp = ope_low(ctrl, &index_save)))
      return (NULL);
    if (ctrl->str[index_save++] == ctrl->op_base[OP_CLOSE_PARENT_IDX])
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

t_tree		*num_high(t_data *ctrl, unsigned int *index)
{
  unsigned int	index_save;
  t_tree	*test;
  t_nbr		*nbr;

  index_save = *index;
  the_space_consumer(ctrl, &index_save);
  if (!is_num(ctrl, &index_save))
    return (NULL);
  nbr = the_malloc(sizeof(t_nbr));
  nbr->nbr = ctrl->str + *index;
  test = create_node(NUM, nbr, NULL, NULL);
  *index = index_save;
  return (test);
}

t_tree		*num_low(t_data *ctrl, unsigned int *index)
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
  if ((tmp = num_high(ctrl, &index_save)))
  {
    tmp->sign = sign;
    *index = index_save;
    return (tmp);
  }
  return (pth(ctrl, index, sign, index_save));
}

t_tree		*ope_high(t_data *ctrl, unsigned int *index)
{
  unsigned int	index_save;
  t_tree	*node;
  t_tree	*node1;
  t_op		*op;

  index_save = *index;
  if (!(node = num_low(ctrl, &index_save)))
    return (NULL);
  *index = index_save;
  the_space_consumer(ctrl, &index_save);
  while (is_upopp(ctrl, index_save))
  {
    op = the_malloc(sizeof(t_op));
    op->c = ctrl->str[index_save++];
    node1 = create_node(OPP, op, node, NULL);
    node1->sign = PLUS;
    if (!(node1->right = num_low(ctrl, &index_save)))
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
    op = the_malloc(sizeof(t_op));
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
