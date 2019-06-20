/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_treat_modulo.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: magaspar <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/20 16:45:36 by magaspar     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/20 16:45:44 by magaspar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_treat_modulo(t_struct *sprint)
{
	int i;

	i = 0;
	sprint->retsize++;
	if (sprint->width == 0 || sprint->width == 1)
		ft_putchar('%');
	else if (sprint->width > 0 && sprint->flagzer == 0 && sprint->flagmin == 0)
	{
		while (i < sprint->width - 1)
		{
			ft_putchar(' ');
			if (i == sprint->width - 2)
				ft_putchar('%');
			sprint->retsize++;
			i++;
		}
	}
	else if (sprint->width > 0 && sprint->flagmin == 1 && sprint->flagzer == 0)
	{
		while (i < sprint->width - 1)
		{
			if (i == 0)
				ft_putchar('%');
			ft_putchar(' ');
			sprint->retsize++;
			i++;
		}
	}
	else if (sprint->width > 0 && sprint->flagmin == 1 && sprint->flagzer == 1)
	{
		while (i < sprint->width - 1)
		{
			if (i == 0)
				ft_putchar('%');
			ft_putchar(' ');
			sprint->retsize++;
			i++;
		}
	}
	else if (sprint->width > 0 && sprint->flagmin == 0 && sprint->flagzer == 1)
	{
		while (i < sprint->width - 1)
		{
			ft_putchar('0');
			if (i == sprint->width - 2)
				ft_putchar('%');
			sprint->retsize++;
			i++;
		}
	}
}
