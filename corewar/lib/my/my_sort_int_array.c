/*
** EPITECH PROJECT, 2017
** my_sort_int_array
** File description:
** sort an int array
*/

#include "my.h"

void	my_sort_int_array(int *array, int size)
{
	int i;
	int loop;

	while (1) {
		loop = 1;
		for (i = 0; array[i + 1]; i += 1) {
			if (array[i] > array[i + 1]) {
				my_swap(&array[i], &array[i + 1]);
				loop = 0;
			}
		}
		if (loop == 1)
			return;
	}
}
