/*
** EPITECH PROJECT, 2017
** my_strcapitalize
** File description:
** capitalize the first letters of words
*/

int	is_letter_or_number(char c)
{
	if (c >= '0' && c <= '9') {
		return (1);
	}
	if (c >= 'A' && c <= 'Z') {
		return (1);
	}
	if (c >= 'a' && c <= 'z') {
		return (1);
	}
	return (0);
}

char	process_letter(char c, int first)
{
	if (c >= 'a' && c <= 'z') {
		if (first)
			c -= 32;
	} else if (c >= 'A' && c <= 'Z')
		if (!first)
			c += 32;
	return (c);
}

char	*my_strcapitalize(char *str)
{
	int	i;
	char	last_char = 0;

	for (i = 0; str[i] != '\0'; i++) {
		if (last_char == 0 || !is_letter_or_number(last_char)) {
			str[i] = process_letter(str[i], 1);
		} else {
			str[i] = process_letter(str[i], 0);
		}
		last_char = str[i];
	}
	return (str);
}
