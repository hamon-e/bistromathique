/*
** char_shift.c for char_shift in /home/lin_p/infinadd2
** 
** Made by lin patrick
** Login   <lin_p@epitech.net>
** 
** Started on  Mon Oct 26 16:49:34 2015 lin patrick
** Last update Thu Oct 29 14:23:32 2015 lin patrick
*/

void	char_shift(char *c, int length)
{
  int	i;

  i = 0;
  while (i < length - 1)
    {
      c[i] = c[i + 1];
      i = i + 1;
    }
  c[length - 1] = 0;
}
