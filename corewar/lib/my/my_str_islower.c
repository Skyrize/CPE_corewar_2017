/*
** EPITECH PROJECT, 2017
** my_str_islower
** File description:
** return 1 if the str is lowercase
*/

int     my_str_islower(char const *str)
{
	int     i;
	int     is_lower = 1;

	if (str[0] == '\0') {
		return (1);
	}
	for (i = 0; str[i] != '\0'; i++) {
		if (!(str[i] >= 'a' && str[i] <= 'z')) {
			is_lower = 0;
		}
	}
	return (is_lower);
}
