/*
** EPITECH PROJECT, 2017
** my_compute_power_rec
** File description:
** compute nb^p in recursive
*/

int	my_compute_power_rec(int nb, int p)
{
	int	act = 0;

	if (p == 0)
		return (1);
	if (p < 0)
		return (0);
	p--;
	act = nb * my_compute_power_rec(nb, p);
	return (act);
}
