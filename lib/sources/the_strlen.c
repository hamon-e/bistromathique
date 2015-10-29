/*
** the_strlen.c for Bistromathique in /home/morty/rendu/Piscine_C_bistromathique/lib/sources
**
** Made by Nicolas Goudal
** Login   <goudal_n@epitech.net>
**
** Started on  Thu Oct 29 02:47:00 2015 Nicolas Goudal
** Last update Thu Oct 29 02:47:27 2015 Nicolas Goudal
*/

int	the_strlen(char const *str)
{
  int	i;

  i = 0;
  while (str[i])
    ++i;
  return (i);
}
