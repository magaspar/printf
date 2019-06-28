#include "src/ft_printf.h"

int main()
{

	printf("%d\n", ft_printf("%4.15u\n", 42));
	printf("%d\n", printf("%4.15u\n", 42));

	return(0);
}
