/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_treat_d.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: magaspar <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/20 16:44:36 by magaspar     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/27 18:35:04 by magaspar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		putzer(int i)
{
	int		j;

	j = 0;
	while (j < i)
	{
		ft_putchar('0');
		j++;
	}
	return (j);
}

void	ft_treat_d(t_struct *sprint)
{
	int		fields;
	int		min;
	int		i;
	char	*tmp;
	int		ut;
	int		t;

	min = 0;
	i = 0;
	ut = 0;
	fields = 0;
	t = 0;
	if (sprint->arg < 0)
	{
		tmp = ft_itoa(-sprint->arg);
		if (ft_strchar(tmp, '-'))
		{
			free(tmp);
			tmp = ft_strdup("9223372036854775808");
		}
	}
	else
		tmp = ft_itoa(sprint->arg);
	if (sprint->arg == 0 && sprint->preczer == 1)
	{
		if (sprint->flagplus)
		{
			sprint->retsize++;
			ft_putchar('+');
		}
		if (sprint->flagspace == 1)
		{
			sprint->retsize++;
			ft_putchar(' ');
			fields++;
		}
		if (sprint->width > 0)
			sprint->retsize += putblank(sprint->width);
	}
	else
	{
		if (sprint->arg < 0)
		{
			sprint->arg = -sprint->arg;
			min = 1;
			fields = ft_countnb(sprint->arg, 10) + 1;
		}
		else
		{
			fields = ft_countnb(sprint->arg, 10);
		}
		if (fields >= sprint->width)
		{
			if (sprint->flagspace == 1 && sprint->prec == 0 && !sprint->flagplus && !sprint->flagzer && min == 0)
			{
				fields++;
				ft_putchar(' ');
				sprint->retsize++;
			}
			if (sprint->flagplus == 1 && min == 0)
			{
				sprint->retsize++;
				ft_putchar('+');
			}
			if (min == 1)
			{
				ft_putchar('-');
				sprint->retsize++;
			}
			if (sprint->prec > ft_countnb(sprint->arg, 10))
			{
				while (i < sprint->prec - ft_countnb(sprint->arg, 10))
				{
					ft_putchar('0');
					i++;
				}
				sprint->retsize += i;
			}
			sprint->retsize += ft_putst(tmp);
		}
		else if (fields < sprint->width)
		{
			if (sprint->flagmin == 1)
			{
				if (sprint->flagspace == 1 && sprint->prec == 0)
				{
					fields++;
					ft_putchar(' ');
					sprint->retsize++;
				}
				if (sprint->flagplus == 1 && min == 0)
				{
					sprint->retsize++;
					ft_putchar('+');
					fields++;
				}
				if (min == 1)
				{
					ft_putchar('-');
					sprint->retsize++;
				}
				if (sprint->prec > ft_countnb(sprint->arg, 10))
				{
					sprint->retsize += putzer(sprint->prec - ft_countnb(sprint->arg, 10));
					ut = sprint->prec - ft_countnb(sprint->arg, 10);
					sprint->retsize += ft_putst(tmp);
					sprint->retsize += putblank(sprint->width - fields - ut);
				}
				else
				{
					sprint->retsize += ft_putst(tmp);
					sprint->retsize += putblank(sprint->width - fields);
				}
			}
			else
			{
				if (min == 1)
				{
					if (sprint->prec > ft_countnb(sprint->arg, 10))
					{
						fields = fields + (sprint->prec - ft_countnb(sprint->arg, 10));
					}
					if (sprint->flagzer != 1)
						sprint->retsize += putblank(sprint->width - fields);
					ft_putchar('-');
					sprint->retsize++;
				}
				if (sprint->flagspace == 1 && sprint->prec == 0)
				{
					fields++;
					ft_putchar(' ');
					sprint->retsize++;
				}
				if (sprint->flagplus == 1 && min != 1)
					fields++;
				if (sprint->flagzer == 1 && sprint->prec == 0 && sprint->preczer == 0)
				{
					if (sprint->flagplus == 1 && min == 0)
					{
						ft_putchar('+');
						sprint->retsize++;
						t = 1;
					}
					sprint->retsize += putzer(sprint->width - fields);
				}
				else if (min != 1)
				{
					if (sprint->prec > ft_countnb(sprint->arg, 10))
					{
						fields = fields + (sprint->prec - ft_countnb(sprint->arg, 10));
					}
					sprint->retsize += putblank(sprint->width - fields);
				}
				if (sprint->flagplus == 1 && min == 0 && t == 0)
				{
					ft_putchar('+');
					sprint->retsize++;
				}
				if (sprint->prec > ft_countnb(sprint->arg, 10))
				{
					while (i < sprint->prec - ft_countnb(sprint->arg, 10))
					{
						ft_putchar('0');
						i++;
					}
					sprint->retsize += i;
				}
				sprint->retsize += ft_putst(tmp);
			}
		}
	}
	free(tmp);
}
