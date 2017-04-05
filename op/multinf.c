/*
** multinf.c for emacs in /home/kevin.ferchaud/CPool_bistro-matic/op
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sun Nov  6 23:09:54 2016 ferchaud kevin
** Last update Sun Nov  6 23:09:55 2016 ferchaud kevin
*/

#include "my.h"

char	*add_in_res(char *res, int i, int sum, int k)
{
  int	j;

  j = 1;
  res[k + i] = sum % 10 + 48;
  if (sum > 9)
    {
      if (res[k + i + j] >= '0' && res[k + i + j] <= '9')
	{
	  while (res[k + i + j] >= '0' && res[k + i + j] <= '9')
	    {
	      sum = (sum / 10) + (res[k + i + j] - 48);
	      res[k + i + j++] = sum % 10 + 48;
	    }
	  if (sum > 9)
	    res[k + i + j] = sum / 10 + 48;
	  else
	    j--;
	}
      else
	res[k + i + j] = sum / 10 + 48;
    }
  while (res[k + i + j] >= '0' && res[k + i + j] <= '9')
    j++;
  res[k + i + j] = '\0';
  return (res);
}

char		*multinfless(char *nb1, char *nb2, char *res)
{
  int           sum;
  int           i;
  int           j;
  int		k;

  i = -1;
  while (nb2[++i] != '\0' && nb2[i] != '-')
    {
      j = -1;
      k = 0;
      while (nb1[++j] != '\0' && nb1[j] != '-')
	{
	  if (res[k + i] >= '0' && res[k + i] <= '9')
	    sum = (nb1[j] - 48) * (nb2[i] - 48) + (res[k + i] - 48);
	  else
	    sum = (nb1[j] - 48) * (nb2[i] - 48);
	  add_in_res(res, i, sum, k);
	  k++;
	}
    }
  return (res);
}

char		*multinf(char *nb1, char *nb2)
{
  char          *res;

  if ((res = malloc((my_strlen(nb1) + my_strlen(nb2) + 3) * sizeof(char))) == NULL)
    exit(EXIT_MALLOC);
  if (my_nstrcmp(nb1, "0") == 0 || my_nstrcmp(nb2, "0") == 0)
    return (my_strdup("0"));
  if (check_bigger(nb1, nb2) == 0)
    multinfless(my_revstr(nb1), my_revstr(nb2), res);
  else
    multinfless(my_revstr(nb2), my_revstr(nb1), res);
  my_revstr(nb1);
  my_revstr(nb2);
  res = retzero(res);
  if  ((nb1[0] == '-' && nb2[0] != '-') ||	\
       (nb1[0] != '-' && nb2[0] == '-'))
    res = my_putsigne(res);
  return (res);
}
