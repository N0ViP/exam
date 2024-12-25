#include <unistd.h>

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int i = 0;
		av++;
		while (**av && (**av == ' ' || **av == '\t'))
			(*av)++;
		while ((*av)[i] && (*av)[i] != ' ' && (*av)[i] != '\t')
			i++;
		if (i)
			write(1, *av, i);
	}
	write(1, "\n", 1);
}
