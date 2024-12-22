#include <stdlib.h>
#include <unistd.h>

int ft_count_words(char *str)
{
	int count = 0;
	while (*str)
	{
		while (*str && (*str == ' ' || *str == '\t'))
			str++;
		if (*str)
			count++;
		while (*str && !(*str == ' ' || *str == '\t'))
			str++;
	}
	return (count);
}

void ft_free_res(char **res, int i)
{
	while (i >= 0)
		free(res[i--]);
}

char **ft_allocate_res(char **res, char *str)
{
	int i = 0;
	int count = 0;
	while (*str)
	{
		count = 0;
		while (*str && (*str == ' ' || *str =='\t'))
			str++;
		while (*str && *str != ' ' && *str != '\t')
		{
			count++;
			str++;
		}
		if (count)
		{
			res[i++] = (char *) malloc(count + 1);
			if (!res[i - 1])
			{
				ft_free_res(res, i - 1);
			}
		}
	}
	return (res);
}

void ft_fill_res(char **res, char *str)
{
	int i = 0;
	int j = 0;
	while (*str)
	{
		i = 0;
		while (*str && (*str == ' ' || *str == '\t'))
			str++;
		while (*str && *str != ' ' && *str != '\t')
			res[j][i++] = *str++;
		if (*(str - 1) != ' ' && *(str - 1) != '\t')
			res[j][i] = '\0';
		j++;
	}
	res[j] = NULL;
}

char **ft_split(char *str, int *res_len)
{
	if (!str)
		return (NULL);
	*res_len = ft_count_words(str);
	char **res = (char **) malloc(sizeof(char *) * (*res_len + 1));
	if (!res)
		return (NULL);
	res = ft_allocate_res(res, str);
	if (!res)
		return (NULL);
	ft_fill_res(res, str);
	return (res);
}

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

int main(int ac, char *av[])
{
	if (ac == 2)
	{
		int res_len = 0;
		int j = 0;
		int i = 0;
		char **res = ft_split(av[1], &res_len);
		if (!res)
			return (write(1, "\n", 1));
		j = res_len - 1;
		while (j >= 0)
		{
			i = ft_strlen(res[j]);
			write(1, res[j], i);
			if (j > 0)
				write(1, " ", 1);
			j--;
		}
	}
	return (write(1, "\n", 1));
}
