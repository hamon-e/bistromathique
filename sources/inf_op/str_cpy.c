/*
** str_cpy.c for str_copy.c in /home/lin_p/infinadd2
** 
** Made by lin patrick
** Login   <lin_p@epitech.net>
** 
** Started on  Mon Oct 26 16:45:49 2015 lin patrick
** Last update Thu Oct 29 16:24:05 2015 lin patrick
*/

void    my_strcpy(char *src, char *dest, int start, int min)
{
  while (start >= min)
    {
      dest[start - min] = src[start];
      start = start - 1;
    }
}

void	my_strcpy2(char *src, char *dest, int idxsrc, int idxdest)
{
  while (idxsrc >= 0)
    {
      dest[idxdest] = src[idxsrc];
      idxdest = idxdest - 1;
      idxsrc = idxsrc - 1;
    }
}
