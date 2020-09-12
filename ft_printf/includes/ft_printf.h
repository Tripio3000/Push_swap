/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 21:08:20 by efleta            #+#    #+#             */
/*   Updated: 2020/08/01 21:08:26 by efleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define SIZE_E 16383
# define SIZE_M 64

# include <stdio.h>
# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <float.h>
# include <math.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct				s_struct{

	char					*s;
	long int				a;
	long long int			d;
	unsigned long long int	o;
	unsigned int			u;
	char					c;
	char					*q;
	int						i;
	char					*tmp;
	char					*str;
	char					*l;
	int						f;
	char					specif;
	int						f_plus;
	int						f_minus;
	int						f_space;
	int						f_resh;
	int						f_nul;
	int						f_pres;
	int						f_long;
	int						f_trig;
	int						f_scp;
	int						f_color;
	int						without_0x;
	int						wdht;
	int						schet;
	int						nul;
	char					*color;
	int						c_trig;
	int						num_flags;
	int						wdth_pres;
	int						zvezd;
	long double				fl;
	int						size;
	int						shift;
	char					*fp;
	char					*sp;
	char					*arr;
	int						round;
	int						f_zero;
	int						sign_bit;
	int						neg_round;
}							t_struct;

typedef struct				s_str
{
	unsigned long			mant : 64;
	unsigned int			exp : 15;
	unsigned int			sign : 1;
}							t_str;

typedef union				u_sun{
	long double				f;
	struct s_str			v;
}							t_sun;

int							ft_printf(char *format, ...);
void						octal(unsigned long long int a, t_struct *st);
void						new(t_struct *st);
char						*itoa(long long int a);
void						check_flags(char *format, t_struct *st, va_list ap);
void						chifr(char *format, t_struct *st, va_list ap);
void						hexadecimal(unsigned long long int a, int trig,
							t_struct *st);
void						specif_di(t_struct *st);
void						specif_uoxx(t_struct *st, char *format,
							unsigned long long int a);
int							length(char *format, t_struct *st, va_list ap);
void						flags(char *format, t_struct *st);
void						ft_print(t_struct *st);
void						width(char *format, t_struct *st, va_list ap);
void						null_print(t_struct *st);
int							ft_length(long long int n);
void						ft_printf_sec(char *format, t_struct *st,
							va_list ap);
void						ft_print_cs(int trig, t_struct *st, va_list ap);
void						ft_free(t_struct *st);
void						space_print(t_struct *st);
int							re_putstr(char const *s);
int							re_putchar(char c);
void						proverka(char *format, t_struct *st);
void						color_print(t_struct *st);
void						pres_check(char *format, t_struct *st, va_list ap);
void						pres_width(char *format, t_struct *st, va_list ap);
void						pres_print(t_struct *st);
void						minus_print(t_struct *st);
void						minus_print1(t_struct *st);
void						print_else(t_struct *st);
void						print_else1(t_struct *st);
int							short_length(char *format, t_struct *st,
							va_list ap);
int							long_length(char *format, t_struct *st, va_list ap);
void						long_length1(char *format, t_struct *st,
							va_list ap);
int							hexadecimal2(unsigned long long int a, int trig,
							t_struct *st);
void						detect_wdth(char *format, t_struct *st, va_list ap);
void						handle(char *format, va_list ap, t_struct *st);
void						init(t_struct *st);
void						pres_str(t_struct *st);
void						pres_num(t_struct *st);
void						bit_parcer(long double f, t_struct *st);
void						rounding(char *sp, t_struct *st);
void						ft_out(char *sp, t_struct *st);
void						sum_reverse(char *tmp, t_struct *st);
void						rounding_fp(t_struct *st);
char						*u_itoa(unsigned long long n);
int							u_ft_length(unsigned long long int n);
void						ft_printf_fl(char *format, t_struct *st,
							va_list ap);
void						*ft_realloc(void *ptr, size_t size);
void						*sum_char(char *ans, char *tmp);
void						*sum_char2(char *ans, int i, int j);
void						*get_char(char *arr);
void						*ft_cpy(char *newptr, char *ptr, int size);
void						init_array(t_struct *st);
void						init_chars(t_struct *st);
void						circle(t_struct *st, t_sun eeei);
void						two_degree2(t_struct *st);
void						two_degree(t_struct *st);
void						rounding_fp(t_struct *st);
int							sum_reverse2(const char *arr, t_struct *st);
void						sum_reverse(char *tmp, t_struct *st);
void						*get_zero(char *arr);
void						*multiplication2(const char *ar, char *newptr);
void						*multiplication(char *arr, int num, int deg);
int							exp_shift(t_sun eeei);
int							check_inf_nan(t_sun eeei, t_struct *st);
int							check_zero1(t_sun eeei, t_struct *st);
int							check_zero(t_sun eeei, t_struct *st);
int							bits(t_sun eeei, int c);
void						after_point(t_sun eeei, t_struct *st);
void						plus_print(t_struct *st);
void						memdel(t_struct *st);

#endif
