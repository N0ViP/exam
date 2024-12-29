#include <unistd.h>

int main(int ac, char **av)
{
	if (ac == 2)
	{
		av++;
		int count = 0;
		int i = 0;
		while ((*av)[i])
		{
			if ((*av)[i] >= 'a' && (*av)[i] <= 'z')
				(*av)[i] = 'z' - ((*av)[i] - 'a');
			if ((*av)[i] >= 'A' && (*av)[i] <= 'Z')
                                (*av)[i] = 'Z' - ((*av)[i] - 'A');
			count++;
			i++;
		}
		write(1, *av, count);
	}
	write(1, "\n", 1);
}
