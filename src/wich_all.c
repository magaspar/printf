/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wich_all.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: magaspar <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/20 17:03:14 by magaspar     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/27 18:36:42 by magaspar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		wich_prec(char *format, t_struct *sprint, int i)
{
	int num;

	num = 0;
	if (ft_strchar("0123456789", format[i + 1]) == 0)
	{
		sprint->preczer = 1;
		return (i);
	}
	else if (ft_strchar("0123456789", format[i + 1]))
	{
		i++;
		while (format[i] >= '0' && format[i] <= '9')
		{
			num = num + format[i] - '0';
			if (ft_strchar("01234567898", format[i + 1]))
				num = num * 10;
			i++;
		}
	}
	sprint->prec = num;
	if (sprint->prec == 0)
		sprint->preczer = 1;
	return (i - 1);
}

int		wich_size(char *format, int i, t_struct *sprint)
{
	int tmp;

	tmp = sprint->size;
	if (format[i] == 'h' && format[i + 1] == 'h')
	{
		tmp = 2;
		i++;
	}
	else if (format[i] == 'h')
		tmp = 1;
	else if (format[i] == 'l')
		tmp = 3;
	else if (format[i] == 'l' && format[i + 1] == 'l')
	{
		tmp = 4;
		i++;
	}
	else if (format[i] == 'L')
		sprint->sizel = 1;
	else if (format[i] == 'z')
		tmp = 5;
	else if (format[i] == 'j')
		tmp = 6;
	if (tmp > sprint->size)
		sprint->size = tmp;
	return (i);
}

int		wich_width(char *format, t_struct *sprint, int i)
{
	int num;

	num = 0;
	while (format[i] >= '0' && format[i] <= '9')
	{
		num = num + format[i] - '0';
		if (ft_strchar("01234567898", format[i + 1]))
			num = num * 10;
		i++;
	}
	sprint->width = num;
	return (i - 1);
}

void	wich_flag(char c, t_struct *sprint)
{
	if (c == '#')
		sprint->flagdiese = 1;
	else if (c == '+')
		sprint->flagplus = 1;
	else if (c == '-')
		sprint->flagmin = 1;
	else if (c == '0')
		sprint->flagzer = 1;
	else if (c == ' ')
		sprint->flagspace = 1;
}
