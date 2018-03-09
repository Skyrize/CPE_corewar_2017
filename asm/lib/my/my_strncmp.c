/*
** EPITECH PROJECT, 2017
** my_strncmp
** File description:
** compare two strings on n character
*/

int     my_strncmp(char const *s1, char const *s2, int n)
{
	int i;

	for (i = 0; (s1[i] || s2[i]) && i < n; i += 1) {
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		if (s1[i] && !(s2[i]))
			return (s1[i]);
		else if (!(s1[i]) && s2[i])
			return (s2[i]);
	}
	return (0);
}
