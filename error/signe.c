/*
** signe.c for emacs in /home/kevin.ferchaud/CPool_bistro-matic/error
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sun Nov  6 23:08:59 2016 ferchaud kevin
** Last update Sun Nov  6 23:08:59 2016 ferchaud kevin
*/

#include "my.h"

int             check_moins(char *expr, char *ops, int a)
{
  int           nb;

  nb = 0;
  while (expr[a] == ops[3] || expr[a] == ops[2])
    {
      if (expr[a] == ops[3])
	nb++;
      a++;
    }
  return (nb);
}

int             avancement(char *expr, char *ops, int a)
{
  int           nb;

  nb = 0;
  while (expr[a] == ops[2] || expr[a] == ops[3])
    {
      nb++;
      a++;
    }
  return (nb);
}

char            *change_str2(char *expr, char *ops, int a, int b)
{
  char          *str;

  str = malloc(my_strlen(expr) + 1);
  while (expr[a] != '\0')
    {
      if ((expr[a] == ops[3]) || (expr[a] == ops[2]))
	{
	  if ((check_moins(expr, ops, a) % 2) == 1)
	    str[b] = ops[3];
	  if ((check_moins(expr, ops, a) % 2) == 0 &&		 \
	      (expr[a - 1] != ops[4] && expr[a - 1] != ops[5] && \
	       expr[a - 1] != ops[5]))
	    str[b] = ops[2];
	  if ((check_moins(expr, ops, a) % 2) == 0 && \
	      (expr[a - 1] == ops[4] || expr[a - 1] == ops[5] || \
	       expr[a - 1] == ops[6]))
	    b--;
	  a += avancement(expr, ops, a);
	  b++;
	}
      str[b++] = expr[a++];
    }
  str[b] = '\0';
  return (str);
}

char		*change_str(char *expr, char *ops)
{
  char		*str;
  int		a;

  a = 0;
  if ((str = malloc((my_strlen(expr) + 1) * sizeof(char))) == NULL)
    exit (EXIT_MALLOC);
  str = change_str2(expr, ops, 0, 0);
  free(expr);
  if (str[a] == ops[2])
    {
      while (str[a] != '\0')
	{
	  str[a] = str[a + 1];
	  a++;
	}
    }
  return (str);
}
