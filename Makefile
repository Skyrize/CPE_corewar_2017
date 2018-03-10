##
## EPITECH PROJECT, 2017
## CPE_corewar_2017
## File description:
## Makefile
##

SRCVM	=	$(wildcard vm/src/*.c) $(wildcard vm/src/instruction/*.c)

SRCASM	=	$(wildcard asm/src/*.c)

NAME	=	corewar

CFLAGS	=	-g -W -Wall -Wextra

OBJVM	=	$(SRCVM:%.c=%.o)
OBJASM	=	$(SRCASM:%.c=%.o)

RED	=	\033[31m
YELLOW	=	\033[93m
BLUE	=	\033[34m
GREEN	=	\033[32m
STDCLR	=	\033[0m

all:	$(NAME)

tests_run:
	make -C tests/
	tests/unit-tests


$(NAME):	$(OBJVM) $(OBJASM)
	@echo -e "\n\n  $(YELLOW)Building corewar executable$(STDCLR)\n\n"
	gcc -o vm/corewar $(OBJVM) $(CFLAGS) -I vm/include -L vm/lib/my -lmy
	@echo -e "\n\n  $(YELLOW)Building asm executable$(STDCLR)\n\n"
	gcc -o asm/asm $(OBJASM) $(CFLAGS) -I asm/include -L asm/lib/my -lmy
	@echo -e "\n\n  $(YELLOW)Build finished$(STDCLR)\n\n"

%.o: %.c
	cd vm/lib/my && $(MAKE)
	cd asm/lib/my && $(MAKE)
	gcc -c $^ -o $@ $(CFLAGS) -I vm/include -I asm/include

clean:
	@echo -e "\n\n  $(YELLOW)Cleaning directory$(STDCLR)\n\n"
	cd vm/lib/my && $(MAKE) clean
	cd asm/lib/my && $(MAKE) clean
	rm -rf $(OBJVM)
	rm -rf $(OBJASM)
	make clean -C tests/

fclean: clean
	@echo -e "\n\n  $(YELLOW)Fcleaning directory$(STDCLR)\n\n"
	cd vm/lib/my && $(MAKE) fclean
	cd asm/lib/my && $(MAKE) fclean
	rm -rf vm/corewar
	rm -rf asm/asm
	make fclean -C tests/

re: fclean all
