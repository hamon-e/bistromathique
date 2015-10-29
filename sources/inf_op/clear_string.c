/*
** clear_string.c for clear_string in /home/lin_p/infinadd2
** 
** Made by lin patrick
** Login   <lin_p@epitech.net>
** 
** Started on  Mon Oct 26 13:59:28 2015 lin patrick
** Last update Thu Oct 29 18:37:40 2015 lin patrick
*/

void	clear_str(char *str, int length)
{
  int	i;

  i = 0;
  while (i < length)
    {
      str[i] = '0';
      i = i + 1;
    }
  str[i] = '\0';
}
