/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_treat_x.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: magaspar <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/20 17:13:31 by magaspar     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/20 17:14:26 by magaspar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_treat_x(t_struct *sprint)
{
	int		fields;
	int		min;
	int		i;
	char	*tmp;

	min = 0;
	i = 0;
	if (sprint->type == 'X')
		tmp = ft_itoabase(sprint->u_arg, "0123456789ABCDEF", 16);
	else if (sprint->type == 'x')
		tmp = ft_itoabase(sprint->u_arg, "0123456789abcdef", 16);
	if (sprint->u_arg == 0 && sprint->preczer == 1)
	{
		if (sprint->flagspace == 1)
		{
			sprint->retsize++;
			ft_putchar(' ');
		}
		else
		{
			sprint->retsize += putblank(sprint->width);
		}
	}
	else
	{
		fields = ft_strlen(tmp);
		if (fields >= sprint->width)
		{
			if (sprint->flagdiese == 1 && sprint->u_arg != 0)
			{
				fields += 2;
			}
			if (sprint->flagspace == 1)
			{
				ft_putchar(' ');
				sprint->retsize++;
			}
			if (sprint->flagplus == 1 && min == 0)
			{
				ft_putchar('+');
				sprint->retsize++;
			}
			if (sprint->prec > ft_strlen(tmp))
			{
				if (sprint->flagdiese == 1)
				{
					i += 1;
					sprint->prec += 2;
				}
				while (i < sprint->prec - ft_strlen(tmp))
				{
					if (min == 0)
					{
						min++;
						sprint->prec--;
						if (sprint->flagdiese == 1)
						{
							if (sprint->type == 'x')
								sprint->retsize += ft_putst("0x");
							else if (sprint->type == 'X')
								sprint->retsize += ft_putst("0X");
						}
						else
						{
							ft_putchar('0');
							sprint->retsize++;
						}
					}
					ft_putchar('0');
					sprint->retsize++;
					i++;
				}
			}
			if (sprint->flagdiese && sprint->u_arg != 0 && min == 0)
			{
				if (sprint->type == 'x')
					sprint->retsize += ft_putst("0x");
				else if (sprint->type == 'X')
					sprint->retsize += ft_putst("0X");
			}
			sprint->retsize += ft_putst(tmp);
		}
		else if (fields < sprint->width)
		{
			if (sprint->flagmin == 1)
			{
				if (sprint->flagdiese == 1)
					fields += 2;
				if (sprint->flagspace == 1)
				{
					sprint->retsize++;
					ft_putchar(' ');
				}
				if (sprint->flagplus == 1 && min == 0)
				{
					ft_putchar('+');
					fields++;
					sprint->retsize++;
				}
				if (sprint->prec > ft_strlen(tmp))
				{
					while (i < sprint->prec - ft_strlen(tmp))
					{
						if (sprint->flagdiese == 1)
						{
							if (min == 0)
							{
								i++;
								min++;
								if (sprint->type == 'x')
									sprint->retsize += ft_putst("0x");
								else if (sprint->type == 'X')
									sprint->retsize += ft_putst("0X");
							}
						}
						else
						{
							ft_putchar('0');
							sprint->retsize++;
							i++;
						}
					}
					if (sprint->flagdiese == 1)
						i -= 2;
					fields += i;
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
				{
					if (sprint->flagdiese == 1 && sprint->u_arg != 0)
					{
						if (sprint->type == 'x')
							sprint->retsize += ft_putst("0x");
						else if (sprint->type == 'X')
							sprint->retsize += ft_putst("0X");
						fields += 2;
					}
					sprint->retsize += putzer(sprint->width - fields);
				}
				else if (min != 1)
				{
					if (sprint->prec > ft_strlen(tmp))
					{
						fields = fields + (sprint->prec - ft_strlen(tmp));
					}
					if (sprint->flagdiese == 1 && sprint->u_arg != 0)
					{
						sprint->retsize += putblank(sprint->width - fields - 2);
						if (sprint->type == 'x')
							sprint->retsize += ft_putst("0x");
						else if (sprint->type == 'X')
							sprint->retsize += ft_putst("0X");
					}
					else
						sprint->retsize += putblank(sprint->width - fields);
				}
				if (sprint->flagplus == 1 && min == 0)
				{
					sprint->retsize++;
					ft_putchar('+');
				}
				if (sprint->prec > ft_strlen(tmp))
				{
					while (i < sprint->prec - ft_strlen(tmp))
					{
						sprint->retsize++;
						ft_putchar('0');
						i++;
					}
				}
				sprint->retsize += ft_putst(tmp);
			}
		}
	}
	free(tmp);
}
