/*
** EPITECH PROJECT, 2017
** my_revstr
** File description:
** reverse a string
*/

int     my_strlen_s(char *str)
{
	char    act_char;
	int     inc;

	inc = 0;
	act_char = *str;
	while (act_char != '\0') {
		inc++;
		act_char = str[inc];
	}
	return (inc);
}

void    my_swap_s(char *str, int i, int j)
{
	char    a;
	char    b;

	a = str[i];
	b = str[j];
	str[j] = a;
	str[i] = b;
}

char    *my_revstr(char *str)
{
	int     length = my_strlen_s(str);
	int     inc = 0;

	while (inc < length) {
		length--;
		my_swap_s(str, inc, length);
		inc++;
	}
	return (str);
}
