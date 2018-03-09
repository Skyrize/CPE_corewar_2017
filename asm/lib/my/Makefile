##
## EPITECH PROJECT, 2017
## libmy compilator
## File description:
## compiles a libmy.a
##

SRC	=	my_compute_power_rec.c\
		my_compute_square_root.c\
		my_find_prime_sup.c\
		my_getnbr.c\
		my_isneg.c\
		my_is_prime.c\
		my_putchar.c\
		my_put_nbr.c\
		my_putstr.c\
		my_revstr.c\
		my_showstr.c\
		my_show_word_array.c\
		my_sort_int_array.c\
		my_strcapitalize.c\
		my_strcat.c\
		my_strcmp.c\
		my_strcpy.c\
		my_strdup.c\
		my_str_isalpha.c\
		my_str_islower.c\
		my_str_isnum.c\
		my_str_isprintable.c\
		my_str_isupper.c\
		my_strlen.c\
		my_strlowcase.c\
		my_strncat.c\
		my_strncmp.c\
		my_strncpy.c\
		my_strstr.c\
		my_strupcase.c\
		my_swap.c\
		my_putnbr_base.c\
		my_is_digit.c\
		my_putlong_base.c\
		printf.c\
		flags_a.c\
		flags_b.c\
		flags_c.c\
		my_split.c\
		get_next_line.c

OBJ	=	$(SRC:%.c=%.o)

NAME	=	libmy.a

FINAL	=	$(NAME)

all:	$(NAME) cph

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o: %.c
	gcc -c $^ -o $@ -g -I ./

clean:
	rm -f *.o
	rm -rf ../../include/my.h

endclean:
	rm -f *.o

fclean:	clean
	rm -f $(FINAL)

rmh:
	rm -f ../../include/my.h

cph:	rmh
	cp my.h ../../include/my.h

re:	fclean all
