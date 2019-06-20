/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: magaspar <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/20 16:12:35 by magaspar     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/20 17:17:08 by magaspar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>

typedef struct			s_struct
{
	char				type;
	int					flagdiese;
	int					flagplus;
	int					flagmin;
	int					flagzer;
	int					flagspace;
	int					width;
	int					size;
	long long int		arg;
	unsigned long long	u_arg;
	char				c_arg;
	char				*s_arg;
	int					sizel;
	int					prec;
	int					preczer;
	va_list				ap;
	int					argsize;
	char				*formattmp;
	int					retsize;
	int					multiret;
}						t_struct;

void					ft_putchar(char c);
int						ft_strchar(char *str, char c);
int						ft_strlen(char *str);
char					*ft_strdup(char *str);
int						ft_atoi(char *str);
void					ft_putnstr(char *str, int n);
char					*ft_strncpy(char *tmps, char *src, size_t len);
char					*ft_strneww(size_t size);
char					*ft_strrev(char *str);
int						ft_countnb(uintmax_t nbr, int baselen);
char					*ft_itoabase(uintmax_t i, char *base, int baselen);
void					ft_putnbr(int n);
char					*ft_itoa(long long int n);
char					*ft_utoa(unsigned long long n);
int						ft_putst(char *str);

void					wich_flag(char c, t_struct *sprint);
int						wich_size(char *format, int i, t_struct *sprint);
int						wich_prec(char *format, t_struct *sprint, int i);
int						wich_width(char *format, t_struct *sprint, int i);

void					ft_treat_c(t_struct *sprint);

void					ft_treat_modulo(t_struct *sprint);

void					ft_treat_s(t_struct *sprint);
int						putblank(int i);

void					ft_treat_p(t_struct *sprint);

void					ft_treat_d(t_struct *sprint);
int						putzer(int i);

void					ft_treat_u(t_struct *sprint);

void					ft_treat_o(t_struct *sprint);

void					ft_treat_x(t_struct *sprint);

#endif
