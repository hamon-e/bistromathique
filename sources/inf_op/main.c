/*
** main.c for main in /home/lin_p/infinadd2
** 
** Made by lin patrick
** Login   <lin_p@epitech.net>
** 
** Started on  Thu Oct 22 10:19:34 2015 lin patrick
** Last update Thu Oct 29 19:09:52 2015 lin patrick
*/

#include <stdlib.h>
#include "structnumber.h"

int	main(int argc, char *argv[])
{
  char	*result;

  if (argc == 3)
    {
      result = divinf(argv[1], argv[2]);
      if (result)
	my_putstr(result);
      my_putchar('\n');
      free(result);
    }
  else
    my_putstr("Invalid argument\n");
  return (0);
}
