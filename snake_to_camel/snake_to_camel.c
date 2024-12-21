#include <stdlib.h>
#include <unistd.h>

int ft_strlen(char *str)
{
	int i = 0;
	while (*str)
	{
		if (*str != '_')
			i++;
		str++;
	}
	return (i);
}

int main(int ac, char *av[])
{
	if (ac == 2)
	{
		int i=0;
		int j=0;
		int str_len = ft_strlen(av[1]);
		char *res = (char *) malloc(str_len);
		if (!res)
			return (0);
		while (av[1][j])
		{
			if (av[1][j] == '_')
			{
				j++;
				if (av[1][j] >= 97 && av[1][j] <= 122)
					av[1][j] -= 32;
			}
			res[i++] = av[1][j++];
		}
		write(1, res, i);
		free(res);
	}
	write(1, "\n", 1);
	return (0);

}
