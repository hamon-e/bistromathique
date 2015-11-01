/*
** peg_tools.c for bistromathique in /home/morty/rendu/Piscine_C_bistromathique/sources/parser
**
** Made by Nicolas Goudal
** Login   <goudal_n@epitech.net>
**
** Started on  Thu Oct 29 19:42:05 2015 Nicolas Goudal
** Last update Thu Oct 29 19:42:59 2015 Nicolas Goudal
*/

#include "the_lib.h"
#include "parser.h"

t_tree		*create_node(t_type type, void *str,
			     t_tree *left, t_tree *right)
{
  t_tree	*new;

  new = the_malloc(sizeof(t_tree));
  new->type = type;
  new->data = str;
  new->right = right;
  new->left = left;
  return (new);
}

void	the_space_consumer(t_data *ctrl, unsigned int *index)
{
  while (ctrl->str[*index] == ' ' || ctrl->str[*index] == '\t' ||
         ctrl->str[*index] == '\n')
    ++*index;
}
