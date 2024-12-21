#include <stdlib.h>
#include <unistd.h>

int ft_count_words(char *str)
{
	int count = 0;
	while (*str)
	{
		while (*str && (*str == ' ' || *str == '\t' || *str == '\n'))
			str++;
		if (*str)
			count++;
		while (*str && *str != ' ' && *str != '\t' && *str != '\n')
			str++;
	}
	return (count);
}

void ft_free_res(char **res)
{
	int i = 0;
	while (*res)
		free(res[i++]);
}

char **ft_allocate_res(char **res, char *str)
{
	int i = 0;
	int j = 0;
	while (*str)
	{
		i = 0;
		while (*str && (*str == ' ' || *str == '\t' || *str == '\n'))
			str++;
		while (*str && *str != ' ' && *str != '\t' && *str != '\n')
		{
			i++;
			str++;
		}
		if (i)
		{
			res[j] = (char *) malloc(i + 1);
			if (!res[j])
			{
				ft_free_res(res);
				return (NULL);
			}
			j++;
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
		j = 0;
		while (*str && (*str == ' ' || *str == '\t' || *str == '\n'))
			str++;
		while (*str && *str != ' ' && *str != '\t' && *str != '\n')
			res[i][j++] = *str++;
		if (*(str - 1) != ' ' && *(str - 1) != '\t' && *(str - 1) != '\n')
			res[i][j] = '\0';
		i++;
	}
	res[i] = NULL;
}

char    **ft_split(char *str)
{
	int words = ft_count_words(str);
	char **res = (char **) malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	res = ft_allocate_res(res, str);
	if (!res)
		return (NULL);
	ft_fill_res(res, str);
	return (res);
}
/*
int main()
{
	int i = 0;
	char **res = ft_split("     this\njust\t test         ");
	while (res[i])
	{
		hhhhhh("|%s|\n", res[i++]);
	}
}
*/
