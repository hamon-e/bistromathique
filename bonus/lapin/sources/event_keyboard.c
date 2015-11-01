/*
** event_keyboard.c for lapin in /home/hamon_e/Piscine/Piscine_C_bistromathique/lapin
** 
** Made by Benoit Hamon
** Login   <hamon_e@epitech.net>
** 
** Started on  mer. oct. 28 22:05:37 2015 Benoit Hamon
** Last update mer. oct. 28 22:05:37 2015 Benoit Hamon
*/

#include <lapin.h>
#include "the_lapin.h"

t_bunny_response	keyboard(t_bunny_event_state key,
				 t_bunny_keysym t,
				 void *data)
{
  t_sfml		*sfml;

  sfml = (t_sfml *)data;
  if (key == 1 && t >= BKS_0 && t <= BKS_9)
  {
    print_calc(sfml, t - 26);
    blit_n(sfml, sfml->img->boutons_p[t - 26]);
    add_list(sfml->res, t - 26 + '0');
  }
  else if (t == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}
