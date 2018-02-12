/*
** EPITECH PROJECT, 2017
** asm
** File description:
** asm.h created: 12/02/18 18:44
*/

#ifndef ASM_H_
#define ASM_H_

typedef char byte;

/// get the file descriptor of the file
///
/// the first call must be with the filename, after that, just put NULL in arg
/// \param name filename
/// \return file descriptor of the file
int get_fd(char *name);

void check_syntax(void);

#endif /* !ASM_H_ */
