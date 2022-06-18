/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:21:19 by czang             #+#    #+#             */
/*   Updated: 2022/06/13 21:28:55 by czang            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pushswap.h"

static char	*yank_to_set(char **str, char set)
{
	t_string	tmp;
	t_string	tmp2;
	int			i;

	tmp2 = *str;
	i = 0;
	while (tmp2[i] != set && tmp2[i])
		i++;
	tmp = malloc(sizeof(char) * i + 1);
	tmp[i] = '\0';
	i = 0;
	while (*tmp2 != set && *tmp2)
		tmp[i++] = *tmp2++;
	*str = tmp2;
	return (tmp);
}

static u_int16_t	number_of_words(t_string str, char set)
{
	u_int16_t	i;

	i = 0;
	while (*str)
	{
		if (*str == set)
		{
			while (*str == set && *str)
				str++;
			if (*str)
				i++;
		}
		if (*str)
			str++;
	}
	i++;
	return (i);
}

static char	**assign_split(char **split, int num, t_string str, char set)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (i < num)
	{
		j = -1;
		tmp = yank_to_set(&str, set);
		while (*str == set && str)
			str++;
		split[i] = malloc(sizeof(char) * ft_strlen(tmp) + 1);
		split[i][ft_strlen(tmp)] = '\0';
		while (tmp[++j])
			split[i][j] = tmp[j];
		free(tmp);
		i++;
	}
	return (split);
}

char	**ft_split(t_string str, char set)
{
	char	**split;
	int		num;

	while (*str == set)
		str++;
	num = number_of_words(str, set);
	split = (char **) malloc(sizeof(char *) * (num + 1));
	if (!split)
		return ((char **) NULL);
	split[num] = NULL;
	return (assign_split(split, num, str, set));
}
