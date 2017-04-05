/*
** tools3.c for emacs in /home/kevin.ferchaud/CPool_bistro-matic
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sun Nov  6 23:07:46 2016 ferchaud kevin
** Last update Sun Nov  6 23:07:47 2016 ferchaud kevin
*/

#include "my.h"

char            *my_putsigne(char *res)
{
  char          *res2;
  int           cpt;

  cpt = 0;
  if ((res2 = malloc((my_strlen(res) + 2) * sizeof(char))) == NULL)
    exit (EXIT_MALLOC);
  res2[0] = '-';
  res2[1] = '\0';
  res2 = my_strcat(res2, res);
  return (res2);
}

char            *retzero(char *res)
{
  int   cpt;

  cpt = my_strlen(res) - 1;
  while (res[cpt] == '0' && cpt > 0)
    {
      cpt--;
    }
  res[cpt + 1] = '\0';
  return (my_revstr(res));
}

int             check_bigger(char *av1, char *av2)
{
  if (my_nstrlen(av1) > my_nstrlen(av2))
    return (0);
  else
    if (my_nstrlen(av2) > my_nstrlen(av1))
      return (1);
    else
      if (my_nstrcmp(av1, av2) > 0 && my_nstrlen(av1) == my_nstrlen(av2))
	return (0);
      else
	if (my_nstrcmp(av1, av2) < 0 && my_nstrlen(av1) == my_nstrlen(av2))
	  return (1);
  return (0);
}

int             my_nstrlen(char *str)
{
  int           i;
  int           r;

  i = 0;
  r = 0;
  while (str[i] == '-' || str[i] == '0')
    i++;
  while (str[i] != '\0')
    {
      r++;
      i++;
    }
  return (r);
}
