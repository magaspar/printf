#include "ft_printf.h"

static int ft_intlen(long n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static unsigned long long ft_ulen(unsigned long long n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		i++;
		if (i >= 21)
			return(21);
	}
	return (i);
}

char *ft_itoa(long long int  j)
{
	char *str;
	long i;

	i = ft_intlen(j);
	if (!j)
		return (str = ft_strdup("0"));
	if (!(str = (char *)malloc(sizeof(char) * ft_intlen(j) + 1)))
		return (NULL);
	str[i--] = '\0';
	if (j < 0)
	{
		j = -j;
		str[0] = '-';
	}
	while (j > 0)
	{
		str[i] = j % 10 + '0';
		j = j / 10;
		i--;
	}
	return (str);
}
char *ft_utoa(unsigned long long int  j)
{
	char *str;
	long i;

	i = ft_ulen(j);
	if (!j)
		return (str = ft_strdup("0"));
	if (!(str = (char *)malloc(sizeof(char) * ft_intlen(j) + 1)))
		return (NULL);
	str[i--] = '\0';
	while (j > 0)
	{
		str[i] = j % 10 + '0';
		j = j / 10;
		i--;
	}
	return (str);
}



void		ft_putnbr(int nb)
{
	unsigned int n;

	n = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		n = nb * -1;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		ft_putchar(n + '0');
	}
}

char	*ft_strneww(size_t size)
{
	char *str;
	size_t i;

	i = 0;
	str = (char *)malloc(sizeof(char) * size + 1);
	if (str == NULL)
		return (NULL);
	while (i < size)
	{
		str[i] = '\0';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strrev(char *str)
{
	int i;
	int b;
	char c;

	i = 0;
	b = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	i--;
	while (i > b)
	{
		c = str[b];
		str[b] = str[i];
		str[i] = c;
		b++;
		i--;
	}
	return (str);
}

int		ft_countnb(uintmax_t nbr, int baselen)
{
	int		i;

	i = 0;
	if (nbr == 0)
		return (1);
	else
	{
		while (nbr)
		{
			nbr /= baselen;
			i++;
		}
		return (i);
	}
}

char	*ft_itoabase(uintmax_t nbr, char *base, int baselen)
{
	int tmp;
	int i;
	char *ret;

	tmp = 0;
	i = 0;
	if ((ret = ft_strneww(ft_countnb(nbr, baselen))) == NULL)
		return (NULL);
	while (nbr != 0 || i == 0)
	{
		tmp = nbr % baselen;
		tmp = (tmp < 0) ? -tmp : tmp;
		ret[i] = base[tmp];
		nbr /= baselen;
		i++;
	}
	ret[i] = '\0';
	ft_strrev(ret);
	return (ret);
}



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


int			ft_putst(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
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
