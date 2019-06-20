/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_treat_p.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: magaspar <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/20 16:47:15 by magaspar     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/20 16:47:46 by magaspar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_treat_p(t_struct *sprint)
{
	int		i;
	char	*tmps;
	int		fields;

	tmps = ft_itoabase(sprint->arg, "0123456789abcdef", 16);
	fields = ft_strlen(tmps) + 2;
	i = 0;
	if (sprint->prec > 0 || sprint->preczer == 1)
	{
		if (sprint->preczer == 1)
			fields = 0;
		else
		{
			if (fields <= sprint->prec)
				fields = ft_strlen(tmps) + 2;
			else
				fields = sprint->prec;
		}
	}
	if (fields >= sprint->width)
	{
		ft_putnstr("0x", 2);
		ft_putnstr(tmps, fields - 2);
		sprint->retsize += fields;
	}
	else if (fields < sprint->width)
	{
		if (sprint->flagmin == 1)
		{
			ft_putnstr("0x", 2);
			ft_putnstr(tmps, fields - 2);
			putblank(sprint->width - fields);
		}
		else
		{
			putblank(sprint->width - fields);
			ft_putnstr("0x", 2);
			ft_putnstr(tmps, fields - 2);
		}
		sprint->retsize = sprint->retsize + sprint->width;
	}
	free(tmps);
}
