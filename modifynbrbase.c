/*
** modifynbrbase.c for emacs in /home/kevin.ferchaud/CPool_bistro-matic
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sun Nov  6 23:06:38 2016 ferchaud kevin
** Last update Sun Nov  6 23:06:39 2016 ferchaud kevin
*/

#include "my.h"

int		check_base_convert(char *str, int i, char *base)
{
  int		k;

  k = 0;
  while (base[k] != '\0')
    {
      if (base[k] == str[i])
	return (k);
      k++;
    }
  return (-1);
}

char		*calc_power(char *longe, int i)
{
  int		r;
  char		*tmp;
  char		*tmp2;

  r = 2;
  if (i == 0)
    return (my_strdup("1"));
  if (i == 1)
    return (longe);
  tmp2 = my_strdup(longe);
  tmp = multinf(longe, tmp2);
  while (r < i)
    {
      tmp = multinf(longe, tmp);
      r++;
    }
  return (tmp);
}

int		todecimalless(char *base, char *str, int i, char *res)
{
  int		k;
  int		j;
  char		*tmp;
  int		save;

  k = 0;
  tmp = my_strdup("0");
  while (check_base_convert(str, i, base) >= 0)
    i++;
  save = i;
  i--;
  while (i >= 0 && (j = check_base_convert(str, i, base)) >= 0)
    {
      tmp = addinf(tmp, multinf(chartoint(j),
				calc_power(chartoint(my_strlen(base)), k)));
      k++;
      i--;
    }
  my_strcat(res, tmp);
  return (save);
}

char		*todecimal(char *ops, char *base, char *str)
{
  char		*res;
  char		*ops2;
  int		i;
  int		j;
  int		r;

  i = 0;
  if ((res = malloc(my_strlen(str) * 2 * sizeof(char))) == NULL)
    exit(EXIT_MALLOC);
  res[0] = '\0';
  ops2 = my_strdup("()+-*/%");
  while (str[i] != '\0')
    {
      if (check_base_convert(str, i, base) >= 0)
	i = todecimalless(base, str, i, res);
      if ((j = check_base_convert(str, i, ops)) >= 0)
	{
	  r = my_strlen(res);
	  res[r] = ops2[j];
	  res[r + 1] = '\0';
	}
      i++;
    }
  return (res);
}

char            *tobase(char *str, char *nbase, char *op, char *str2)
{
  int		i;
  char		*res;
  char		*longe;

  if ((res = malloc(my_strlen(str) * 2 * sizeof(char))) == NULL)
    exit(EXIT_MALLOC);
  res[0] = '\0';
  str = my_lesssigne(str);
  longe = chartoint(my_strlen(nbase));
  while (check_bigger(str, longe) == 0)
    {
      i = my_strlen(res);
      res[i] = nbase[my_getnbr(modinf(str, longe))];
      res[i + 1] = '\0';
      str = divinf(str, longe);
    }
  i = my_strlen(res);
  res[i] = nbase[my_getnbr(str)];
  res[i + 1] = '\0';
  if (str2[0] == '-')
    {
      res[i + 1] = op[3];
      res[i + 2] = '\0';
    }
  return (my_revstr(res));
}
