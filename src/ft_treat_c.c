#include "ft_printf.h"

void	ft_treat_c(t_struct *Sprint)
{
	int i;

	i = 0;
	Sprint->retSize++;
	if (Sprint->width == 0 || Sprint->width == 1)
	{
		ft_putchar((char)Sprint->arg);
	}
	else if (Sprint->width > 0 && Sprint->flagZer == 0 && Sprint->flagMin == 0)
	{
		while(i < Sprint->width - 1)
		{
			ft_putchar(' ');
			if (i == Sprint->width - 2)
				ft_putchar((char)Sprint->arg);
			Sprint->retSize++;
			i++;
		}
	}
	else if (Sprint->width > 0 && Sprint->flagMin == 1 && Sprint->flagZer == 0)
	{
		while(i < Sprint->width - 1)
		{
			if (i == 0)
				ft_putchar((char)Sprint->arg);
			ft_putchar(' ');
			Sprint->retSize++;
			i++;
		}
	}
	else if (Sprint->width > 0 && Sprint->flagMin == 1 && Sprint->flagZer == 1)
	{
		while(i < Sprint->width - 1)
		{
			if (i == 0)
				ft_putchar((char)Sprint->arg);
			ft_putchar(' ');
			Sprint->retSize++;
			i++;
		}
	}
	else if (Sprint->width > 0 && Sprint->flagMin == 0 && Sprint->flagZer == 1)
	{
		while(i < Sprint->width - 1)
		{
			ft_putchar('0');
			if (i == Sprint->width - 2)
				ft_putchar((char)Sprint->arg);
			Sprint->retSize++;
			i++;
		}
	}
}
