/*
** tools2.c for emacs in /home/kevin.ferchaud/CPool_bistro-matic
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sun Nov  6 23:07:32 2016 ferchaud kevin
** Last update Sun Nov  6 23:07:33 2016 ferchaud kevin
*/

#include "my.h"

int             count_int(int tot)
{
  int           i;

  i = 0;
  while ((tot /= 10) != 0)
    i++;
  return (i);
}

char            *chartointless(char *res, int nb, int div)
{
  int           i;
  int           tmp;

  i = 0;
  while (div != 0)
    {
      tmp = nb / div;
      if (tmp < 0)
	tmp *= -1;
      res[i++] = tmp + '0';
      nb %= div;
      div /= 10;
    }
  res[i] = '\0';
  return (res);
}

int     my_nstrcmp(char *s1, char *s2)
{
  int   i;
  int   j;

  i = 0;
  j = 0;
  while (s1[i] == '-' || s1[i] == '0')
    i++;
  while (s2[j] == '-' || s2[j] == '0')
    j++;
  while ((s1[i] != '\0' || s2[j] != '\0') && s1[i] == s2[j])
    {
      i++;
      j++;
    }
  return (s1[i] - s2[j]);
}

char            *chartoint(int nb)
{
  char          *res;
  int           tmp;
  int           div;

  if ((res = malloc(sizeof(char) * (count_int(nb) + 10))) == NULL)
    exit(EXIT_MALLOC);
  div = 1;
  tmp = nb;
  while ((nb /= 10) != 0)
    div *= 10;
  nb = tmp;
  res = chartointless(res, nb, div);
  return (res);
}

char            *my_nstrdup(char *str)
{
  char           *res;
  int            i;
  int            r;

  if ((res = malloc((my_nstrlen(str) + 1) * sizeof(char))) == NULL)
    exit(EXIT_MALLOC);
  i = 0;
  r = 0;
  while (str[i] == '0' || str[i] == '-')
    i++;
  while (str[i] != '\0')
    res[r++] = str[i++];
  res[r] = '\0';
  return (res);
}
