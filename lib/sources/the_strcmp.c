/*
** the_strcmp.c for Bistromathique in /home/morty/rendu/Piscine_C_bistromathique/lib/sources
**
** Made by Nicolas Goudal
** Login   <goudal_n@epitech.net>
**
** Started on  Thu Oct 29 02:42:44 2015 Nicolas Goudal
** Last update Thu Oct 29 02:46:43 2015 Nicolas Goudal
*/

int	the_strcmp(char const *s1, char const *s2)
{
  int	i;

  i = 0;
  while (s1[i] && s2[i] && s1[i] == s2[i])
    ++i;
  return (s1[i] - s2[i]);
}
