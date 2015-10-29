/*
** convert_to_ascii.c for convert in /home/lin_p/infinadd2
** 
** Made by lin patrick
** Login   <lin_p@epitech.net>
** 
** Started on  Thu Oct 22 17:24:27 2015 lin patrick
** Last update Thu Oct 29 18:35:46 2015 lin patrick
*/

void		a_to_i(char *str, int length)
{
  int		i;

  i = 0;
  while (i <= length)
    {
      str[i] = str[i] - '0';
      i = i + 1;
    }
}

void		i_to_a(char *str, int length)
{
  int		i;

  i = 0;
  while (i <= length)
    {
      str[i] = str[i] + '0';
      i = i + 1;
    }
}
