/*
** EPITECH PROJECT, 2017
** my_isneg
** File description:
** P if positive or zero N if negative
*/

void	my_putchar(char c);

int	my_isneg(int n)
{
	if (n >= 0)
		my_putchar('P');
	else
		my_putchar('N');
	return (0);
}
