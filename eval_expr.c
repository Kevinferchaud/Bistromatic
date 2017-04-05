/*
** eval_expr.c for emacs in /home/kevin.ferchaud/CPool_bistro-matic
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sun Nov  6 23:29:55 2016 ferchaud kevin
** Last update Sun Nov  6 23:29:56 2016 ferchaud kevin
*/

#include "my.h"

char		*make_neg_res(char *str)
{
  char		*res;
  int		i;

  i = 0;
  if ((res = malloc(sizeof(char) * (my_strlen(str) + 3))) == NULL)
    exit(EXIT_MALLOC);
  res[0] = '(';
  while (str[i] != '\0')
    {
      res[i + 1] = str[i];
      i++;
    }
  res[i + 1] = ')';
  res[i + 2] = '\0';
  free(str);
  return (res);
}

char		*replace_str(char *str, int i, char *tot)
{
  int		j;
  int		k;
  char		*res;
  char		*mid;

  j = i;
  k = 0;
  if ((res = malloc(sizeof(char) * my_strlen(str))) == NULL)
    exit(EXIT_MALLOC);
  if (tot[0] == '-')
    tot = make_neg_res(tot);
  j = count_first(str, j);
  while (k <= j)
    res[k] = str[k++];
  j = -1;
  while (tot[++j] != '\0')
    res[k++] = tot[j];
  j = count_last(str, i);
  while (str[j] != '\0')
    res[k++] = str[j++];
  res[k] = '\0';
  free(str);
  free(tot);
  return (res);
}

char		*eval_expr(char *str, char *base, char *op)
{
  int		res;
  char		*expr;
  int		i;

  i = -1;
  res = 0;
  expr = my_strdup(str);
  if (my_strcmp(base, "0123456789") != 0 || my_strcmp(op, "()+-*/%") != 0)
    expr = todecimal(op, base, str);
  expr = epur_expr(expr);
  expr = calcul_par(expr);
  expr = calcul_expr(expr);
  expr = clean_expr(expr);
  if (my_strcmp(base, "0123456789") != 0 || my_strcmp(op, "()+-*/%") != 0)
    expr = tobase(expr, base, op, my_strdup(expr));
  return (expr);
}
