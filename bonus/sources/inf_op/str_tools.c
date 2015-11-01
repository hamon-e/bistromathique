/*
** str_tools.c for bistromathique in /home/morty/rendu/Piscine_C_bistromathique/sources/inf_op
**
** Made by Nicolas Goudal
** Login   <goudal_n@epitech.net>
**
** Started on  Thu Oct 29 23:25:44 2015 Nicolas Goudal
** Last update Thu Oct 29 23:29:16 2015 Nicolas Goudal
*/

void		a_to_i(char *str, int length)
{
  int		i;

  i = 0;
  while (i <= length)
  {
    str[i] -= '0';
    ++i;
  }
}

void		i_to_a(char *str, int length)
{
  int		i;

  i = 0;
  while (i <= length)
  {
    str[i] += '0';
    ++i;
  }
}

void		copy_str(char *src, char *dest, int start, int min)
{
  while (start >= min)
  {
    dest[start - min] = src[start];
    --start;
  }
}

void		rev_copy_str(char *src, char *dest, int idxsrc, int idxdest)
{
  while (idxsrc >= 0)
  {
    dest[idxdest] = src[idxsrc];
    --idxdest;
    --idxsrc;
  }
}

void		clear_str(char *str, int length)
{
  int		i;

  i = 0;
  while (i < length)
  {
    str[i] = '0';
    ++i;
  }
  str[i] = '\0';
}
