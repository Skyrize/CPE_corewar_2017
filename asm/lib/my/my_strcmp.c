/*
** EPITECH PROJECT, 2017
** my_strcmp
** File description:
** compare two strings
*/

int	my_strcmp(char const *s1, char const *s2)
{
	int i;

	for (i = 0; s1[i] || s2[i]; i += 1) {
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		if (s1[i] && !(s2[i]))
			return (s1[i]);
		else if (!(s1[i]) && s2[i])
			return (s2[i]);
	}
	return (0);
}
