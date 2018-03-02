/*
** EPITECH PROJECT, 2017
** my_exec_2017
** File description:
** my_split.c
*/

#include "my.h"

int count_words(char *str, char separator)
{
	int i = 0;
	int a = 0;
	int words = 0;

	while (str[i]) {
		if ((str[i] != separator && str[i] != '\t') && a == 0) {
			words += 1;
			a = 1;
		} else if (str[i] == separator || str[i] == '\t')
			a = 0;
		i++;
	}
	return (words);
}

char *count_letters(int *letters, char *str, char separator)
{
	int i = 0;
	int j = 0;
	char *word;

	*letters = 0;
	while (str[i] == separator || str[i] == '\t')
		i++;
	while ((str[i] != separator && str[i] != '\t') && str[i] != 0) {
		i += 1;
		*letters += 1;
	}
	*letters = i;
	word = malloc(sizeof(char) * (*letters + 1));
	if (word == NULL)
		return (NULL);
	for (j; str[j] == separator || str[j] == '\t'; j++);
	for (i = j; (str[i] != separator && str[i] != '\t') && str[i] != 0; i++)
		word[i - j] = str[i];
	word[i - j] = 0;
	return (word);
}

char **my_split(char *str, char separator)
{
	int words = 0;
	char *word = NULL;
	char **word_array = NULL;
	int letters = 0;
	int i = 0;

	if (str == NULL)
		return (NULL);
	words = count_words(str, separator);
	word_array = malloc(sizeof(char *) * (words + 1));
	for (i = 0; i < words; i++) {
		word = count_letters(&letters, str, separator);
		str += letters;
		word_array[i] = word;
	}
	word_array[i] = NULL;
	return (word_array);
}

int my_array_length(void **arr)
{
	int i = 0;

	for (; arr[i]; i += 1);
	return (i);
}

char *str_array_to_str(char **words)
{
	int len = my_array_length((void **) words);
	int total_len = 0;
	char *res;
	int pos = 0;

	for (int i = 0; words[i]; i++) {
		for (int j = 0; words[i][j]; j++)
			total_len++;
		total_len ++;
	}
	res = malloc(sizeof(char) * total_len);
	for (int i = 0; words[i]; i++) {
		for (int j = 0; words[i][j]; j++) {
			res[pos] = words[i][j];
			pos++;
		}
		res[pos] = ' ';
		pos++;
	}
	res[pos - 1] = '\0';
	return (res);
}