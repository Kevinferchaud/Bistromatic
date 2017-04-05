/*
** expr.c for emacs in /home/kevin.ferchaud/CPool_bistro-matic
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sun Nov  6 23:29:37 2016 ferchaud kevin
** Last update Sun Nov  6 23:29:38 2016 ferchaud kevin
*/

#include "my.h"

char            *calcul_exprless(char *str)
{
  int           i;
  int           j;

  i = 0;
  j = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '(')
	j++;
      if (str[i] == ')')
	j--;
      if ((str[i] == '+' || str[i] == '-') && j == 0 && i != 0)
	{
	  str = sums(str, i);
	  i = 0;
	}
      else
	i++;
    }
  return (str);
}

char            *calcul_expr(char *str)
{
  int           i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '*' || str[i] == '/' || str[i] == '%')
	{
	  str = factors(str, i);
	  i = 0;
	}
      i++;
    }
  str = calcul_exprless(str);
  return (str);
}

char            *clean_expr(char *str)
{
  int           i;
  char          *res;
  int           r;

  i = 0;
  r = 0;
  if (str != NULL)
    if (str[0] != '(')
      return (str);
  if ((res = malloc((my_strlen(str) - 1) * sizeof(char))) == NULL)
    exit(EXIT_MALLOC);
  while (str[i] != '\0')
    {
      if (str[i] != '(' && str[i] != ')')
	res[r++] = str[i];
      i++;
    }
  free(str);
  res[r] = '\0';
  return (res);
}

char            *epur_exprless(char *str, int j, int i)
{
  char          *res;
  int           r;

  r = 0;
  if ((res = malloc((my_strlen(str) + 3) * sizeof(char))) == NULL)
    exit(EXIT_MALLOC);
  while (r < j)
    res[r] = str[r++];
  res[r++] = '(';
  while (j <= i)
    res[r++] = str[j++];
  res[r++] = ')';
  while (str[++i] != '\0')
    res[r++] = str[i];
  res[r] = '\0';
  free(str);
  return (res);
}

char            *epur_expr(char *str)
{
  int           i;
  int           j;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '+' || str[i] == '/' || \
	  str[i] == '*' || str[i] == '%')
	if (str[i + 1] == '-')
	  {
	    i++;
	    j = i;
	    if (str[i + 1] >= '0' && str[i + 1] <= '9')
	      {
		i++;
		while (str[i] >= '0' && str[i] <= '9')
		  i++;
		i--;
		str = epur_exprless(str, j, i);
		i = -1;
	      }
	  }
      i++;
    }
  return (str);
}
