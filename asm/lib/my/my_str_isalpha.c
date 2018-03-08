/*
** EPITECH PROJECT, 2017
** my_str_isalpha
** File description:
** return 1 if alphabetical 0 if not
*/

void	is_alpha_v(int *is_alpha, char c)
{
	if (!(c >= 'a' && c <= 'z')) {
		if (!(c >= 'A' && c <= 'Z')) {
			*is_alpha = 0;
		}
	}
}

int	my_str_isalpha(char const *str)
{
	int	i;
	int	is_alpha = 1;

	if (str[0] == '\0')
		return (1);
	for (i = 0; str[i] != '\0'; i++) {
		is_alpha_v(&is_alpha, str[i]);
	}
	return (is_alpha);
}
