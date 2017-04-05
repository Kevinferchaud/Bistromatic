/*
** error3.c for emacs in /home/kevin.ferchaud/CPool_bistro-matic/error
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sun Nov  6 23:08:45 2016 ferchaud kevin
** Last update Sun Nov  6 23:08:46 2016 ferchaud kevin
*/

#include "my.h"

int		error_msg()
{
  put_error(SYNTAX_ERROR_MSG);
  exit(EXIT_READ);
  return (0);
}

int             check_beginend(char *expr, char *ops, int a)
{
  int           end;

  end = my_strlen(expr) - 1;
  if (expr[0] == ops[4] || expr[0] == ops[5] || \
      expr[0] == ops[6])
    error_msg();
  while (ops[a] != '\0' && (expr[end] != ops[a] || expr[end] == ops[1]))
    a++;
  if (expr[end] == ops[a] && expr[end] != ops[1])
    error_msg();
  return (0);
}

int             check_doublops(char *expr, char *ops, int a)
{
  while (expr[a] != '\0')
    {
      if (expr[a] == ops[4] || expr[a] == ops[5] || \
	  expr[a] == ops[6])
	{
	  if (expr[a - 1] == ops[2])
	    error_msg();
	  if (expr[a - 1] == ops[4])
	    error_msg();
	  if (expr[a + 1] == ops[5] || expr[a - 1] == ops[5])
	    error_msg();
	  if (expr[a + 1] == ops[6] || expr[a - 1] == ops[6])
	    error_msg();
	}
      a++;
    }
  return (0);
}

int             check_parenth(char *str, char *base, int a)
{
  int           b;

  while (str[a] != '\0')
    {
      b = 0;
      while (str[a] != base[b] && base[b] != '\0')
	b++;
      if (str[a] == base[b])
	return (1);
      a++;
    }
  return (0);
}

int             check_empty(char *expr, char *base, char *ops, int a)
{
  char          *str;
  int           b;

  b = 0;
  if ((str = malloc((my_strlen(expr) + 1) * sizeof(char))) == NULL)
    exit(EXIT_MALLOC);
  while (expr[a] != '\0')
    {
      if (expr[a] == ops[0])
	{
	  while (expr[a + 1] != ops[1])
	    {
	      a++;
	      str[b] = expr[a];
	      b++;
	    }
	  str[b] = '\0';
	  if (check_parenth(str, base, 0) == 0)
	    error_msg();
	}
      a++;
    }
  return (0);
}
