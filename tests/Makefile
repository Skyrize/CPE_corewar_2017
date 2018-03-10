##
## EPITECH PROJECT, 2018
## minishell1
## File description
## Makefile
##

CC	=	gcc

WFLAGS		=	-Wextra -W -Wall -Wparentheses -Wsign-compare -Wpointer-sign -Wuninitialized -Wunused-but-set-variable

CFLAGS		=	-I../compiler/include -L../compiler/lib/my/ -lmy --coverage -lcriterion

RM	=	rm -rf

SRCTEST	=	../compiler/src/io.c	\
		../compiler/src/op.c	\
		../compiler/src/syntax.c	\
		../compiler/src/str.c	\
		../compiler/src/reader.c	\

OBJTEST	=	$(SRCTEST:.c=.o)

NAMETEST	=	unit-tests

all:	prepare_lib tests_run

prepare_lib:
	make -C ../compiler/lib/my

tests_run:	$(OBJTEST)
	$(CC) -o $(NAMETEST) $(OBJTEST) $(CFLAGS) $(WFLAGS)

clean:
	$(RM) $(OBJTEST)
	$(RM) ../compiler/src/*.gcda
	$(RM) ../compiler/src/*.gcno
	$(RM) ./*.gcda
	$(RM) ./*.gcno

fclean: clean
	$(RM) $(NAMETEST)

re:	fclean all
