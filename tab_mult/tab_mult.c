#include <unistd.h>
#include <stdio.h>

int ft_atoi(char *str)
{
	int res = 0;
	int i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (10 * res) + (str[i] - '0');
		i++;
	}
	return (res);
}

void ft_putnbr(int nb)
{
	if (nb > 9)
		ft_putnbr(nb / 10);
	char c = (nb % 10) + 48;
	write(1, &c, 1);
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int nb = ft_atoi(av[1]);
		int i = 1;
		while (i <= 9)
		{
			ft_putnbr(i);
			write(1, " x ", 3);
			ft_putnbr(nb);
			write(1, " = ", 3);
			ft_putnbr(nb * i);
			write(1, "\n", 1);
			i++;
		}
	}
	else
		write(1, "\n", 1);
}
