/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** header of my library
*/

#ifndef MY_H_
#define MY_H_

#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>

void	my_putchar(char c);

int	my_isneg(int nb);

int	my_put_nbr(int nb);

void	my_swap(int *a, int *b);

int	my_putstr(char const *str);

int	my_strlen(char const *str);

int	my_getnbr(char const *nbr);

void	my_sort_int_array(int *tab, int size);

int	my_compute_power_rec(int nb, int power);

int	my_compute_square_root(int nb);

int	my_is_prime(int nb);

int	my_find_prime_sup(int nb);

char	*my_strcpy(char *dest, char const *src);

char	*my_strncpy(char *dest, char const *src, int n);

char	*my_revstr(char *str);

char	*my_strstr(char *str, char const *to_find);

int	my_strcmp(char const *s1, char const *s2);

int	my_strncmp(char const *s1, char const *s2, int n);

char	*my_strupcase(char *str);

char	*my_strlowcase(char *str);

char	*my_strcapitalize(char *str);

int	my_str_isalpha(char const *str);

int	my_str_isnum(char const *str);

int	my_str_islower(char const *str);

int	my_str_isupper(char const *str);

int	my_str_isprintable(char const *str);

int	my_showstr(char const *str);

int	my_showmem(char const *str, int size);

char	*my_strcat(char *dest, char const *src);

char	*my_strncat(char *dest, char const *src, int nb);

char	**my_str_to_word_array(char const *str);

char	*my_strdup(char const *src);

int	my_putnbr_base(int nbr, char const *base);

int	my_getnbr_base(char const *str, char const *base);

int	my_isprintable(char const c);

int	my_printf(char const *format, ...);

int	my_is_digit(char c);

int	my_contains(char *s, char *cont);

int	my_put_long(long nb);

int	my_putlong_base(long nbr, char const *base);

char	*my_str_append(char *stra, char *strb);

char	**my_split(char *str, char sp);

int	my_array_length(void **arr);

char	*get_next_line(int fd);

bool	is_number(char *str);

void my_putnbr_base_lowcase(long long nbr, int base);

void	flag_c(va_list list, char *a);
void	flag_s(va_list list, char *a);
void	flag_d(va_list list, char *a);
void	flag_pc(va_list list, char *a);
void	flag_ld(va_list list, char *a);
void	flag_hd(va_list list, char *a);
void	flag_p(va_list list, char *a);
void	flag_x(va_list list, char *a);
void	flag_o(va_list list, char *a);
void	flag_u(va_list list, char *a);
void	flag_xx(va_list list, char *a);
void 	flag_b(va_list list, char *a);
void	flag_ss(va_list list, char *a);

int	my_printf(char const *format, ...);

typedef void (*oper_func)(va_list, char *);

typedef struct operation {
	char c;
	oper_func operation;
} operation_t;

extern const operation_t oper_array[];

#endif /* MY_H_ */
