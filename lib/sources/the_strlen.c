/*
** the_strlen.c for bistromathique in /home/morty/rendu/Piscine_C_bistromathique/lib/sources
**
** Made by Nicolas Goudal
** Login   <goudal_n@epitech.net>
**
** Started on  Thu Oct 29 20:35:28 2015 Nicolas Goudal
** Last update Thu Oct 29 20:36:03 2015 Nicolas Goudal
*/

unsigned int	the_strlen(char const *str)
{
  unsigned int	i;

  i = 0;
  while (str[i])
    ++i;
  return (i);
}
