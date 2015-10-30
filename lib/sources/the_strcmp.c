/*
** the_strcmp.c for bistromathique in /home/morty/rendu/Piscine_C_bistromathique/lib/sources
**
** Made by Nicolas Goudal
** Login   <goudal_n@epitech.net>
**
** Started on  Fri Oct 30 04:37:12 2015 Nicolas Goudal
** Last update Fri Oct 30 04:37:21 2015 Nicolas Goudal
*/

int	the_strcmp(char const *s1, char const *s2)
{
  int	i;

  i = 0;
  while (s1[i] && s2[i] && s1[i] == s2[i])
    ++i;
  return (s1[i] - s2[i]);
}
