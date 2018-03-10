/*
** EPITECH PROJECT, 2017
** asm
** File description:
** op.c created: 12/02/18 17:16
*/

#include "vm.h"

op_t op_tab[] = {{"live", 1, {T_DIR}, 1, 10, &operate_live},
		{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, &operate_ld},
		{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, &operate_st},
		{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, &operate_add},
		{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, &operate_sub},
		{"and", 3, \
		{T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, \
		 6, 6, &operate_and},
		{"or", 3, \
		{T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, \
		7, 6, &operate_or},
		{"xor", 3, \
		{T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, \
		8, 6, &operate_xor},
		{"zjmp", 1, {T_DIR}, 9, 20, &operate_zjmp},
		{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, \
		10, 25, &operate_ldi},
		{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, \
		11, 25, &operate_tmp},
		{"fork", 1, {T_DIR}, 12, 800, &operate_fork},
		{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, &operate_lld},
		{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, \
		14, 50, &operate_tmp},
		{"lfork", 1, {T_DIR}, 15, 1000, &operate_lfork},
		{"aff", 1, {T_REG}, 16, 2, &operate_aff},
		{0, 0, {0}, 0, 0, 0}};
