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
#include "the_lib.h"
#include "the_lapin.h"

t_op_nbr	*calc(t_data *ctrl, char *str)
{
  t_tree	*root;
  t_op_nbr	*result;
  unsigned int	index;

  index = 0;
  (ctrl->nbr_base = the_malloc(11));
  ctrl->nbr_base = "0123456789";
  ctrl->op_base = the_malloc(8);
  ctrl->op_base= "()+-*/%";
  ctrl->str = str;
  root = ope_low(ctrl, &index);
  if (the_strlen(ctrl->str) != index)
    return (NULL);
  result = do_inf_op(ctrl, root);
  return (result);
}

int		main()
{
  t_sfml	sfml;
  t_data	ctrl;

  sfml.ctrl = &ctrl;
  init_sfml(&sfml);
  bunny_set_key_response(keyboard);
  bunny_set_click_response(mouse);
  loop(&sfml);
  bunny_loop(sfml.img->windows, 100, &sfml);
  bunny_stop(sfml.img->windows);
  return (0);
}
