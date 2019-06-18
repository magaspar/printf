#include "ft_printf.h"

void	dispatch(t_struct *Sprint)
{
	if (Sprint->type == 'u' || Sprint->type == 'U')
	{
		ft_treat_u(Sprint);
	}
	else if (Sprint->type == 'o' || Sprint->type == 'O')
		ft_treat_o(Sprint);
	else if (Sprint->type == 'x' || Sprint->type == 'X')
		ft_treat_x(Sprint);
}

void	get_and_treat_arg(t_struct *Sprint)
{
	if (Sprint->type == 'c' || Sprint->type == 'C')
	{
		if (Sprint->type == 'c')
			Sprint->arg = (unsigned char)va_arg(Sprint->ap, int);
		else
			Sprint->arg = (wint_t)va_arg(Sprint->ap, int);
		ft_treat_c(Sprint);
	}
	if (Sprint->type == 's')
	{
		Sprint->s_arg = (char *)va_arg(Sprint->ap, char *);
		ft_treat_s(Sprint);
	}
	if 	(Sprint->type == 'p')
	{
		Sprint->arg = (long long int)va_arg(Sprint->ap, void *);
		ft_treat_p(Sprint);
	}
	if (Sprint->type == 'd' || Sprint->type == 'i' || Sprint->type == 'D')
	{
		if (Sprint->size == 1)
			Sprint->arg = (short)va_arg(Sprint->ap,  long long int);
		else if (Sprint->size == 2)
			Sprint->arg = (char)va_arg(Sprint->ap, long long int);
		else if (Sprint->size == 3 || Sprint->type == 'D')
			Sprint->arg = (long int)va_arg(Sprint->ap, long long int);
		else if (Sprint->size == 4)
			Sprint->arg = (long long int)va_arg(Sprint->ap, long long int);
		else
			Sprint->arg = (int)va_arg(Sprint->ap, long long int);
		ft_treat_d(Sprint);
	}
	if (Sprint->type == 'o' || Sprint->type == 'u' ||
	Sprint->type == 'x' || Sprint->type == 'X' || Sprint->type == 'U' || Sprint->type == 'O')
	{
		if (Sprint->size == 1)
			Sprint->u_arg = (unsigned short)va_arg(Sprint->ap, unsigned int);
		else if (Sprint->size == 2)
			Sprint->u_arg = (unsigned char)va_arg(Sprint->ap, unsigned int);
		else if (Sprint->size == 3 || Sprint->type == 'U')
			Sprint->u_arg = (unsigned long)va_arg(Sprint->ap, unsigned long int);
		else if (Sprint->size == 4 || Sprint->size == 5 || Sprint->size == 6 || Sprint->type == 'O')
			Sprint->u_arg = (unsigned long long int)va_arg(Sprint->ap, unsigned long long int);
		else
			Sprint->u_arg = (unsigned int)va_arg(Sprint->ap, unsigned int);
		dispatch(Sprint);
	}
	if (Sprint->type == '%')
		ft_treat_modulo(Sprint);
}

//trouver une alternative pour pas cut avec j sinon prob
int		parse(char *format, int i, t_struct *Sprint)
{
	int j;
	int n;
	j = 3;
	n = 0;
	i++;
	while(j != 1 && format[i] != '\0')
	{
		if (ft_strchar("#-+0 ", format[i]) == 1)
			wich_flag(format[i], Sprint);
		else if (ft_strchar("123456789", format[i]))
			i = wich_width(format, Sprint, i);
		else if (ft_strchar(".", format[i]))
			i = wich_prec(format, Sprint, i);
		else if (ft_strchar("hlLzj", format[i]) == 1)
			i = wich_size(format, i, Sprint);
		else if (ft_strchar("dDioOuUxXcCsfp%", format[i]) == 1)
		{
			Sprint->argsize = j;
			Sprint->type = format[i];
			j = 0;
		}
		i++;
		j++;
	}
		return (i);
}

void		reinit(t_struct *Sprint)
{
	Sprint->type = 0;
	Sprint->flagDiese = 0;
	Sprint->flagPlus = 0;
	Sprint->flagMin = 0;
	Sprint->flagZer = 0;
	Sprint->flagSpace = 0;
	Sprint->size = 0;
	Sprint->width = 0;
	Sprint->prec = 0;
	Sprint->precZer = 0;
	Sprint->sizeL = 0;
	Sprint->arg = 0;
	Sprint->u_arg = 0;
}

t_struct	*init(t_struct *Sprint)
{
	if (!(Sprint = (t_struct*)malloc(sizeof(t_struct))))
		return (NULL);
	Sprint->type = 0;
	Sprint->flagDiese = 0;
	Sprint->flagPlus = 0;
	Sprint->flagMin = 0;
	Sprint->flagZer = 0;
	Sprint->flagSpace = 0;
	Sprint->size = 0;
	Sprint->width = 0;
	Sprint->prec = 0;
	Sprint->precZer = 0;
	Sprint->sizeL = 0;
	Sprint->arg = 0;
	Sprint->retSize = 0;
	Sprint->u_arg = 0;
		return (Sprint);
}

int		ft_printf(char *format, ...)
{
	t_struct *Sprint;
	Sprint = init(Sprint);
	int i;
	int ret;
	i = 0;
	ret = 0;
	char *formatt;
	formatt = ft_strdup(format);
	va_start(Sprint->ap, format);
	while(formatt[i])
	{
		if (formatt[i] == '%' && formatt[i + 1] != '\0')
		{
			i = parse(formatt, i, Sprint);
			get_and_treat_arg(Sprint);
			reinit(Sprint);
		}
		else if (formatt[i] != '\0')
		{
			ft_putchar(formatt[i]);
			Sprint->retSize++;
			i++;
		}
	}
	ret = Sprint->retSize;
	va_end(Sprint->ap);
	free(Sprint);
	free(formatt);
	return (ret);
}
