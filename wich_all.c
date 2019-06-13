#include "ft_printf.h"

int		wich_prec(char *format, t_struct *Sprint, int i)
{
	int num;

	num = 0;
	if (ft_strchar("0123456789", format[i + 1]) == 0)
		return(i);
	else if (ft_strchar("0123456789", format[i + 1]))
	{
		i++;
		while(format[i] >= '0' && format[i] <= '9')
		{
			num = num + format[i] - '0';
			if (ft_strchar("01234567898", format[i + 1]))
				num = num * 10;
			i++;
		}
	}
	Sprint->prec = num;
	return (i - 1);
}

int		wich_size(char *format, int i, t_struct *Sprint)
{
	int tmp;

	tmp = Sprint->size;
	if (format[i] == 'h' && format[i + 1] == 'h')
	{
		tmp = 2;
		i++;
	}
	else if (format[i] == 'h')
		tmp = 1;
	else if (format[i] == 'l' && format[i + 1] == 'l')
	{
		tmp = 4;
		i++;
	}
	else if (format[i] == 'l')
		tmp = 3;
	else if (format[i] == 'L')
		Sprint->sizeL = 1;
	if (tmp > Sprint->size)
		Sprint->size = tmp;
	return (i);
}

int		wich_width(char *format, t_struct *Sprint, int i)
{
	int num;

	num = 0;
	while(format[i] >= '0' && format[i] <= '9')
	{
		num = num + format[i] - '0';
		if (ft_strchar("01234567898", format[i + 1]))
			num = num * 10;
		i++;
	}
	Sprint->width = num;
	return (i - 1);
}

void	wich_flag(char c, t_struct *Sprint)
{
	if (c == '#')
		Sprint->flagDiese = 1;
	else if (c == '+')
		Sprint->flagPlus = 1;
	else if (c == '-')
		Sprint->flagMin = 1;
	else if (c == '0')
		Sprint->flagZer = 1;
	else if (c == ' ')
		Sprint->flagSpace = 1;
}
