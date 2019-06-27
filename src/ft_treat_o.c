/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_treat_o.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: magaspar <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/20 16:57:03 by magaspar     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/27 17:50:59 by magaspar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_treat_o(t_struct *sprint)
{
	int		fields;
	int		min;
	int		i;
	char	*tmp;

	min = 0;
	i = 0;
	tmp = ft_itoabase(sprint->u_arg, "0123456789abcdef", 8);
	if (sprint->u_arg == 0 && sprint->preczer == 1)
	{
		if (sprint->flagspace == 1)
		{
			sprint->retsize++;
			ft_putchar(' ');
		}
		if (sprint->flagdiese == 1)
		{
			sprint->retsize++;
			ft_putchar('0');
		}
		if (sprint->width > 0)
			sprint->retsize += putblank(sprint->width);
	}
	else
	{
		fields = ft_strlen(tmp);
		if (fields >= sprint->width)
		{
			if (sprint->flagdiese == 1 && sprint->u_arg != 0)
				fields++;
			if (sprint->flagspace == 1)
			{
				sprint->retsize++;
				ft_putchar(' ');
			}
			if (sprint->flagplus == 1 && min == 0)
			{
				sprint->retsize++;
				ft_putchar('+');
			}
			if (min == 1)
			{
				sprint->retsize++;
				ft_putchar('-');
			}
			if (sprint->prec > ft_strlen(tmp))
			{
				if (sprint->flagdiese == 1)
				{
					if (sprint->u_arg != 0)
						i++;
				}
				while (i < sprint->prec - ft_strlen(tmp))
				{
					sprint->retsize++;
					ft_putchar('0');
					i++;
				}
			}
			if (sprint->flagdiese && sprint->u_arg != 0)
			{
				sprint->retsize++;
				ft_putchar('0');
			}
			sprint->retsize += ft_putst(tmp);
		}
		else if (fields < sprint->width)
		{
			if (sprint->flagmin == 1)
			{
				if (sprint->flagdiese == 1)
				{
					fields++;
				}
				if (sprint->flagspace == 1)
				{
					sprint->retsize++;
					ft_putchar(' ');
				}
				if (sprint->flagplus == 1 && min == 0)
				{
					sprint->retsize++;
					ft_putchar('+');
					fields++;
				}
				if (sprint->prec > ft_strlen(tmp))
				{
					while (i < sprint->prec - ft_strlen(tmp))
					{
						sprint->retsize++;
						ft_putchar('0');
						i++;
					}
					if (sprint->flagdiese == 1)
						i--;
					fields += i;
				}
				if (sprint->flagdiese == 1 && sprint->prec == 0)
				{
					sprint->retsize++;
					ft_putchar('0');
				}
				sprint->retsize += ft_putst(tmp);
				sprint->retsize += putblank(sprint->width - fields);
			}
			else
			{
				if (sprint->flagspace == 1)
				{
					sprint->retsize++;
					ft_putchar(' ');
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
					if (sprint->flagdiese == 1 && sprint->u_arg != 0)
					{
						sprint->retsize += putblank(sprint->width - fields - 1);
						ft_putchar('0');
						sprint->retsize++;
					}
					else
						sprint->retsize += putblank(sprint->width - fields);
				}
				if (sprint->flagplus == 1 && min == 0)
				{
					sprint->retsize++;
					ft_putchar('+');
				}
				if (sprint->flagdiese == 1)
				{
					sprint->prec++;
				}
				if (sprint->prec > ft_strlen(tmp))
				{
					while (i < sprint->prec - ft_strlen(tmp))
					{
						ft_putchar('0');
						i++;
						sprint->retsize++;
					}
				}
				sprint->retsize += ft_putst(tmp);
			}
		}
	}
	free(tmp);
}
