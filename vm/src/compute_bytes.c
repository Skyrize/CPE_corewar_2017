/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** compute_bytes.
*/

#include "vm.h"
#include <stdio.h>

char *int_to_bin(unsigned int num)
{
	unsigned int mask = 128;
	char *result = malloc(12);
	int i = 0;

	while (mask > 0) {
		if ((num & mask) == 0 )
			result[i] = '0';
		else
			result[i] = '1';
		mask = mask >> 1 ;
		if (i == 1 || i == 4 || i == 7)
			result[++i] = 32;
		i++;
	}
	result[i] = 0;
	return (result);
}

int *detect_parameters(int num)
{
	char *binary_number = int_to_bin(num);
	int *parameters = malloc(sizeof(int) * 3);
	int param_1 = my_getnbr(binary_number);
	int param_2 = my_getnbr(binary_number + 3);
	int param_3 = my_getnbr(binary_number + 6);

	param_1 == 1 ? parameters[0] = 1 : 0;
	param_1 == 10 ? parameters[0] = 2 : 0;
	param_1 == 11 ? parameters[0] = 4 : 0;
	param_2 == 1 ? parameters[1] = 1 : 0;
	param_2 == 10 ? parameters[1] = 2 : 0;
	param_2 == 11 ? parameters[1] = 4 : 0;
	param_3 == 1 ? parameters[2] = 1 : 0;
	param_3 == 10 ? parameters[2] = 2 : 0;
	param_3 == 11 ? parameters[2] = 4 : 0;
	return (parameters);
}

int get_int(byte *bytes)
{
	char str[4];
	int nb = 0;

	str[0] = bytes[0];
	str[1] = bytes[1];
	str[2] = bytes[2];
	str[3] = bytes[3];
	nb = reverse_int(*(int *)str);
	return (nb);
}

int get_short_int(byte *bytes)
{
	char str[2];
	int nb = 0;

	str[0] = bytes[0];
	str[1] = bytes[1];
	nb = reverse_short_int(*(short int *)str);
	return (nb);
}

int compute_bytes_read(int *parameters, champ_t *champ, pc_t *pc)
{
	int param_0 = 0;
	int param_1 = 0;
	int param_2 = 0;

	parameters[0] == 1 ? param_0 += 1 : 0;
	parameters[0] == 2 ? param_0 += 4 : 0;
	parameters[0] == 4 ? param_0 += 2 : 0;
	parameters[1] == 1 ? param_1 += 1 : 0;
	parameters[1] == 2 ? param_1 += 4 : 0;
	parameters[1] == 4 ? param_1 += 2 : 0;
	parameters[2] == 1 ? param_2 += 1 : 0;
	parameters[2] == 2 ? param_2 += 4 : 0;
	parameters[2] == 4 ? param_2 += 2 : 0;
	return (param_0 + param_1 + param_2);
}