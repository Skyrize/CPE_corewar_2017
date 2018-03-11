/*
** EPITECH PROJECT, 2017
** CPE_corewar_2017
** File description:
** (enter)
*/

#ifndef TEST_H_
#define TEST_H_
#include <criterion/criterion.h>
#include <criterion/redirect.h>

bool is_printing_coding_byte(byte ins_tag);
void clear_header(header_t *var);
char *remove_start_line(char *line);
int is_label_present(char **words);

#endif /* TEST_H_ */
