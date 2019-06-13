#include "ft_printf.h"

char		*ft_strncpy(char *dest, char *src, size_t n)
{
	unsigned int i;

	i = 0;
	while ((src[i] != '\0') && (i < n))
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}


void		ft_putnstr(char *str, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		ft_strlen(char * str)
{
	int i;
	i = 0;

	while(str[i] != '\0')
		i++;
	return (i);
}

char *ft_strdup(char *src)
{
	int n;
	char *tab;

	n = 0;
	n = ft_strlen(src);
	if (!(tab = (char*)(malloc(sizeof(char) * (n + 1)))))
		return (NULL);
	n = 0;
	while (src[n] != '\0')
	{
		tab[n] = src[n];
		n++;
	}
	tab[n] = '\0';
	return (tab);
}

int		ft_strchar(char *s, char c)
{
	int i;
	int n;

	i = 0;
	n = ft_strlen(s);
	while (i <= n)
	{
		if (s[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_atoi(char *str)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] == '-')
		j = 1;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		k = k * 10;
		k = k + str[i] - '0';
		i++;
	}
	if (j)
		return(-k);
	else
		return(k);
}
