/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 22:48:18 by czang             #+#    #+#             */
/*   Updated: 2022/06/18 22:05:43 by czang            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pushswap.h"

u_int16_t	ft_strlen(char *str)
{
	t_string	tmp;

	if (!str)
		return (0);
	tmp = str;
	while (*tmp)
		tmp++;
	return (tmp - str);
}

t_string	ft_strjoin(t_string str1, t_string str2)
{
	t_string		str;
	u_int16_t		i;
	t_string		tmp;

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

bool	ft_atoi(t_string str, int32_t *num2)
{
	int64_t		num;

	num = 0;
	if (str[0] == '-')
	{
		*num2 = -1;
		str++;
	}
	else if (str[0] == '+')
		str++;
	if (ft_strlen(str) > 10)
		return (false);
	while (*str)
	{
		if (*str > '9' || *str < '0')
			return (false);
		num = num * 10 + *str - '0';
		str++;
	}
	if (*num2 == -1)
		num *= -1;
	if (num > INT32_MAX || num < INT32_MIN)
		return (false);
	*num2 = num;
	return (true);
}

void	print(t_string str)
{
	write(1, str, ft_strlen(str));
}
