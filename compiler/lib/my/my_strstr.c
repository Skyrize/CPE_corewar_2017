/*
** EPITECH PROJECT, 2017
** my_strstr
** File description:
** find a pattern
*/

char	*my_strstr(char const *str, char const *to_find)
{
	int	i;
	int	checked = 0;

	for (i = 0; str[i] && to_find[checked]; i += 1) {
		if (str[i] == to_find[checked]) {
			checked += 1;
		} else if (str[i] != to_find[checked - 1]) {
			checked = 0;
		}
	}
	if (to_find[checked] == '\0') {
		return ((char *) &str[i - checked]);
	} else {
		return (0);
	}
}
