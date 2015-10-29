/*
** str_ft.c for str_ft in /home/lin_p/infinadd2
** 
** Made by lin patrick
** Login   <lin_p@epitech.net>
** 
** Started on  Thu Oct 22 15:03:18 2015 lin patrick
** Last update Thu Oct 29 18:41:10 2015 lin patrick
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i = i + 1;
  return (i);
}

int	my_strcmp(char *str1, char *str2)
{
  int	i;

  i = 0;
  while (str1[i])
    {
      if (str1[i] < str2[i])
	return (1);
      if (str1[i] > str2[i])
        return (-1);
      i = i + 1;
    }
  return (0);
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	 my_putstr(char *str)
{
  int   i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}
