/*
** EPITECH PROJECT, 2017
** asm
** File description:
** var_types.c created: 28/02/18 11:05
*/

#include <my.h>
#include <asm.h>
#include <op.h>

bool is_cmd_valid(char **words)
{
	int len = my_array_length((void **) words);

	if (len < 2)
		return (false);
	if (words[1][0] == '"' &&
		words[len - 1][my_strlen(words[len - 1]) - 1] == '"') {

		return (true);
	}
	return (false);
}

char *get_cmd_str(char *line)
{
	int i;
	int j;
	char *res;

	for (i = 0; line[i] && line[i] != '"'; i++);
	i++;
	for (j = 0; line[i + j] && line[i + j] != '"'; j++);
	res = malloc(sizeof(char) * j + 1);
	for (j = 0; line[i + j] && line[i + j] != '"'; j++)
		res[j] = line[i + j];
	res[j] = '\0';
	return (res);
}

cmd_data *get_cmd_data(void)
{
	static cmd_data *data = NULL;

	if (data == NULL) {
		data = malloc(sizeof(*data));
		data->name = my_strdup("");
		data->description = my_strdup("");
	}
	return (data);
}

bool is_valid_cmd(char **words)
{
	cmd_data *data = NULL;

	if (check_unknown_line(words) && is_cmd_valid(words)) {
		data = get_cmd_data();
		if (my_strcmp(words[0], NAME_CMD_STRING) == 0) {
			char *r = str_array_to_str(words);
			free(data->name);
			data->name = get_cmd_str(r);
		} else {
			free(data->description);
			data->description = get_cmd_str(\
			str_array_to_str(words));
		}
		return (true);
	}
	return (false);
}