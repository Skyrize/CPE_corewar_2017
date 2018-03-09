/*
** EPITECH PROJECT, 2017
** my_putnbr_base
** File description:
** put a base number
*/

void	my_putchar(char c);

int	ft_strlen(char const *str)
{
	int i = 0;

	while (str[i] != '\0') {
		i += 1;
	}
	return (i);
}

void	calcul_put(int nbr, int length, char const *base)
{
	int i = nbr / length;
	int j = nbr % length;

	if (nbr < 0) {
		my_putchar('-');
		calcul_put(-nbr, length, base);
	} else if (i >= length)
		calcul_put(i, length, base);
	else {
		switch (i)
		{
		case 0:
			break;
		default :
			my_putchar(base[i]);
		}
	}
	my_putchar(base[j]);
}

int	my_putnbr_base(int nbr, char const *base)
{
	int lenght = ft_strlen(base);

	calcul_put(nbr, lenght, base);
	return (0);
}
