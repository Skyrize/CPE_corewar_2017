/*
** EPITECH PROJECT, 2017
** CPE_corewar_2017
** File description:
** (enter)
*/

#include <asm.h>
#include <my.h>
#include "test.h"

Test(is_printing_coding_byte, test_0x01)
{
	byte test = 0x01;
	bool got = is_printing_coding_byte(test);

	cr_assert(got == false, "ERROR: send 0x01 but didn't got false\n");

}

Test(is_printing_coding_byte, test_0x09)
{
	byte test = 0x09;
	bool got = is_printing_coding_byte(test);

	cr_assert(got == false, "ERROR: send 0x09 but didn't got false\n");
}

Test(is_printing_coding_byte, test_0x0c)
{
	byte test = 0x0c;
	bool got = is_printing_coding_byte(test);

	cr_assert(got == false, "ERROR: send 0x0c but didn't got false\n");
}

Test(is_printing_coding_byte, test_0x0f)
{
	byte test = 0x0f;
	bool got = is_printing_coding_byte(test);

	cr_assert(got == false, "ERROR: send 0x0f but didn't got false\n");
}

Test(is_printing_coding_byte, test_true)
{
	byte test1 = 0x02;
	byte test2 = 0x03;
	byte test3 = 0x04;
	byte test4 = 0x05;
	byte test5 = 0x06;
	bool got = is_printing_coding_byte(test1);

	cr_assert(got == true, "ERROR: send 0x02 didn't got true\n");
	got = is_printing_coding_byte(test2);
	cr_assert(got == true, "ERROR: send 0x03 didn't got true\n");
	got = is_printing_coding_byte(test3);
	cr_assert(got == true, "ERROR: send 0x04 didn't got true\n");
	got = is_printing_coding_byte(test4);
	cr_assert(got == true, "ERROR: send 0x05 didn't got true\n");
	got = is_printing_coding_byte(test5);
	cr_assert(got == true, "ERROR: send 0x06 didn't got true\n");
}
