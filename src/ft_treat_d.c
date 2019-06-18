#include "ft_printf.h"


int		putZer(int i)
{
	int j;

	j = 0;
	while (j < i)
	{
		ft_putchar('0');
		j++;
	}
	return(j);
}

void	ft_treat_d(t_struct *Sprint)
{
	int fields;
	int min;
	int i;
	char *tmp;
	int ut;

	min = 0;
	i = 0;
	ut = 0;
	fields = 0;
	if (Sprint->arg < 0)
		tmp = ft_itoa(-Sprint->arg);
	else
		tmp = ft_itoa(Sprint->arg);
	if (Sprint->arg == 0 && Sprint->precZer == 1)
	{
		if (Sprint->flagPlus)
		{
			Sprint->retSize++;
			ft_putchar('+');
		}
		if (Sprint->flagSpace == 1)
		{
			Sprint->retSize++;
			ft_putchar(' ');
			fields++;
		}
	}
	else
	{
		if (Sprint->arg < 0)
		{
			Sprint->arg = -Sprint->arg;
			min = 1;
			fields = ft_countnb(Sprint->arg, 10) + 1;
		}
		else
		{
			fields = ft_countnb(Sprint->arg, 10);
		}
		if (fields >= Sprint->width)
		{
			if (Sprint->flagSpace == 1 && Sprint->prec == 0)
			{
				fields++;
				ft_putchar(' ');
				Sprint->retSize++;
			}
			if (Sprint->flagPlus == 1 && min == 0)
			{
				Sprint->retSize++;
				ft_putchar('+');
			}
			if (min == 1)
			{
				ft_putchar('-');
				Sprint->retSize++;
			}
			if (Sprint->prec > ft_countnb(Sprint->arg, 10))
			{
				while(i < Sprint->prec - ft_countnb(Sprint->arg, 10))
				{
					ft_putchar('0');
					i++;
				}
				Sprint->retSize += i;
			}
			Sprint->retSize += ft_putst(tmp);
		}
		else if(fields < Sprint->width)
		{
			if (Sprint->flagMin == 1)
			{
				if (Sprint->flagSpace == 1 && Sprint->prec == 0)
				{
					fields++;
					ft_putchar(' ');
					Sprint->retSize++;
				}
				if (Sprint->flagPlus == 1 && min == 0)
				{
					Sprint->retSize++;
					ft_putchar('+');
					fields++;
				}
				if (min == 1)
				{
					ft_putchar('-');
					Sprint->retSize++;
				}
				if (Sprint->prec > ft_countnb(Sprint->arg, 10))
				{
					Sprint->retSize += putZer(Sprint->prec - ft_countnb(Sprint->arg, 10));
					ut = Sprint->prec - ft_countnb(Sprint->arg, 10);
					Sprint->retSize += ft_putst(tmp);
					Sprint->retSize += putblank(Sprint->width - fields - ut);
				}
				else
				{
					Sprint->retSize += ft_putst(tmp);
					Sprint->retSize += putblank(Sprint->width - fields);
				}
			}
			else
			{
				if (min == 1)
				{
					if (Sprint->prec > ft_countnb(Sprint->arg, 10))
					{
						fields = fields + (Sprint->prec - ft_countnb(Sprint->arg, 10));
					}
					if (Sprint->flagZer != 1)
						Sprint->retSize += putblank(Sprint->width - fields);
					ft_putchar('-');
					Sprint->retSize++;
				}
				if (Sprint->flagSpace == 1 && Sprint->prec == 0)
				{
					fields++;
					ft_putchar(' ');
					Sprint->retSize++;
				}
				if (Sprint->flagPlus == 1)
				{
					fields++;
				}
				if (Sprint->flagZer == 1 && Sprint->prec == 0 && Sprint->precZer == 0)
					Sprint->retSize += putZer(Sprint->width - fields);
				else if (min != 1)
				{
					if (Sprint->prec > ft_countnb(Sprint->arg, 10))
					{
						fields = fields + (Sprint->prec - ft_countnb(Sprint->arg, 10));
					}
					Sprint->retSize += putblank(Sprint->width - fields);
				}
				if (Sprint->flagPlus == 1 && min == 0)
				{
					ft_putchar('+');
					Sprint->retSize++;
				}
				if (Sprint->prec > ft_countnb(Sprint->arg, 10))
				{
					while(i < Sprint->prec - ft_countnb(Sprint->arg, 10))
					{
						ft_putchar('0');
						i++;
					}
					Sprint->retSize += i;
				}
				Sprint->retSize += ft_putst(tmp);
			}
		}
	}
	free(tmp);
}
