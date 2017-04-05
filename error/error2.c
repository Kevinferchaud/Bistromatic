/*
** error2.c for emacs in /home/kevin.ferchaud/CPool_bistro-matic/error
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sun Nov  6 23:08:35 2016 ferchaud kevin
** Last update Sun Nov  6 23:08:36 2016 ferchaud kevin
*/

#include "my.h"

int		check_parenthese(char *expr, char *base, char *ops)
{
  int		a;
  int		b;
  int		c;

  a = 0;
  b = 0;
  c = 0;
  while (expr[a] != '\0')
    {
      if (expr[a] == ops[0])
	b += 1;
      if (expr[a] == ops[1])
	c += 1;
      a++;
    }
  if (b != c)
    {
      put_error(SYNTAX_ERROR_MSG);
      exit(EXIT_READ);
    }
  else
    return (0);
}

int		check_expr(char *expr, char *base, char *ops)
{
  int		a;
  int		b;

  a = 0;
  while (expr[a] != '\0')
    {
      if (expr[a] == ops[0])
	{
	  b = 0;
	  while (ops[b] != '\0' && expr[a - 1] != ops[b])
	    b++;
	  if (expr[a - 1] != ops[b])
	    {
	      put_error(SYNTAX_ERROR_MSG);
	      exit(EXIT_READ);
	    }
	}
      a++;
    }
  return (0);
}

int		check_expr2(char *expr, char *base, char *ops)
{
  int		a;
  int		b;

  a = 0;
  while (expr[a] != '\0')
    {
      if (expr[a] == ops[1])
	{
	  b = 0;
	  while (ops[b] != '\0' && expr[a + 1] != ops[b])
	    b++;
	  if (expr[a + 1] != ops[b])
	    {
	      put_error(SYNTAX_ERROR_MSG);
	      exit(EXIT_READ);
	    }
	}
      a++;
    }
  return (0);
}

int		check_expr3(char *expr, char *ops)
{
  int		a;
  int		f;

  a = 2;
  f = my_strlen(expr) - 1;
  while (ops[a] != '\0')
    {
      if (expr[f] == ops[a])
	{
	  put_error(SYNTAX_ERROR_MSG);
	  exit(EXIT_READ);
	}
      a++;
    }
  return (0);
}

char		*get_expr(unsigned int size)
{
  char		*expr;
  int		len;

  if (size <= 0)
    {
      put_error(SYNTAX_ERROR_MSG);
      exit(EXIT_SIZE_NEG);
    }
  expr = malloc(size + 1);
  if (expr == 0)
    {
      put_error(ERROR_MSG);
      exit (EXIT_MALLOC);
    }
  if (read(0, expr, size) != size)
    {
      put_error(ERROR_MSG);
      exit (EXIT_READ);
    }
  expr[size] = 0;
  return (expr);
}
