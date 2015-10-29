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
#include "the_lib.h"

typedef enum	e_type
{
  OPP,
  NUM
}		t_type;

typedef enum	e_sign
{
  PLUS = 1,
  MINUS = -1
}		t_sign;

typedef struct	s_tree
{
  t_type	type;
  t_sign	sign;
  char		*data;
  struct s_tree	*left;
  struct s_tree	*right;
}		t_tree;

t_tree *pth(char *str, int *index);

t_tree		*create_node(t_type type, char *str,
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

bool	is_upopp(char c)
{
  if (c == '/' || c == '*' || c == '%')
    return (true);
  return (false);
}

bool	is_lowopp(char c)
{
  if (c == '-' || c == '+')
    return (true);
  return (false);
}

bool	is_digit(char c)
{
  if (c <= '9' && c >= '0')
    return (true);
  return (false);
}

bool	is_num(char *str, int *index)
{
  if (!is_digit(str[*index]))
    return (false);
  while (is_digit(str[*index]))
    ++*index;
  return (true);
}

void	the_space_consumer(char *str, int *index)
{
  while (str[*index] == ' ')
    ++*index;
}

t_tree	*num(char *str, int *index)
{
  int	index_save;
  t_tree *test;

  index_save = *index;
  the_space_consumer(str, &index_save);
  test = create_node(NUM, str + index_save, NULL, NULL);
  if (!is_num(str, &index_save))
    return (NULL);
  if (str[index_save] != '.')
  {
    *index = index_save;
    return (test);
  }
  ++index_save;
  if (!is_num(str, &index_save))
    exit(4);
  *index = index_save;
  return (test);
}

t_tree *ope_high(char *str, int *index)
{
  int		index_save;
  t_tree	*node;
  t_tree	*node1;

  index_save = *index;
  if (!(node = pth(str, &index_save)))
    return (NULL);
  *index = index_save;
  the_space_consumer(str, &index_save);
  while (is_upopp(str[index_save]))
  {
    node1 = create_node(OPP, str + index_save++, node, NULL);
    node1->sign = PLUS;
    if (!(node1->right = pth(str, &index_save)))
      return (node);
    *index = index_save;
    the_space_consumer(str, &index_save);
    node = node1;
  }
  return (node);
}

t_tree *ope_low(char *str, int *index)
{
  int		index_save;
  t_tree	*node;
  t_tree	*node1;

  index_save = *index;
  if (!(node = ope_high(str, &index_save)))
    return (NULL);
  *index = index_save;
  the_space_consumer(str, &index_save);
  while (is_lowopp(str[index_save]))
  {
    node1 = create_node(OPP, str + index_save++, node, NULL);
    node1->sign = PLUS;
    if (!(node1->right = ope_high(str, &index_save)))
      return (NULL);
    *index = index_save;
    the_space_consumer(str, &index_save);
    node = node1;
  }
  the_space_consumer(str, index);
  return (node);
}

t_tree *pth(char *str, int *index)
{
  t_tree	*tmp;
  int		index_save;
  int		sign;

  sign = 1;
  index_save = *index;
  the_space_consumer(str, &index_save);
  while (is_lowopp(str[index_save]) || str[index_save] == ' ')
  {
    if (str[index_save] == '-')
      sign *= -1;
    ++index_save;
  }
  if ((tmp = num(str, &index_save)))
  {
    tmp->sign = sign;
    *index = index_save;
    return (tmp);
  }
  if (str[index_save] == '(')
  {
    ++index_save;
    if (!(tmp = ope_low(str, &index_save)))
      return (NULL);
    if (str[index_save++] == ')')
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

int	calc(t_tree *racine)
{
  char	opp;

  if (!racine)
    exit(4);
  opp = *(racine->data);
  if (racine->type == OPP)
  {
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
  return (atoi(racine->data) * racine->sign);
}

int	main(int ac, char **av)
{
  int	a;
  t_tree *bonjour;

  (void)ac;
  a = 0;
  bonjour = ope_low(av[1], &a);
  if (a != the_strlen(av[1]))
    exit(1);
  printf("%d\n", calc(bonjour));
  return (0);
}
