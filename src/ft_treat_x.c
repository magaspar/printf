#include "ft_printf.h"


void	ft_treat_x(t_struct *Sprint)
{
	int fields;
	int min;
	int i;
	char *tmp;

	min = 0;
	i = 0;
	if (Sprint->type == 'X')
		tmp = ft_itoabase(Sprint->u_arg, "0123456789ABCDEF", 16);
	else if (Sprint->type == 'x')
		tmp = ft_itoabase(Sprint->u_arg, "0123456789abcdef", 16);
	if (Sprint->u_arg == 0 && Sprint->precZer == 1)
	{
		if (Sprint->flagSpace == 1)
		{
			Sprint->retSize++;
			ft_putchar(' ');
		}
		else
		{
			Sprint->retSize += putblank(Sprint->width);
		}
	}
	else
	{
		fields = ft_strlen(tmp);
		if (fields >= Sprint->width)
		{
			if (Sprint->flagDiese == 1 && Sprint->u_arg != 0)
			{
				fields += 2;
			}
			if (Sprint->flagSpace == 1)
			{
				ft_putchar(' ');
				Sprint->retSize++;
			}
			if (Sprint->flagPlus == 1 && min == 0)
			{
				ft_putchar('+');
				Sprint->retSize++;
			}
			if (Sprint->prec > ft_strlen(tmp))
			{
				if (Sprint->flagDiese == 1)
				{
					i += 1;
					Sprint->prec += 2;
				}
				while(i < Sprint->prec - ft_strlen(tmp))
				{
					if (min == 0)
					{
						min++;
						Sprint->prec--;
						if (Sprint->flagDiese == 1)
						{
							if (Sprint->type == 'x')
								Sprint->retSize += ft_putst("0x");
							else if(Sprint->type == 'X')
								Sprint->retSize += ft_putst("0X");
						}
						else
						{
							ft_putchar('0');
							Sprint->retSize++;
						}
					}
					ft_putchar('0');
					Sprint->retSize++;
					i++;
				}
			}
			if (Sprint->flagDiese && Sprint->u_arg != 0 && min == 0)
			{
				if (Sprint->type == 'x')
					Sprint->retSize += ft_putst("0x");
				else if (Sprint->type == 'X')
					Sprint->retSize += ft_putst("0X");
			}
			Sprint->retSize += ft_putst(tmp);
		}
		else if(fields < Sprint->width)
		{
			if (Sprint->flagMin == 1)
			{
				if (Sprint->flagDiese == 1)
					fields += 2;
				if (Sprint->flagSpace == 1)
				{
					Sprint->retSize++;
					ft_putchar(' ');
				}
				if (Sprint->flagPlus == 1 && min == 0)
				{
					ft_putchar('+');
					fields++;
					Sprint->retSize++;
				}
				if (Sprint->prec > ft_strlen(tmp))
				{
					while(i < Sprint->prec - ft_strlen(tmp))
					{
						if (Sprint->flagDiese == 1)
						{
							if (min == 0)
							{
								i++;
								min++;
								if (Sprint->type == 'x')
									Sprint->retSize += ft_putst("0x");
								else if(Sprint->type == 'X')
									Sprint->retSize += ft_putst("0X");
							}
						}
						else
						{
							ft_putchar('0');
							Sprint->retSize++;
							i++;
						}
					}
					if (Sprint->flagDiese == 1)
						i -= 2;
					fields += i;
				}
				Sprint->retSize += ft_putst(tmp);
				Sprint->retSize += putblank(Sprint->width - fields);
			}
			else
			{
				if (Sprint->flagSpace == 1)
				{
					Sprint->retSize++;
					ft_putchar(' ');
				}
				if (Sprint->flagPlus == 1)
				{
					fields++;
				}
				if (Sprint->flagZer == 1 && Sprint->prec == 0 && Sprint->precZer == 0)
				{
					if (Sprint->flagDiese == 1 && Sprint->u_arg != 0)
					{
						if (Sprint->type == 'x')
							Sprint->retSize += ft_putst("0x");
						else if (Sprint->type == 'X')
							Sprint->retSize += ft_putst("0X");
						fields += 2;
					}
					Sprint->retSize += putZer(Sprint->width - fields);
				}
				else if (min != 1)
				{
					if (Sprint->prec > ft_strlen(tmp))
					{
						fields = fields + (Sprint->prec - ft_strlen(tmp));
					}
					if (Sprint->flagDiese == 1 && Sprint->u_arg != 0)
					{
						Sprint->retSize += putblank(Sprint->width - fields - 2);
						if (Sprint->type == 'x')
							Sprint->retSize += ft_putst("0x");
						else if (Sprint->type == 'X')
							Sprint->retSize += ft_putst("0X");
					}
					else
						Sprint->retSize += putblank(Sprint->width - fields);
				}
				if (Sprint->flagPlus == 1 && min == 0)
				{
					Sprint->retSize++;
					ft_putchar('+');
				}
				if (Sprint->prec > ft_strlen(tmp))
				{
					while(i < Sprint->prec - ft_strlen(tmp))
					{
						Sprint->retSize++;
						ft_putchar('0');
						i++;
					}
				}
				Sprint->retSize += ft_putst(tmp);
			}
		}
	}
	free(tmp);
}
