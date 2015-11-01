/*
** list.c for sources in /home/hamon_e/Piscine/Piscine_C_bistromathique/bonus/sources/lapin/sources
** 
** Made by Benoit Hamon
** Login   <hamon_e@epitech.net>
** 
** Started on  Sun Nov 01 12:03:09 2015 Benoit Hamon
** Last update Sun Nov 01 12:03:09 2015 Benoit Hamon
*/

#include <stdlib.h>
#include <lapin.h>
#include "the_lapin.h"

t_list		*new_elem(char c)
{
  t_list	*a;

  a = malloc(sizeof(t_list));
  a->next = 0;
  a->data = c;
  return (a);
}

void	free_list(t_list *res)
{
  if (res->next)
    free_list(res->next);
  free(res);
}

static int	count_list(t_list *res)
{
  int		i;

  i = 0;
  while (res)
  {
    i++;
    res = res->next;
  }
  return (i);
}

char	*list_to_str(t_list *res)
{
  int	i;
  char	*str;

  str = malloc(sizeof(char) * (count_list(res) + 1));
  i = 0;
  while (res->next)
  {
    str[i++] = res->data;
    res = res->next;
  }
  str[i++] = res->data;
  str[i] = 0;
  free_list(res);
  return (str);
}

void	add_list(t_list *res, char c)
{
  if (res->data == '@')
    res->data = c;
  else
  {
    while (res->next)
      res = res->next;
    res->next = new_elem(c);
  }
}
