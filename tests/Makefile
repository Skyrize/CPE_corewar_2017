##
## EPITECH PROJECT, 2018
## minishell1
## File description
## Makefile
##

CC	=	gcc

WFLAGS		=	-Wextra -W -Wall -Wparentheses -Wsign-compare -Wpointer-sign -Wuninitialized -Wunused-but-set-variable

CFLAGS		=	-I../asm/include -Iinclude -L../asm/lib/my/ -lmy --coverage -lcriterion

RM	=	rm -rf

SRCTEST	=	../asm/src/io.c	\
		../asm/src/op.c	\
		../asm/src/write_op.c	\
		../asm/src/witing.c	\
		../asm/src/args.c	\
		../asm/src/cmd.c	\
		../asm/src/byterevert.c	\
		../asm/src/operation.c	\
		../asm/src/counter.c	\
		../asm/src/op_args.c	\
		../asm/src/op_type.c	\
		../asm/src/label.c	\
		../asm/src/syntax.c	\
		../asm/src/reader.c	\
		../asm/src/str.c	\
		../asm/src/free.c	\
		./src/test_is_printing_coding_byte.c	\
		./src/test_clear_header.c	\
		./src/test_get_cmd_data.c	\
		./src/test_revert_int.c	\

OBJTEST	=	$(SRCTEST:.c=.o)

NAMETEST	=	unit-tests

all:	prepare_lib tests_run

prepare_lib:
	make -C ../asm/lib/my

tests_run:	$(OBJTEST)
	$(CC) -o $(NAMETEST) $(OBJTEST) $(CFLAGS) $(WFLAGS)

clean:
	$(RM) $(OBJTEST)
	$(RM) ../asm/src/*.gcda
	$(RM) ../asm/src/*.gcno
	$(RM) ./src/*.gcda
	$(RM) ./src/*.gcno

fclean: clean
	$(RM) $(NAMETEST)

re:	fclean all
