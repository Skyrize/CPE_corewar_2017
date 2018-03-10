/*
** EPITECH PROJECT, 2017
** my_str_isnum
** File description:
** return 1 if str only contain digits, otherwise, 0
*/

int	my_str_isnum(char const *str)
{
	int	i;
	int	is_num = 1;

	if (str[0] == '\0') {
		return (1);
	}
	for (i = 0; str[i] != '\0'; i++) {
		if (!(str[i] >= '0' && str[i] <= '9')) {
			is_num = 0;
		}
	}
	return (is_num);
}
