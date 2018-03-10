/*
** EPITECH PROJECT, 2017
** asm
** File description:
** counter.c created: 08/03/18 15:37
*/

#include <unistd.h>
#include <asm.h>
#include <my.h>

int counter(int to_add)
{
	static int count = 0;

	count += to_add;
	return (count);
}

int counter_b(int to_add)
{
	static int count = 0;

	count += to_add;
	return (count);
}

void write_size(int fd)
{
	int a = counter(0);

	a = revert_int(a);
	lseek(fd, 0x88, SEEK_SET);
	write(fd, &a, 4);
}