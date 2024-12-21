#include <unistd.h>

int ft_check_prime(int nb)
{
	int tmp = nb - 1;
	while (tmp > 1)
	{
		if (nb % tmp == 0)
			return (0);
		tmp--;
	}
	return (1);
}

int ft_atoi(char *str)
{
	int res;
	while (*str >= '0' && *str <= '9')
	{
		if (res < 0)
			return (-1);
		res = (10 * res) + (*str - '0');
		str++;
	}
	return (res);
}

void ft_putnbr(int nb)
{
	char c;
	if (nb > 9)
		ft_putnbr(nb / 10);
	c = (nb % 10) + '0';
	write(1, &c, 1);
}

int main(int ac, char *av[])
{
	if (ac != 2 || av[1][0] == '0')
		return (write(1, "0\n", 2));
	int nb = ft_atoi(av[1]);
	if (nb == -1)
		return (write(1, "0\n", 1));
	int res = 0;
	while (nb > 1)
	{
		if (ft_check_prime(nb) != 0)
			res += nb;
		nb--;
	}
	ft_putnbr(res);
	write(1, "\n", 1);
}
