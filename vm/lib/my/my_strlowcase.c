/*
** EPITECH PROJECT, 2017
** my_strlowcase
** File description:
** returns a lowcase string
*/

char    *my_strlowcase(char *str)
{
	int     i;

	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] = str[i] + 32;
		}
	}
	return (str);
}
