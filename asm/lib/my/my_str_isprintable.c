/*
** EPITECH PROJECT, 2017
** my_str_isprintable
** File description:
** return 1 if a string is printable
*/

int	my_isprintable(char const c)
{
	if (c < 32 || c == 127)
			return (0);
	return (1);
}

int	my_str_isprintable(char const *str)
{
	int i;

	for (i = 0; str[i]; i += 1) {
		if (my_isprintable(str[i]))
			return (0);
	}
	return (1);
}
