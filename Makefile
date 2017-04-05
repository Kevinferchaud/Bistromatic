##
## Makefile for emacs in /home/kevin.ferchaud/CPool_bistro-matic
## 
## Made by ferchaud kevin
## Login   <kevin.ferchaud@epitech.net>
## 
## Started on  Sun Nov  6 23:17:25 2016 ferchaud kevin
## Last update Sun Nov  6 23:17:28 2016 ferchaud kevin
##

NAME	=	calc

SRC	=	main.c			\
		modifynbrbase.c		\
		eval_expr.c		\
		par.c			\
		par2.c			\
		tools.c			\
		expr.c			\
		calcul.c		\
		tools2.c		\
		tools3.c		\
		op/addinf.c		\
		op/lessinf.c		\
		op/divinf.c		\
		op/multinf.c		\
		op/modinf.c		\
		error/error.c		\
		error/error2.c		\
		error/error3.c		\
		error/signe.c		\
		error/check_error.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I include/

CC	=	gcc

RM	=	rm -f

LIB	=	-L lib/my -lmy

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LIB)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
