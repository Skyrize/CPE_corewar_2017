/*
** EPITECH PROJECT, 2017
** my_compute_square_root
** File description:
** square root of nb
*/

int	my_compute_square_root(int nb)
{
	int	i;
	int	res = 0;

	if (nb <= 0)
		return (0);
	for (i = 0; res < nb; i += 1) {
		res = i * i;
		if (res == nb)
			return (i);
	}
	return (0);
}
