/*
** par.c for emacs in /home/kevin.ferchaud/CPool_bistro-matic
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sun Nov  6 23:07:09 2016 ferchaud kevin
** Last update Sun Nov  6 23:07:09 2016 ferchaud kevin
*/

#include "my.h"

char            *check_parless(char *str, int k, int i, int r)
{
  char          *calcul;
  char          *res;
  int           j;

  j = k;
  if ((calcul = malloc(my_strlen(str) * sizeof(char))) == NULL)
    exit(EXIT_MALLOC);
  if ((res = malloc(my_strlen(str) * sizeof(char))) == NULL)
    exit(EXIT_MALLOC);
  while (++k < i)
    calcul[r++] = str[k];
  calcul[r] = '\0';
  calcul = calcul_expr(calcul);
  r = 0;
  while (r < j)
    res[r] = str[r++];
  k = 0;
  while (calcul[k] != '\0')
    res[r++] = calcul[k++];
  while (str[++i] != '\0')
    res[r++] = str[i];
  res[r] = '\0';
  free(calcul);
  return (res);
}

int             check_par(char *str, int i)
{
  int           sign;

  sign = 0;
  i--;
  while (str[i] != '(' && i > 0)
    {
      if (str[i] == ')')
	{
	  while (str[i] != '(')
	    i--;
	  i--;
	}
      if (str[i] == '*' || str[i] == '-' ||  \
	  str[i] == '+' || str[i] == '/' || str[i] == '%')
	if (str[i - 1] != '(')
	  sign++;
      if (i > 0 && str[i] != '(')
	i--;
    }
  if (sign > 0)
    return (i);
  return (-1);
}

char            *clean_parless(char *str, int i, int j)
{
  char          *res;
  int           r;

  r = 0;
  if ((res = malloc(my_strlen(str) * sizeof(char))) == NULL)
    exit(EXIT_MALLOC);
  while (r < i)
    res[r] = str[r++];
  while (++i < j)
    res[r++] = str[i];
  while (str[++j] != '\0')
    res[r++] = str[j];
  res[r] = '\0';
  free(str);
  return (res);
}

int             clean_par(char *str, int i)
{
  int           j;
  int           k;

  j = i;
  i--;
  while (str[i] != '(')
    {
      if (str[i] == ')')
	while (str[i] != '(')
	  i--;
      i--;
    }
  k = i;
  k++;
  while (str[k] >= '0' && str[k] <= '9')
    k++;
  if (k == j || (str[i + 1] == '(' && str[j - 1] == ')'))
    return (i);
  return (-1);
}

char            *calcul_par(char *str)
{
  int           i;
  int           k;

  i = -1;
  while (str[++i] != '\0')
    {
      if (str[i] == ')')
	{
	  if ((k = check_par(str, i)) >= 0)
	    str = check_parless(str, k, i, 0);
	  else
	    if ((k = clean_par(str, i)) >= 0)
	      str = clean_parless(str, k, i);
	    else
	      if ((k = sign_par(str, i)) >= 0)
		str = sign_parless(str, k, i);
	  if (k != -1)
	    i = -1;
	}
      str = epur_expr(str);
    }
  return (str);
}
