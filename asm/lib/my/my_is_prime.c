/*
** EPITECH PROJECT, 2017
** my_is_prime
** File description:
** check if nb is prime
*/

int	my_is_prime(int nb)
{
	int	i = nb - 1;

	if (nb == 2)
		return (1);
	if (nb <= 1)
		return (0);
	while (i > 1) {
		if (nb % i == 0) {
			return (0);
		}
		i--;
	}
	return (1);
}
