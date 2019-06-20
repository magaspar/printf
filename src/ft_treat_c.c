/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_treat_c.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: magaspar <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/20 16:44:44 by magaspar     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/20 16:45:14 by magaspar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_treat_c(t_struct *sprint)
{
	int i;

	i = 0;
	sprint->retsize++;
	if (sprint->width == 0 || sprint->width == 1)
	{
		ft_putchar((char)sprint->arg);
	}
	else if (sprint->width > 0 && sprint->flagzer == 0 && sprint->flagmin == 0)
	{
		while (i < sprint->width - 1)
		{
			ft_putchar(' ');
			if (i == sprint->width - 2)
				ft_putchar((char)sprint->arg);
			sprint->retsize++;
			i++;
		}
	}
	else if (sprint->width > 0 && sprint->flagmin == 1 && sprint->flagzer == 0)
	{
		while (i < sprint->width - 1)
		{
			if (i == 0)
				ft_putchar((char)sprint->arg);
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
				ft_putchar((char)sprint->arg);
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
				ft_putchar((char)sprint->arg);
			sprint->retsize++;
			i++;
		}
	}
}
