
#include "libft.h"

void	putnbr_fd(int n, int fd)
{
	int	exponent;
	int	sign;
	int	i;
	char	buff;

	sign = (n < 0) ? 1 : 0;
	exponent = 1;
	i = n;
	while ((i = i / 10))
		exponent *= 10;
	if (sign)
		write(fd, "-", 1);
	while (exponent) {
		i = n / exponent;
		buff = (sign) ? HEX_T(-(i % 10)) : HEX_T((i % 10));
		n -= i * exponent;
		write(fd, &buff, 1);
		exponent /= 10;
	}
}