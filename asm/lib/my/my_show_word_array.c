/*
** EPITECH PROJECT, 2017
** my_show_word_array
** File description:
** print an array
*/

#include <my.h>

int	my_show_word_array(char * const *tab)
{
	int	i;

	for (i = 0; tab[i]; i += 1) {
		my_putstr(tab[i]);
		my_putchar('\n');
	}
}
