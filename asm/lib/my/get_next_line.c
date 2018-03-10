/*
** EPITECH PROJECT, 2018
** GetNextLine
** File description:
** main file
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

char *my_strcat_gnl(char *a, char *b)
{
	int len_a;
	int len_b;
	int i;
	int j;
	char * ret;

	for (len_a = 0; a[len_a] != 0 && a[len_a] != '\n'; len_a += 1);
	for (len_b = 0; b[len_b] != 0 && b[len_b] != '\n'; len_b += 1);
	ret = malloc(sizeof(char *) * (len_a + len_b) + 1);
	for (i = 0; a[i] != 0 && a[i] != '\n'; i += 1)
		ret[i] = a[i];
	for (j = 0; b[j] != 0 && b[j] != '\n'; j += 1)
		ret[i + j] = b[j];
	ret[i + j] = 0;
	return (ret);
}

int is_lr(char *str)
{
	int i = 0;

	for (; str[i] != '\0' && str[i] != '\n'; i += 1);
	if (str[i] == '\0')
		return (-1);
	if (str[i] == '\n')
		return (i);
	return (-1);
}

char *gnl(int fd, char **saver, int *lr, char *tmp)
{
	char *buffer = malloc(sizeof(char) * 5 + 1);
	ssize_t read_ret = read(fd, buffer, 5);

	if (read_ret == 0) {
		if (my_strlen(*saver) != 0) {
			tmp = *saver;
			*saver = "";
			return (tmp);
		}
		return (NULL);
	}
	buffer[read_ret] = 0;
	*lr = is_lr(buffer);
	if (*lr > -1) {
		tmp = &buffer[*lr + 1];
		buffer = my_strcat_gnl(*saver, buffer);
		*saver = tmp;
		return (buffer);
	}
	*saver = my_strcat_gnl(*saver, buffer);
	return (1);
}

char *get_next_line(int fd)
{
	static char *saver = NULL;
	char *tmp = "";
	int lr;

	if (!saver) {
		saver = malloc(1);
		saver[0] = '\0';
	}
	lr = is_lr(saver);
	while (lr == -1) {
		tmp = gnl(fd, &saver, &lr, tmp);
		if (tmp != (char *) 0x1)
			return (tmp);
	}
	tmp = saver;
	saver = &saver[lr + 1];
	return (my_strcat_gnl(tmp, ""));
}
