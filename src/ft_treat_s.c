/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_treat_s.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: magaspar <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/20 16:48:05 by magaspar     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/20 16:49:06 by magaspar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		putblank(int n)
{
	int i;

	i = -1;
	while (++i < n)
		ft_putchar(' ');
	return (i);
}

void	ft_treat_s(t_struct *sprint)
{
	int fields;

	fields = 0;
	if (sprint->s_arg == NULL)
	{
		sprint->s_arg = "(null)";
	}
	fields = ft_strlen(sprint->s_arg);
	if (sprint->prec > 0 || sprint->preczer == 1)
	{
		if (sprint->preczer == 1)
			fields = 0;
		else
		{
			if (ft_strlen(sprint->s_arg) <= sprint->prec)
				fields = ft_strlen(sprint->s_arg);
			else
				fields = sprint->prec;
		}
	}
	if (fields >= sprint->width)
	{
		ft_putnstr(sprint->s_arg, fields);
		sprint->retsize += fields;
	}
	else if (fields < sprint->width)
	{
		if (sprint->flagmin == 1)
		{
			ft_putnstr(sprint->s_arg, fields);
			putblank(sprint->width - fields);
		}
		else
		{
			putblank(sprint->width - fields);
			ft_putnstr(sprint->s_arg, fields);
		}
		sprint->retsize = sprint->retsize + sprint->width;
	}
}
