/*
** char_shift.c for bistromathique in /home/morty/rendu/Piscine_C_bistromathique/sources/inf_op
**
** Made by Nicolas Goudal
** Login   <goudal_n@epitech.net>
**
** Started on  Thu Oct 29 23:28:04 2015 Nicolas Goudal
** Last update Thu Oct 29 23:28:09 2015 Nicolas Goudal
*/

void		char_shift(char *str, int length)
{
  int		i;

  i = 0;
  while (i < length - 1)
  {
    str[i] = str[i + 1];
    ++i;
  }
  str[length - 1] = 0;
}
