/*
** bistro-matic.h for emacs in /home/kevin.ferchaud/CPool_bistro-matic/include
** 
** Made by ferchaud kevin
** Login   <kevin.ferchaud@epitech.net>
** 
** Started on  Sun Nov  6 23:16:18 2016 ferchaud kevin
** Last update Sun Nov  6 23:16:19 2016 ferchaud kevin
*/

#ifndef BISTRO_MATIC_H
# define BISTRO_MATIC_H

#define OP_OPEN_PARENT_IDX  0
#define OP_CLOSE_PARENT_IDX 1
#define OP_PLUS_IDX	    2
#define OP_SUB_IDX	    3
#define OP_NEG_IDX	    3
#define OP_MULTI_IDX	    4
#define OP_DIV_PARENT_IDX   5
#define OP_MOD_IDX	    6

#define	EXIT_USAGE	84
#define	EXIT_BASE	84
#define EXIT_SIZE_NEG	84
#define EXIT_MALLOC	84
#define EXIT_READ	84
#define EXIT_OPS	84

#define SYNTAX_ERROR_MSG "syntax error"
#define ERROR_MSG	 "error"

char	*get_expr(unsigned int);
char	*check_error(int, char **);
int	check_same(char *);
int	check_same2(char *, char *);
int	check_same3(char *, char *, char *, int);
int	check_base(char *);
int	check_ops(char *);
int	check_parenthese(char *, char *, char *);
int	check_expr(char *, char *, char *);
int	check_expr2(char *, char *, char *);
int	check_expr3(char *, char *);
int	check_moins(char *, char *, int);
int	avancement(char *, char *, int);
int	check_beginend(char *, char *, int);
int	check_doublops(char *, char *, int);
int	check_empty(char *, char *, char *, int);
int	check_parenth(char *, char *, int);
char	*change_str(char *, char *);
char	*change_str2(char *, char *, int, int);

#endif /* !BISTRO_MATIC_H */
