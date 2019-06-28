/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_treat_u.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: magaspar <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/20 17:05:29 by magaspar     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/28 17:06:56 by magaspar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_treat_u(t_struct *sprint)
{
	int		fields;
	int		min;
	int		i;
	char	*tmp;

	min = 0;
	i = 0;
	tmp = ft_utoa(sprint->u_arg);
	if (sprint->u_arg == 0 && sprint->preczer == 1)
	{
		min = 0;
	}
	else
	{
		fields = ft_strlen(tmp);
		if (fields >= sprint->width)
		{
			if (min == 1)
			{
				ft_putchar('-');
				sprint->retsize++;
			}
			if (sprint->prec > ft_strlen(tmp))
			{
				while (i < sprint->prec - ft_strlen(tmp))
				{
					ft_putchar('0');
					sprint->retsize++;
					i++;
				}
			}
			sprint->retsize += ft_putst(tmp);
		}
		else if (fields < sprint->width)
		{
			if (sprint->flagmin == 1)
			{
				if (sprint->flagspace == 1)
				{
					ft_putchar(' ');
					sprint->retsize++;
				}
				if (sprint->flagplus == 1 && min == 0)
				{
					ft_putchar('+');
					sprint->retsize++;
					fields++;
				}
				if (min == 1)
				{
					ft_putchar('-');
					sprint->retsize++;
				}
				if (sprint->prec > ft_strlen(tmp))
				{
					fields = fields + (sprint->prec - ft_strlen(tmp));
					sprint->retsize += putzer(sprint->prec - ft_strlen(tmp));
				}
				sprint->retsize += ft_putst(tmp);
				sprint->retsize += putblank(sprint->width - fields);
			}
			else
			{
				if (min == 1)
				{
					if (sprint->prec > ft_strlen(tmp))
					{
						fields = fields + (sprint->prec - ft_strlen(tmp));
					}
					if (sprint->flagzer != 1)
						sprint->retsize += putblank(sprint->width - fields);
					ft_putchar('-');
					sprint->retsize++;
				}
				if (sprint->flagspace == 1)
				{
					ft_putchar(' ');
					sprint->retsize++;
				}
				if (sprint->flagplus == 1)
				{
					fields++;
				}
				if (sprint->flagzer == 1 && sprint->prec == 0 && sprint->preczer == 0)
					sprint->retsize += putzer(sprint->width - fields);
				else if (min != 1)
				{
					if (sprint->prec > ft_strlen(tmp))
					{
						fields = fields + (sprint->prec - ft_strlen(tmp));
					}
					sprint->retsize += putblank(sprint->width - fields);
				}
				if (sprint->flagplus == 1 && min == 0)
				{
					ft_putchar('+');
					sprint->retsize++;
				}
				if (sprint->prec > ft_strlen(tmp))
				{
					while (i < sprint->prec - ft_strlen(tmp))
					{
						ft_putchar('0');
						sprint->retsize++;
						i++;
					}
				}
				sprint->retsize += ft_putst(tmp);
			}
		}
	}
	free(tmp);
}
