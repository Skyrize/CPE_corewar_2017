/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** compute_bytes.
*/

#include "vm.h"

int reverse_int(int nb)
{
	union number number;
	char tmp;

	number.nbr = nb;
	tmp = number.str[0];
	number.str[0] = number.str[3];
	number.str[3] = tmp;
	tmp = number.str[1];
	number.str[1] = number.str[2];
	number.str[2] = tmp;
	return (number.nbr);
}

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

int *assign_value_to_parameters(char *binary_number, int *parameters)
{
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

int *detect_parameters(int num);
{
	char *binary_number = int_to_bin(num);
	int *parameters = malloc(sizeof(int) * 3);

	assign_value_to_parameters(binary_number, parameters);
	return (parameters);
}