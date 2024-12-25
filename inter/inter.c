#include <unistd.h>

int main(int ac, char **av)
{
	if (ac == 3)
	{
		int i = 0;
		char str[255] = {0};
		while (av[2][i])
		{
			str[(int) av[2][i++]] = '1';
		}
		i = 0;
		while (av[1][i])
		{
			if (str[(int )av[1][i]])
			{
				write(1, &av[1][i], 1);
				str[(int) av[1][i]] = 0;
			}
			i++;
		}
	}
	write(1, "\n", 1);
}
