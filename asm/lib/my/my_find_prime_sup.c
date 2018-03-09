/*
** EPITECH PROJECT, 2017
** my_find_prim_sup
** File description:
** find the smallest prime number that is greater than or equal to nb
*/

#include <my.h>

int	my_find_prime_sup(int nb)
{
	int	is_prime = 0;

	nb--;
	while (is_prime == 0) {
		nb++;
		is_prime = my_is_prime(nb);
	}
	return (nb);
}
