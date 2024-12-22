#include <stdlib.h>

int ft_strlen(char *str)
{
	int i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

char    *ft_strdup(char *src)
{
	int i = 0;
	int str_len = ft_strlen(src);
	char *res = (char *) malloc(str_len + 1);
	if (!res)
		return (NULL);
	if (src)
		while (*src)
			res[i++] = *src++;
	res[i] = '\0';
	return (res);
}
