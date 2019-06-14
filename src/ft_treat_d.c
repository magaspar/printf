#include "ft_printf.h"


void	putZer(int i)
{
	int j;

	j = 0;
	while (j < i)
	{
		ft_putchar('0');
		j++;
	}
}

void	ft_treat_d(t_struct *Sprint)
{
	int fields;
	int min;
	int i;
	char *tmp;

	min = 0;
	i = 0;
	if (Sprint->arg < 0)
		tmp = ft_itoa(-Sprint->arg);
	else
		tmp = ft_itoa(Sprint->arg);
	if (Sprint->arg == 0 && Sprint->precZer == 1)
	{
		if (Sprint->flagSpace == 1)
		{
			Sprint->retSize++;
			ft_putchar(' ');
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
			if (Sprint->flagSpace == 1)
				ft_putchar(' ');
			if (Sprint->flagPlus == 1 && min == 0)
				ft_putchar('+');
			if (min == 1)
				ft_putchar('-');
			if (Sprint->prec > ft_countnb(Sprint->arg, 10))
			{
				while(i < Sprint->prec - ft_countnb(Sprint->arg, 10))
				{
					ft_putchar('0');
					i++;
				}
				Sprint->retSize += i;
			}
			ft_putst(tmp);
			Sprint->retSize += fields;
		}
		else if(fields < Sprint->width)
		{
			if (Sprint->flagMin == 1)
			{
				if (Sprint->flagSpace == 1)
					ft_putchar(' ');
				if (Sprint->flagPlus == 1 && min == 0)
				{
					ft_putchar('+');
					fields++;
				}
				if (min == 1)
					ft_putchar('-');
				ft_putst(tmp);
				putblank(Sprint->width - fields);
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
						putblank(Sprint->width - fields);
					ft_putchar('-');
				}
				if (Sprint->flagSpace == 1)
					ft_putchar(' ');
				if (Sprint->flagPlus == 1)
				{
					Sprint->retSize--;
					fields++;
				}
				if (Sprint->flagZer == 1 && Sprint->prec == 0 && Sprint->precZer == 0)
					putZer(Sprint->width - fields);
				else if (min != 1)
				{
					if (Sprint->prec > ft_countnb(Sprint->arg, 10))
					{
						fields = fields + (Sprint->prec - ft_countnb(Sprint->arg, 10));
					}
					putblank(Sprint->width - fields);
				}
				if (Sprint->flagPlus == 1 && min == 0)
					ft_putchar('+');
				if (Sprint->prec > ft_countnb(Sprint->arg, 10))
				{
					while(i < Sprint->prec - ft_countnb(Sprint->arg, 10))
					{
						ft_putchar('0');
						i++;
					}
				}
				ft_putst(tmp);
			}
			Sprint->retSize = Sprint->retSize + Sprint->width;
		}
		if (Sprint->flagSpace == 1)
		{
			Sprint->retSize = Sprint->retSize + 1;
		}
		if (Sprint->flagPlus == 1 && min == 0)
		{
			Sprint->retSize = Sprint->retSize + 1;
		}
	}
}
