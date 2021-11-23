#include "minitalk.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
}


size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putnbr_fd(long long n, int fd)
{
	if (n == 0)
		ft_putchar_fd('0', fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n / -10)
			ft_putnbr_fd(n / -10, fd);
		ft_putchar_fd('0' - n % 10, fd);
	}
	else
	{
		if (n / -10)
			ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd('0' + n % 10, fd);
	}
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}


static int	ft_is_space(char ch)
{
	if ((ch >= 9 && ch <= 13) || ch == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	x;
	int	minus;

	x = 0;
	minus = -1;
	while (ft_is_space(*str))
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			minus = 1;
	while (*str && ft_isdigit(*str))
		x = x * 10 - (*str++ - '0');
	return (x * minus);
}
