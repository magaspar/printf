#include "ft_printf.h"


void	ft_treat_o(t_struct *Sprint)
{
	int fields;
	int min;
	int i;
	char *tmp;

	min = 0;
	i = 0;
	tmp = ft_itoabase(Sprint->u_arg, "0123456789abcdef", 8);
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
		fields = ft_strlen(tmp);
		if (fields >= Sprint->width)
		{
			if (Sprint->flagDiese == 1 && Sprint->u_arg != 0)
			{
				fields++;
				Sprint->retSize--;
			}
			if (Sprint->flagSpace == 1)
				ft_putchar(' ');
			if (Sprint->flagPlus == 1 && min == 0)
				ft_putchar('+');
			if (min == 1)
			{
				ft_putchar('-');
			}
			if (Sprint->prec > ft_strlen(tmp))
			{
				if (Sprint->flagDiese == 1)
				{
					Sprint->retSize--;
					i++;
				}
				while(i < Sprint->prec - ft_strlen(tmp))
				{
					ft_putchar('0');
					i++;
				}
				Sprint->retSize += i;
			}
			if (Sprint->flagDiese && Sprint->u_arg != 0)
				ft_putchar('0');
			ft_putst(tmp);
			Sprint->retSize += fields;
		}
		else if(fields < Sprint->width)
		{
			if (Sprint->flagMin == 1)
			{
				if (Sprint->flagDiese == 1)
				{
					fields++;
					Sprint->retSize--;
				}
				if (Sprint->flagSpace == 1)
					ft_putchar(' ');
				if (Sprint->flagPlus == 1 && min == 0)
				{
					ft_putchar('+');
					fields++;
				}
				if (Sprint->prec > ft_strlen(tmp))
				{
					while(i < Sprint->prec - ft_strlen(tmp))
					{
						ft_putchar('0');
						i++;
					}
					if (Sprint->flagDiese == 1)
						i--;
					fields += i;
					Sprint->retSize += i + 1;
				}
				ft_putst(tmp);
				putblank(Sprint->width - fields);
			}
			else
			{
				if (Sprint->flagDiese == 1)
				{
					Sprint->retSize--;
					Sprint->prec++;
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
					if (Sprint->prec > ft_strlen(tmp))
					{
						fields = fields + (Sprint->prec - ft_strlen(tmp));
					}
					if (Sprint->flagDiese == 1 && Sprint->u_arg != 0)
					{
						putblank(Sprint->width - fields - 1);
						ft_putchar('0');
					}
					else
						putblank(Sprint->width - fields);
				}
				if (Sprint->flagPlus == 1 && min == 0)
					ft_putchar('+');
				if (Sprint->prec > ft_strlen(tmp))
				{
					while(i < Sprint->prec - ft_strlen(tmp))
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
		if (Sprint->flagDiese == 1 && Sprint->u_arg != 0)
			Sprint->retSize++;
	}
	free(tmp);
}
