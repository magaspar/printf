#ifndef FT_PRINTF
#define FT_PRINTF

#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_struct
{
	char		type;
	int			flagDiese;
	int			flagPlus;
	int			flagMin;
	int			flagZer;
	int			flagSpace;
	int			width;
	int			size;
	long long int	arg;
	char			c_arg;
	char			*s_arg;
	int			sizeL;
	int			prec;
	va_list		ap;
	int			argsize;
	char		*formatTmp;
}			   t_struct;

void	ft_putchar(char c);
int		ft_strchar(char *str, char c);
int		ft_strlen(char *str);
char	*ft_strdup(char *str);
int		ft_atoi(char *str);

void	wich_flag(char c, t_struct *Sprint);
int		wich_size(char *format, int i, t_struct *Sprint);
int		wich_prec(char *format, t_struct *Sprint, int i);
int		wich_width(char *format, t_struct *Sprint, int i);

void	ft_treat_c(t_struct *Sprint);

void	ft_treat_modulo(t_struct *Sprint);

void	ft_treat_s(t_struct *Sprint);
#endif
