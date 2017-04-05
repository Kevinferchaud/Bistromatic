/*
** par2.c for emacs in /home/kevin.ferchaud/CPool_bistro-matic
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sun Nov  6 23:06:54 2016 ferchaud kevin
** Last update Sun Nov  6 23:06:55 2016 ferchaud kevin
*/

#include "my.h"

int             sign_par(char *str, int i)
{
  int           j;

  j = i;
  i--;
  while (str[i] != '(')
    {
      if (str[i] == ')')
	while (str[i] != '(')
	  i--;
      i--;
    }
  if (i >= 1)
    if ((str[i - 1] == '-' && ((i - 1) == 0)) || \
	(str[i - 1] == '-' && str[i - 2] == '('))
      return (--i);
  return (-1);
}

char            *sign_parless(char *str, int k, int j)
{
  int           r;
  char          *res;

  r = 0;
  if ((res = malloc(my_strlen(str) * sizeof(char))) == NULL)
    exit(EXIT_MALLOC);
  while (r < k)
    res[r] = str[r++];
  while (k < j)
    {
      if (str[k] != '-')
	res[r++] = str[k++];
      else
	k++;
    }
  while (str[j] != '\0')
    res[r++] = str[j++];
  res[r] = '\0';
  free(str);
  return (res);
}
