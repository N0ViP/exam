#include <unistd.h>

int main(int ac, char *av[])
{
	if (ac == 2)
	{
		char *str = av[1];
		while (*str && (*str == ' ' || *str == '\t'))
			str++;
		int i = 0;
		while (*str)
		{
			i = 0;
			while (*(str + i) && *(str + i) != ' ' && *(str + i) != '\t')
				i++;
			write(1, str, i);
			str += i;
			while (*str && (*str == ' ' || *str == '\t'))
				str++;
			if (*str && (*(str - 1) == ' ' || *(str - 1) == '\t'))
				write(1, " ", 1);
		}
	}
	write(1, "\n", 1);
	return (1);
}
