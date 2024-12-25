#include <unistd.h>

void ft_putnbr(int nb)
{
	if (nb  > 9)
		ft_putnbr(nb / 10);
	char x = (nb % 10) + 48;
	write(1, &x, 1);
}

int main()
{
	int i = 1;
	while (i <= 100)
	{
		if (i % 3 == 0)
			write (1, "fizz", 4);
		if (i % 5 == 0)
			write(1, "buzz", 4);
		if (i % 5 != 0 && i % 3 != 0)
			ft_putnbr(i);
		i++;
	write(1, "\n", 1);
	}
}
