/*
** calcul.c for emacs in /home/kevin.ferchaud/CPool_bistro-matic
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sun Nov  6 23:04:50 2016 ferchaud kevin
** Last update Sun Nov  6 23:04:53 2016 ferchaud kevin
*/

#include "my.h"

char		*recup_nb1(char *str, int i, int r)
{
  int           sign;
  char		*nb1;

  sign = 1;
  if ((nb1 = malloc(my_strlen(str) * sizeof(char))) == NULL)
    exit(EXIT_MALLOC);
  i--;
  while (str[i] != '-' && str[i] != '*' && str[i] != '+' &&     \
	 str[i] != '/' && str[i] != '%' && i > 0)
    i--;
  if ((i == 0 && str[i] == '-'))
      sign *= -1;
  else
    if (i > 0)
      if (str[i - 1] == '(')
	sign *= -1;
  if (i != 0 || (i == 0 && str[i] == '-'))
    i++;
  while (str[i] != ')' && str[i] != '-' && str[i] != '*' &&     \
	 str[i] != '+' && str[i] != '/' && str[i] != '%')
    nb1[r++] = str[i++];
  nb1[r] = '\0';
  if (sign < 0)
    nb1 = my_putsigne(nb1);
  return (nb1);
}

char		*recup_nb2(char *str, int i)
{
  char		*nb2;
  int           sign;
  int		r;

  sign = 1;
  i++;
  r = 0;
  if ((nb2 = malloc(my_strlen(str) * sizeof(char))) == NULL)
    exit(EXIT_MALLOC);
  if (str[i] == '(')
    {
      sign *= -1;
      i++;
      while (str[++i] != ')')
	nb2[r++] = str[i];
    }
  else
    while (str[i] != '-' && str[i] != '*' && str[i] != '+' &&   \
	   str[i] != '/' && str[i] != '%' && str[i] != '\0')
      nb2[r++] = str[i++];
  nb2[r] = '\0';
  if (sign < 0)
    nb2 = my_putsigne(nb2);
  return (nb2);
}

char            *factors(char *str, int i)
{
  int           j;
  char          *res;
  char          *sign;
  char		*(*tab[3])(char *, char *);

  j = -1;
  sign = my_strdup("*/%");
  tab[0] = &multinf;
  tab[1] = &divinf;
  tab[2] = &modinf;
  while (sign[++j] != '\0')
    if (sign[j] == str[i])
      res = tab[j](recup_nb1(str, i, 0), recup_nb2(str, i));
  str = replace_str(str, i, res);
  free(sign);
  return (str);
}

char            *sums(char *str, int i)
{
  int           j;
  char          *res;
  char          *sign;
  char          *(*tab[2])(char *, char *);

  j = -1;
  sign = my_strdup("+-");
  tab[0] = &addinf;
  tab[1] = &lessinf;
  while (sign[++j] != '\0')
    if (sign[j] == str[i])
      res = tab[j](recup_nb1(str, i, 0), recup_nb2(str, i));
  str = replace_str(str, i, res);
  free(sign);
  return (str);
}
