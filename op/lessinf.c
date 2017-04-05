/*
** lessinf.c for emacs in /home/kevin.ferchaud/CPool_bistro-matic/op
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sun Nov  6 23:09:30 2016 ferchaud kevin
** Last update Sun Nov  6 23:09:31 2016 ferchaud kevin
*/

#include "my.h"

char            *calcul_less(char *nb1, char *nb2)
{
  char          *res;
  int           tmp;
  int           i;
  int           j;

  if ((res = malloc((my_strlen(nb1) + my_strlen(nb2)) * sizeof(char))) == NULL)
    exit(EXIT_MALLOC);
  i = 0;
  tmp = 0;
  j = 0;
  while (nb1[i] != '\0' && nb1[i] != '-')
    {
      if (nb2[j] != '\0' && nb2[j] != '-')
	tmp = (nb1[i] - 48) - ((nb2[j] - 48) + tmp / 10);
      else
	tmp = (nb1[i] - 48) - tmp / 10;
      if (tmp < 0)
	tmp = 10 - tmp * -1  + 10;
      res[i++] = tmp % 10 + 48;
      if (nb2[j] != '\0' && nb2[j] != '-')
	j++;
    }
  res[i] = '\0';
  return (res);
}

char            *aff_less(char *av1, char *av2, char *res)
{
  int           i;

  i = my_strlen(res) - 1;
  while (res[i] == '0' && i > 0)
    {
      res[i] = '\0';
      i--;
    }
  res = my_revstr(res);
  if (my_nstrlen(my_revstr(av2)) > my_nstrlen(my_revstr(av1)) && av1[0] != '-')
    res = my_putsigne(res);
  else
    if (av1[0] == '-' && (my_nstrlen(av1) > my_nstrlen(av2)))
      res = my_putsigne(res);
    else
      if (my_nstrcmp(av1, av2) < 0 && my_nstrlen(av1) == my_nstrlen(av2) && \
	  av1[0] != '-')
	res = my_putsigne(res);
      else
	if (my_nstrcmp(av1, av2) > 0 && my_nstrlen(av1) == my_nstrlen(av2) && \
	    av1[0] == '-')
	  res = my_putsigne(res);
  return (res);
}

char		*lessinfless(char *av1, char *av2)
{
  char          *res;

  if (my_nstrlen(av1) > my_nstrlen(av2))
    res = calcul_less(my_revstr(av1), my_revstr(av2));
  else
    if (my_nstrlen(av2) > my_nstrlen(av1))
      res = calcul_less(my_revstr(av2), my_revstr(av1));
    else
      if (my_nstrcmp(av1, av2) >= 0)
	res = calcul_less(my_revstr(av1), my_revstr(av2));
      else
	if (my_nstrcmp(av1, av2) < 0)
	  res = calcul_less(my_revstr(av2), my_revstr(av1));
  res = aff_less(av1, av2, res);
  return (res);
}

char		*my_lesssigne(char *str)
{
  int		i;
  int		r;
  char		*res;

  i = 0;
  r = 0;
  if ((res = malloc(my_strlen(str) * sizeof(char))) == NULL)
    exit(EXIT_MALLOC);
  while (str[i] == '-')
    i++;
  while (str[i] != '\0')
    res[r++] = str[i++];
  res[r] = '\0';
  return (res);
}

char            *lessinf(char *av1, char *av2)
{
  char		*res;

  if (av1[0] == '-' && av2[0] != '-')
    res = addinf(av1, my_putsigne(av2));
  else
    if (av1[0] != '-' && av2[0] == '-')
      res = addinf(av1, my_lesssigne(av2));
    else
      res = lessinfless(av1, av2);
  return (res);
}
