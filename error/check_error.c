/*
** check_error.c for emacs in /home/kevin.ferchaud/CPool_bistro-matic/error
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sun Nov  6 23:08:05 2016 ferchaud kevin
** Last update Sun Nov  6 23:08:06 2016 ferchaud kevin
*/

#include "my.h"

void		put_error(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      write(2, &str[i], 1);
      i++;
    }
}

char		*check_error(int ac, char **av)
{
  char          *expr;
  unsigned int  size;

  if (ac != 4)
    {
      put_error("Usage: ");
      put_error(av[0]);
      put_error(" base ops\"()+-*/%\" exp_len\n");
      exit(EXIT_USAGE);
    }
  size = my_getnbr(av[3]);
  expr = get_expr(size);
  check_base(av[1]);
  check_ops(av[2]);
  check_same2(av[1], av[2]);
  check_expr(expr, av[1], av[2]);
  check_expr2(expr, av[1], av[2]);
  check_expr3(expr, av[2]);
  check_same3(expr, av[1], av[2], 0);
  check_parenthese(expr, av[1], av[2]);
  check_beginend(expr, av[2], 0);
  check_doublops(expr, av[2], 0);
  check_empty(expr, av[1], av[2], 0);
  expr = change_str(expr, av[2]);
  return (expr);
}
