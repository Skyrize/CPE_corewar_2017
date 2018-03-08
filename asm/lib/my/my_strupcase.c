/*
** EPITECH PROJECT, 2017
** my_strupcase
** File description:
** RETURNS A UPCASE STRING
*/

char	*my_strupcase(char *str)
{
	int	i;

	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] = str[i] - 32;
		}
	}
	return (str);
}
