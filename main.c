/*
** main.c for emacs in /home/kevin.ferchaud/CPool_bistro-matic
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sun Nov  6 23:06:20 2016 ferchaud kevin
** Last update Sun Nov  6 23:06:22 2016 ferchaud kevin
*/

#include "my.h"

int		main(int ac, char **av)
{
  char		*res;

  res = check_error(ac, av);
  my_putstr(eval_expr(res, av[1], av[2]));
  return (0);
}
