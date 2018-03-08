/*
** EPITECH PROJECT, 2017
** asm
** File description:
** counter.c created: 08/03/18 15:37
*/

int counter(int to_add)
{
	static int count = 0;

	count += to_add;
	return (count);
}