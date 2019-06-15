#include "ft_printf.h"


void	ft_treat_u(t_struct *Sprint)
{
	int fields;
	int min;
	int i;
	char *tmp;

	min = 0;
	i = 0;
	tmp = ft_utoa(Sprint->u_arg);
	if (Sprint->u_arg == 0 && Sprint->precZer == 1)
	{
		if (Sprint->flagSpace == 1)
		{
			Sprint->retSize++;
			ft_putchar(' ');
		}
	}
	else
	{
		fields = ft_countnb(Sprint->u_arg, 10);
		if (fields >= Sprint->width)
		{
			if (Sprint->flagSpace == 1)
				ft_putchar(' ');
			if (Sprint->flagPlus == 1 && min == 0)
				ft_putchar('+');
			if (min == 1)
				ft_putchar('-');
			if (Sprint->prec > ft_countnb(Sprint->u_arg, 10))
			{
				while(i < Sprint->prec - ft_countnb(Sprint->u_arg, 10))
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
					if (Sprint->prec > ft_countnb(Sprint->u_arg, 10))
					{
						fields = fields + (Sprint->prec - ft_countnb(Sprint->u_arg, 10));
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
					if (Sprint->prec > ft_countnb(Sprint->u_arg, 10))
					{
						fields = fields + (Sprint->prec - ft_countnb(Sprint->u_arg, 10));
					}
					putblank(Sprint->width - fields);
				}
				if (Sprint->flagPlus == 1 && min == 0)
					ft_putchar('+');
				if (Sprint->prec > ft_countnb(Sprint->u_arg, 10))
				{
					while(i < Sprint->prec - ft_countnb(Sprint->u_arg, 10))
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
	free(tmp);
}
