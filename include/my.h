/*
** my.h for emacs in /home/kevin.ferchaud/CPool_bistro-matic
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sun Nov  6 23:30:11 2016 ferchaud kevin
** Last update Sun Nov  6 23:30:12 2016 ferchaud kevin
*/

#ifndef MY_H_
# define MY_H_

#include <stdlib.h>
#include <unistd.h>
#include "bistro-matic.h"

void	my_putchar(char);
int	my_isneg(int);
int	my_put_nbr(int);
int	my_swap(int *, int *);
int	my_putstr(char *);
int	my_strlen(char *);
int	my_getnbr(char *);
void	my_sort_int_tab(int *, int);
int	my_power_rec(int, int);
int	my_square_root(int);
int	my_is_prime(int);
int	my_find_prime_sup(int);
char	*my_strcpy(char *, char *);
char	*my_strncpy(char *, char *, int);
char	*my_revstr(char *);
char	*my_strstr(char *, char *);
int	my_strcmp(char *, char *);
int	my_strncmp(char *, char *, int);
char	*my_strupcase(char *);
char	*my_strlowcase(char *);
char	*my_strcapitalize(char *);
int	my_str_isalpha(char *);
int	my_str_isnum(char *);
int	my_str_islower(char *);
int	my_str_isupper(char *);
int	my_str_isprintable(char *);
int	my_showstr(char *);
int	my_showmem(char *, int);
char	*my_strcat(char *, char *);
char	*my_strncat(char *, char *, int);
char	**my_str_to_wordtab(char *);
char	*my_strdup(char *);
int	check_char(char);
int	make_pointer(char *, int);
int	make_long(char *, int);
int	counts_word(char *);
int	my_show_wordtab(char **);
char	*multinf(char *, char *);
char	*lessinf(char *, char *);
char	*addinf(char *, char *);
char	*divinf(char *, char *);
char	*modinf(char *, char *);
char	*epur_exprless(char *, int, int);
char	*epur_expr(char *);
char	*recup_nb1(char *, int, int);
char	*recup_nb2(char *, int);
int	count_int(int);
char	*chartointless(char *, int, int);
char	*chartoint(int);
int	count_first(char *, int);
int	count_last(char *, int);
char	*replace_str(char *, int, char *);
char	*factors(char *, int);
char	*sums(char *, int);
char	*calcul_exprless(char *);
char	*calcul_expr(char *);
char	*check_parless(char *, int, int, int);
int	check_par(char *, int);
char	*clean_parless(char *, int, int);
int	clean_par(char *, int);
int	sign_par(char *, int);
char	*sign_parless(char *, int, int);
char	*calcul_par(char *);
char	*clean_expr(char *);
char	*eval_expr(char *, char *, char *);
char	*my_mod(char *, char *, int, int);
char	*my_div(char *, char *, int, int);
char	*addinf(char *, char *);
char	*retzero(char *);
char	*my_putsigne(char *);
char	*my_nstrdup(char *);
int	check_bigger(char *, char *);
int	my_nstrcmp(char *, char *);
char	*find_first(char *, char *);
int	my_nstrlen(char *);
char	*calcul_less(char *, char *);
char	*create_my_malloc(char *);
char	*my_modless(char *, char *, int);
char	*trouvemoilebug(char *);
void	put_error(char *);
char	*todecimal(char *, char *, char *);
char	*tobase(char *, char *, char *, char *);
int	check_base_convert(char *, int, char *);
char	*calc_power(char *, int);
int	todecimalless(char *, char *, int, char *);
char	*my_lesssigne(char *);

#endif /* !MY_H_ */
