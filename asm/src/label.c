/*
** EPITECH PROJECT, 2017
** asm
** File description:
** label.c created: 08/03/18 14:17
*/

#include <my.h>
#include <asm.h>

label_t **get_label_list(void)
{
	static label_t **ret = NULL;

	if (ret == NULL) {
		ret = malloc(sizeof(*ret));
		*ret = NULL;
	}
	return (ret);
}

bool is_label_chars(char *word)
{
	char *b = my_strdup(word);
	char *a = my_strdup(" ");

	b[my_strlen(word) - 1] = '\0';
	for (int i = 0; i < my_strlen(word); i++) {
		a[0] = word[i];
		if (!my_contains(a, LABEL_CHARS))
			return (false);
	}
	return (true);
}

int is_label_present(char **words)
{
	int i;
	int len = my_array_length((void **)words);

	for (i = 0; i < len; i++) {
		if (words[i][my_strlen(words[i]) - 1] == LABEL_CHAR) {
			return (i);
		}
	}
	return (-1);
}

void add_label(label_t *label)
{
	label_t **act_label = get_label_list();
	label_t *tmp = *act_label;

	if (!tmp) {
		*act_label = label;
		return;
	}
	for (; tmp->next; tmp = tmp->next);
	tmp->next = label;
}

void scan_line_for_labels(char **words)
{
	int pos = is_label_present(words);

	if (pos == -1)
		return;
	label_t *label = malloc(sizeof(*label));
	label->name = my_strdup(words[pos]);
	label->name[my_strlen(label->name) - 1] = '\0';
	label->bytes_pos = counter_b(0);
	label->next = NULL;
	add_label(label);
}