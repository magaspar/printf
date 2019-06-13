#include "ft_printf.h"

void	ft_treat_p(t_struct *Sprint)
{
	int i;

	i = 0;
	char *tmps;
	tmps = ft_itoabase(Sprint->arg, "0123456789abcdef", 16);
	int fields;
	fields = ft_strlen(tmps) + 2;
	if (Sprint->prec > 0 || Sprint->precZer == 1)
	{
		if (Sprint->precZer == 1)
			fields = 0;
		else
		{
			if (fields <= Sprint->prec)
				fields = ft_strlen(tmps) + 2;
			else 
				fields = Sprint->prec;
		}
	}
	if (fields >= Sprint->width)
	{
		ft_putnstr("0x", 2);
		ft_putnstr(tmps, fields - 2);
		Sprint->retSize += fields;
	}
	else if(fields < Sprint->width)
	{
		if (Sprint->flagMin == 1)
		{
			ft_putnstr("0x", 2);
			ft_putnstr(tmps, fields - 2);
			putblank(Sprint->width - fields);
		}
		else
		{
			putblank(Sprint->width - fields);
			ft_putnstr("0x", 2);
			ft_putnstr(tmps, fields);
		}
		Sprint->retSize = Sprint->retSize + Sprint->width;
	}
	free(tmps);
}
