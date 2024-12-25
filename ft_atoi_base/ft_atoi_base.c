int ft_index(char *base, int str_base, char c)
{
	int i = 0;
	int idx = -1;
	while (i < str_base)
	{
		if (base[i] == c)
		{
			idx = i;
			break ;
		}
		i++;
	}
	return (idx);
}

int ft_atoi_base(char *str, int str_base)
{
	int res = 0;
	int sign = 1;
	char *hex = "0123456789abcdef";
	char *HEX = "0123456789ABCDEF";
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && (ft_index(hex, str_base, *str) != -1|| ft_index(HEX, str_base, *str) != -1))
	{
		if (*str >= 97 && *str <= 122)
			res = (res * str_base) + ft_index(hex, str_base, *str);
		else
			res = (res * str_base) + ft_index(HEX, str_base, *str);
		str++;
	}
	return (res * sign);
}
