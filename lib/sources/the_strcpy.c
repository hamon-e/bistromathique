/*
** the_strcpy.c for bistromathique in /home/morty/rendu/Piscine_C_bistromathique/lib/sources
**
** Made by Nicolas Goudal
** Login   <goudal_n@epitech.net>
**
** Started on  Fri Oct 30 03:45:02 2015 Nicolas Goudal
** Last update Fri Oct 30 03:46:50 2015 Nicolas Goudal
*/

char		*the_strcpy(char *dest, char const *src)
{
  int		i;

  i = 0;
  while (src[i])
  {
    dest[i] = src[i];
    ++i;
  }
  dest[i] = '\0';
  return (dest);
}
