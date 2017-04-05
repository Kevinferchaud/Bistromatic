/*
** tools.c for emacs in /home/kevin.ferchaud/CPool_bistro-matic
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sun Nov  6 23:07:21 2016 ferchaud kevin
** Last update Sun Nov  6 23:07:21 2016 ferchaud kevin
*/

#include "my.h"

int             count_first(char *str, int j)
{
  j--;
  while (str[j] != '-' && str[j] != '*' && str[j] != '+' &&     \
	 str[j] != '/' && str[j] != '%' && j > 0)
    j--;
  if (j > 0)
    if (str[j - 1] == '(')
      j -= 2;
  if (j == 0)
    j--;
  return (j);
}

int             count_last(char *str, int i)
{
  int           j;

  j = 0;
  i++;
  if (str[i] == '(')
    {
      while (str[i] != ')')
	i++;
      i++;
      return (i);
    }
  else
    while (str[i] != '-' && str[i] != '*' && str[i] != '+' && \
	   str[i] != '/' && str[i] != '%' && str[i] != '\0')
      i++;
  return (i);
}
