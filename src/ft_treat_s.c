#include "ft_printf.h"


void	putblank(int n)
{
	int i;

	i = -1;
	while (++i < n)
		ft_putchar(' ');
}

void	ft_treat_s(t_struct *Sprint)
{
	int fields;

	fields = 0;
	if (Sprint->s_arg == NULL)
	{
		Sprint->s_arg = "(null)";
	}
	fields = ft_strlen(Sprint->s_arg);
	if (Sprint->prec > 0 || Sprint->precZer == 1)
	{
		if (Sprint->precZer == 1)
			fields = 0;
		else
		{
			if (ft_strlen(Sprint->s_arg) <= Sprint->prec)
				fields = ft_strlen(Sprint->s_arg);
			else 
				fields = Sprint->prec;
		}
	}
	if (fields >= Sprint->width)
	{
		ft_putnstr(Sprint->s_arg, fields);
		Sprint->retSize += fields;
	}
	else if(fields < Sprint->width)
	{
		if (Sprint->flagMin == 1)
		{
			ft_putnstr(Sprint->s_arg, fields);
			putblank(Sprint->width - fields);
		}
		else
		{
			putblank(Sprint->width - fields);
			ft_putnstr(Sprint->s_arg, fields);
		}
		Sprint->retSize = Sprint->retSize + Sprint->width;
	}
}
