/*
** EPITECH PROJECT, 2017
** my_swap
** File description:
** swap the content of 2 variables
*/

void	my_swap(int *a, int *b)
{
	int	c;

	c = *b;
	*b = *a;
	*a = c;
}
