/*
** divinf.c for emacs in /home/kevin.ferchaud/CPool_bistro-matic/op
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sun Nov  6 23:10:04 2016 ferchaud kevin
** Last update Sun Nov  6 23:10:05 2016 ferchaud kevin
*/

#include "my.h"

char		*find_div(char *av1, char *av2, char *res)
{
  char		*mult;
  int		i;

  i = 1;
  mult = multinf(av2, chartoint(i));
  while (check_bigger(av1, mult) == 0)
    {
      i++;
      mult = multinf(av2, chartoint(i));
    }
  if (i > 0)
    i--;
  mult = multinf(av2, chartoint(i));
  res = my_strcat(res, chartoint(i));
  return (mult);
}

char		*find_first(char *av1, char *av2)
{
  int		i;
  int		j;
  char		*div;

  i = 1;
  if ((div = malloc((my_strlen(av1) + 1) * sizeof(char))) == NULL)
    exit(EXIT_MALLOC);
  div[0] = av1[0];
  div[1] = '\0';
  while (check_bigger(div, av2) == 1)
    {
      div[i] = av1[i];
      div[i + 1] = '\0';
      i++;
    }
  return (div);
}

char            *my_div(char *av1, char *av2, int i, int r)
{
  char		*res;
  char          *tmp;
  int           j;

  res = create_my_malloc(av1);
  tmp = find_first(av1, av2);
  i = my_strlen(tmp) - 2;
  res[0] = '\0';
  j = 0;
  while (av1[++i] != '\0')
    {
      if (j == 1)
	tmp = my_modless(av1, tmp, i);
      if (check_bigger(tmp, av2) == 1)
	res = my_strcat(res, "0");
      else
	while (check_bigger(tmp, av2) == 0 && ++r >= 0)
	  tmp = lessinf(tmp, av2);
      tmp = trouvemoilebug(tmp);
      if (r >= 0)
	my_strcat(res, chartoint(++r));
      r = -1;
      j = 1;
    }
  return (res);
}

char		*divinf(char *av1, char *av2)
{
  char		*res;

  if (my_nstrcmp(av2, "0") == 0)
    {
      put_error(ERROR_MSG);
      exit(EXIT_USAGE);
    }
  if (check_bigger(av1, av2) == 1)
    return (my_strdup("0"));
  if (my_nstrcmp(av1, "0") == 0)
    return (my_strdup("0"));
  res = my_div(my_nstrdup(av1), my_nstrdup(av2), 0, -1);
  if  ((av1[0] == '-' && av2[0] != '-') || \
       (av1[0] != '-' && av2[0] == '-'))
    res = my_putsigne(res);
  return (res);
}
