/*
** error.c for emacs in /home/kevin.ferchaud/CPool_bistro-matic/error
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sun Nov  6 23:08:25 2016 ferchaud kevin
** Last update Sun Nov  6 23:08:26 2016 ferchaud kevin
*/

#include "my.h"

int		check_same(char *str)
{
  int		a;
  int		b;
  char		*str2;

  str2 = my_strdup(str);
  a = 0;
  b = 1;
  while (str[a] != '\0' && str[a] != str2[b])
    {
      while (str2[b] != '\0' && str[a] != str2[b])
	b++;
      if (str[a] != str2[b])
	{
	  a += 1;
	  b = a + 1;
	}
    }
  if (str[a] == str[b])
    return (1);
  else
    return (0);
}

int		check_same2(char *base, char *ops)
{
  int		a;
  int		b;

  a = 0;
  b = 0;
  while (ops[a] != '\0' && ops[a] != base[b])
    {
      while (base[b] != '\0' && ops[a] != base[b])
	b++;
      if (ops[a] != base[b])
	{
	  b = 0;
	  a++;
	}
    }
  if (ops[a] == base[b])
    {
      put_error(SYNTAX_ERROR_MSG);
      exit(EXIT_USAGE);
    }
  else
    return (0);
}

int		check_same3(char *expr, char *bs, char *ops, int a)
{
  int		b;
  char		*o;

  b = 0;
  if ((o = malloc((my_strlen(bs) + my_strlen(ops) + 1) * sizeof(char))) == NULL)
    exit(EXIT_MALLOC);
  o[0] = '\0';
  my_strcat(o, bs);
  my_strcat(o, ops);
  while (expr[b] != '\0')
    {
      while (o[a] != '\0' && o[a] != expr[b])
	a++;
      if (o[a] == expr[b])
	{
	  a = 0;
	  b++;
	}
      else
	{
	  put_error(SYNTAX_ERROR_MSG);
	  exit(EXIT_USAGE);
	}
    }
  return (0);
}

int             check_base(char *base)
{
  if (my_strlen(base) < 2)
    {
      put_error(SYNTAX_ERROR_MSG);
      exit(EXIT_BASE);
    }
  if (check_same(base) == 1)
    {
      put_error(SYNTAX_ERROR_MSG);
      exit(EXIT_BASE);
    }
  else
    return (0);
}

int		check_ops(char *ops)
{
  if (my_strlen(ops) != 7)
    {
      put_error(SYNTAX_ERROR_MSG);
      exit(EXIT_OPS);
    }
  if (check_same(ops) == 1)
    {
      put_error(SYNTAX_ERROR_MSG);
      exit(EXIT_OPS);
    }
  else
    return (0);
}
