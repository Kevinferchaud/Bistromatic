/*
** modinf.c for emacs in /home/kevin.ferchaud/CPool_bistro-matic/op
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sun Nov  6 23:09:43 2016 ferchaud kevin
** Last update Sun Nov  6 23:09:44 2016 ferchaud kevin
*/

#include "my.h"

char		*trouvemoilebug(char *str)
{
  char		*res;
  int		r;

  r = 0;
  if ((res = malloc((my_strlen(str) + 4) * sizeof(char))) == NULL)
    exit(EXIT_MALLOC);
  while (str[r] != '\0')
    res[r] = str[r++];
  res[r] = '\0';
  free(str);
  return (res);
}

char		*my_modless(char *av1, char *tmp, int i)
{
  int		k;

  k = my_strlen(tmp);
  tmp[k] = av1[i];
  tmp[k + 1] = '\0';
  return (tmp);
}

char		*create_my_malloc(char *longe)
{
   char          *res;

   if ((res = malloc((my_strlen(longe) + 1) * sizeof(char))) == NULL)
     exit(EXIT_MALLOC);
   return (res);
}

char            *my_mod(char *av1, char *av2, int i, int r)
{
  char		*res;
  char          *tmp;
  int		j;

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
  return (tmp);
}

char            *modinf(char *av1, char *av2)
{
  char          *res;

  if (my_nstrcmp(av2, "0") == 0)
    {
      put_error(ERROR_MSG);
      exit(EXIT_USAGE);
    }
  if (check_bigger(av1, av2) == 1)
    return (av1);
  if (my_nstrcmp(av1, "0") == 0)
    return (my_strdup("0"));
  res = my_mod(my_nstrdup(av1), my_nstrdup(av2), 0, -1);
  res = retzero(my_revstr(res));
  if  (av1[0] == '-')
    res = my_putsigne(res);
  return (res);
}
