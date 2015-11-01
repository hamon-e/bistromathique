/*
** free_tree.c for parser in /home/hamon_e/Piscine/tmp/tmp/Piscine_C_bistromathique/sources/parser
** 
** Made by Benoit Hamon
** Login   <hamon_e@epitech.net>
** 
** Started on  Sat Oct 31 21:40:38 2015 Benoit Hamon
** Last update Sat Oct 31 21:40:38 2015 Benoit Hamon
*/

#include <stdlib.h>
#include "parser.h"

void	free_tree(t_tree *root)
{
  if (root->left)
    free_tree(root->left);
  if (root->right)
    free_tree(root->right);
  free(root);
}
