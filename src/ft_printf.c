/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: magaspar <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/20 16:56:18 by magaspar     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/28 16:32:41 by magaspar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void		dispatch(t_struct *sprint)
{
	if (sprint->type == 'u' || sprint->type == 'U')
	{
		ft_treat_u(sprint);
	}
	else if (sprint->type == 'o' || sprint->type == 'O')
		ft_treat_o(sprint);
	else if (sprint->type == 'x' || sprint->type == 'X')
		ft_treat_x(sprint);
}

void		get_and_treat_arg(t_struct *sprint)
{
	if (sprint->type == 'c' || sprint->type == 'C')
	{
		if (sprint->type == 'c')
			sprint->arg = (unsigned char)va_arg(sprint->ap, int);
		else
			sprint->arg = (wint_t)va_arg(sprint->ap, int);
		ft_treat_c(sprint);
	}
	if (sprint->type == 's')
	{
		sprint->s_arg = (char *)va_arg(sprint->ap, char *);
		ft_treat_s(sprint);
	}
	if (sprint->type == 'p')
	{
		sprint->arg = (long long int)va_arg(sprint->ap, void *);
		ft_treat_p(sprint);
	}
	if (sprint->type == 'd' || sprint->type == 'i' || sprint->type == 'D')
	{
		if (sprint->size == 1)
			sprint->arg = (short)va_arg(sprint->ap, long long int);
		else if (sprint->size == 2)
			sprint->arg = (char)va_arg(sprint->ap, long long int);
		else if (sprint->size == 3 || sprint->type == 'D')
			sprint->arg = (long int)va_arg(sprint->ap, long long int);
		else if (sprint->size == 4 || sprint->size == 5 || sprint->size == 6)
			sprint->arg = (long long int)va_arg(sprint->ap, long long int);
		else
			sprint->arg = (int)va_arg(sprint->ap, long long int);
		ft_treat_d(sprint);
	}
	if (sprint->type == 'o' || sprint->type == 'u' ||
			sprint->type == 'x' || sprint->type == 'X' ||
			sprint->type == 'U' || sprint->type == 'O')
	{
		if (sprint->size == 1 && sprint->type != 'U')
			sprint->u_arg = (unsigned short)va_arg(sprint->ap, unsigned int);
		else if (sprint->size == 2)
			sprint->u_arg = (unsigned char)va_arg(sprint->ap, unsigned int);
		else if (sprint->size == 3 || sprint->type == 'U')
			sprint->u_arg = (unsigned long)va_arg(sprint->ap,
					unsigned long int);
		else if (sprint->size == 4 || sprint->size == 5 ||
				sprint->size == 6 || sprint->type == 'O')
			sprint->u_arg = (unsigned long long int)va_arg(sprint->ap,
					unsigned long long int);
		else
			sprint->u_arg = (unsigned int)va_arg(sprint->ap, unsigned int);
		dispatch(sprint);
	}
	if (sprint->type == '%')
		ft_treat_modulo(sprint);
}

int			parse(char *format, int i, t_struct *sprint)
{
	int j;
	int n;

	j = 3;
	n = 0;
	i++;
	while (j != 1 && format[i] != '\0')
	{
		if (ft_strchar("#-+0 ", format[i]) == 1)
			wich_flag(format[i], sprint);
		else if (ft_strchar("123456789", format[i]))
			i = wich_width(format, sprint, i);
		else if (ft_strchar(".", format[i]))
			i = wich_prec(format, sprint, i);
		else if (ft_strchar("hlLzj", format[i]) == 1)
			i = wich_size(format, i, sprint);
		else if (ft_strchar("dDioOuUxXcCsfp%", format[i]) == 1)
		{
			sprint->argsize = j;
			sprint->type = format[i];
			j = 0;
		}
		j++;
		i++;
	}
	return (i);
}

void		reinit(t_struct *sprint)
{
	sprint->type = 0;
	sprint->flagdiese = 0;
	sprint->flagplus = 0;
	sprint->flagmin = 0;
	sprint->flagzer = 0;
	sprint->flagspace = 0;
	sprint->size = 0;
	sprint->width = 0;
	sprint->prec = 0;
	sprint->preczer = 0;
	sprint->sizel = 0;
	sprint->arg = 0;
	sprint->u_arg = 0;
}

t_struct	*init(t_struct *sprint)
{
	if (!(sprint = (t_struct*)malloc(sizeof(t_struct))))
		return (NULL);
	sprint->type = 0;
	sprint->flagdiese = 0;
	sprint->flagplus = 0;
	sprint->flagmin = 0;
	sprint->flagzer = 0;
	sprint->flagspace = 0;
	sprint->size = 0;
	sprint->width = 0;
	sprint->prec = 0;
	sprint->preczer = 0;
	sprint->sizel = 0;
	sprint->arg = 0;
	sprint->retsize = 0;
	sprint->u_arg = 0;
	return (sprint);
}

int			ft_printf(char *format, ...)
{
	t_struct	*sprint;
	int			i;
	int			ret;
	char		*formatt;

	i = 0;
	ret = 0;
	sprint = NULL;
	sprint = init(sprint);
	formatt = ft_strdup(format);
	va_start(sprint->ap, format);
	while (formatt[i])
	{
		if (formatt[i] == '%' && formatt[i + 1] != '\0')
		{
			i = parse(formatt, i, sprint);
			get_and_treat_arg(sprint);
			reinit(sprint);
		}
		else if (formatt[i] != '\0')
		{
			if (formatt[i] == '%' && formatt[i + 1] == '\0')
				break;
			ft_putchar(formatt[i]);
			sprint->retsize++;
			i++;
		}
	}
	ret = sprint->retsize;
	va_end(sprint->ap);
	free(sprint);
	free(formatt);
	return (ret);
}
