/*
** main.c for lapin in /home/hamon_e/Piscine/Piscine_C_bistromathique/lapin
** 
** Made by Benoit Hamon
** Login   <hamon_e@epitech.net>
** 
** Started on  mer. oct. 28 22:09:23 2015 Benoit Hamon
** Last update mer. oct. 28 22:09:23 2015 Benoit Hamon
*/

#include <lapin.h>
#include <unistd.h>
#include "the_lapin.h"

char		*calc(char *str)		//GOTO BISTRO
{
  char	*res;
  res = strdup("415");
  printf("%s\n", res);
  return (res);
}

int		main()
{
  t_sfml	sfml;

  init(&sfml);
  bunny_set_key_response(keyboard);
  bunny_set_click_response(mouse);
  loop(&sfml);
  bunny_loop(sfml.img->windows, 100, &sfml);
  bunny_stop(sfml.img->windows);
}
