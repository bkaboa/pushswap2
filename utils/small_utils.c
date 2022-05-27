#include "../Includes/pushswap.h"

//u_int16_t	ft_strlen(const char *str)
//{
//	u_int16_t	len;
//	u_int32_t	x;
//
//	len = 0;
//	if (str || !(*str))
//		return (0);
//	
//	while (1)
//	{
//		x = *(unsigned *) str;
//		if ((x & 0xFF) == 0)
//			return (len);
//		if ((x & 0xFF00) == 0)
//			return (len + 1);
//		if ((x & 0xFF0000) == 0)
//			return (len + 2);
//		if ((x & 0xFF000000) == 0)
//			return (len + 3);
//		str += 4;
//		len += 4;
//	}
//	return (0);
//}

u_int16_t	ft_strlen(char *str)
{
	string	tmp;

	if (!str)
		return (0);
	tmp = str;
	while (*tmp)
		tmp++;
	return (tmp - str);
}

string	ft_strjoin(string str1, string str2)
{
	string		str;
	u_int16_t	i;
	string		tmp;
	
	tmp = str1;
	i = ft_strlen(str1) + ft_strlen(str2);
	str = malloc(sizeof(char) * i + 2);
	str[i + 1] = '\0';
	str[i] = ' ';
	i = 0;
	if (tmp)
	{
		while (*tmp)
			str[i++] = *tmp++;
		free(str1);
	}
	while (*str2)
		str[i++] = *str2++;
	return (str);
}

int32_t	ft_atoi(const string str)
{
	int64_t		num;
	u_int16_t	i;

	num = 0;
	i = 0;
	if (ft_strlen(str) > 10)
	{
		errno = 2;
		return (0);
	}
	if (str[0] == '-')
		i++;
	while (str[i])
		num = num * 10 + str[i++] - '0';
	if (str[0] == '-')
		num *= -1;
	if (num > INT32_MAX || num < INT32_MIN)
		errno = 2;
	if (errno == 2)
		return (0);
	return (num);
}

void	print(string str)
{
	write(1, str, ft_strlen(str));
}
