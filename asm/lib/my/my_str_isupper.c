/*
** EPITECH PROJECT, 2017
** my_str_isupper
** File description:
** return 1 if there is only uppercase in str, 0 otherwise
*/

int     my_str_isupper(char const *str)
{
	int     i;
	int     is_upper = 1;

	if (str[0] == '\0') {
		return (1);
	}
	for (i = 0; str[i] != '\0'; i += 1) {
		if (!(str[i] >= 'A' && str[i] <= 'Z')) {
			is_upper = 0;
		}
	}
	return (is_upper);
}
