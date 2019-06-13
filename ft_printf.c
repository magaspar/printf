#include "ft_printf.h"

void	get_and_treat_arg(t_struct *Sprint)
{
	if (Sprint->type == 'c')
	{
		Sprint->arg = (unsigned char)va_arg(Sprint->ap, int);
		ft_treat_c(Sprint);
	}
	if (Sprint->type == 's')
	{
		Sprint->s_arg = (char *)va_arg(Sprint->ap, char *);
		ft_treat_s(Sprint);
	}
	if 	(Sprint->type == 'p')
		Sprint->arg = (unsigned long int)va_arg(Sprint->ap, void *);
	if (Sprint->type == 'd' || Sprint->type == 'i')
	{
		if (Sprint->size == 1)
			Sprint->arg = (short)va_arg(Sprint->ap,  long long int);
		else if (Sprint->size == 2)
			Sprint->arg = (char)va_arg(Sprint->ap, long long int);
		else if (Sprint->size == 3)
			Sprint->arg = (long int)va_arg(Sprint->ap, long long int);
		else if (Sprint->size == 4)
			Sprint->arg = (long long int)va_arg(Sprint->ap, long long int);
	}
	if (Sprint->type == 'o' || Sprint->type == 'u' ||
	Sprint->type == 'x' || Sprint->type == 'X')
	{
		if (Sprint->size == 1)
			Sprint->arg = (unsigned short)va_arg(Sprint->ap,  long long int);
		else if (Sprint->size == 2)
			Sprint->arg = (unsigned char)va_arg(Sprint->ap, long long int);
		else if (Sprint->size == 3)
			Sprint->arg = (unsigned long)va_arg(Sprint->ap, long long int);
		else if (Sprint->size == 4)
			Sprint->arg = (unsigned long long)va_arg(Sprint->ap, long long int);
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
		else if (ft_strchar("hlL", format[i]) == 1)
			i = wich_size(format, i, Sprint);
		else if (ft_strchar("diouxXcsfp%", format[i]) == 1 &&
		format[i + 1] != '\0')
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
	Sprint->sizeL = 0;
	Sprint->arg = 0;
	return (Sprint);
}

int		ft_printf(char *format, ...)
{
	t_struct *Sprint;
	Sprint = init(Sprint);
	int i;
	i = 0;
	char *formatt;
	formatt = ft_strdup(format);
	va_start(Sprint->ap, format);
	while(formatt[i])
	{
		if (formatt[i] == '%' && formatt[i + 1] != '\0')
		{
			i = parse(formatt, i, Sprint);
			get_and_treat_arg(Sprint);
		}
		else if (formatt[i] != '\0')
		{
			ft_putchar(formatt[i]);
			i++;
		}
		else
			i++;
	}
	//free ? pour l'instant tout les malloc sont free a la fin car util
	va_end(Sprint->ap);
}

int main()
{
	ft_printf("f:%s|\n", "coucou");
	printf("p:%4.7s|\n\n", "coucou");

	ft_printf("f:%-c|\n", 'b');
	printf("p:%-c|\n\n", 'b');

	ft_printf("f:%+10c|\n", 'b');
	printf("p:%+10c|\n\n", 'b');
	
	ft_printf("f:%#10c|\n", 'b');
	printf("p:%#10c|\n\n", 'b');
	
	ft_printf("-f:%00c|\n", 'b');
	printf("-p:%00c|\n\n", 'b');

	ft_printf("f:% c|\n", 'b');
	printf("p:% c|\n\n", 'b');

	ft_printf("f:%55.5c|\n", 'b');
	printf("f:%55.5c|\n\n", 'b');

	ft_printf("f:%0#+- 55.0c|\n", 'b');
	printf("f:%0#+- 55.0c|\n\n", 'b');

	ft_printf("f:%-010%|\n", 'b');
	printf("f:%010%|\n\n", 'b');

	printf("|%2.6d|\n", 12);
	return (0);
}
