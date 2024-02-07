/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:53:52 by cfidalgo          #+#    #+#             */
/*   Updated: 2023/10/29 00:43:54 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	calculate_base_exp(int base_value, int power)
{
	int	i;
	int	res;

	i = 0;
	res = 1;
	while (i++ < power)
		res *= base_value;
	return (res);
}

int	calculate_base_length(char *base)
{
	int	i;
	int	j;
	int	is_char_repeated;

	i = 0;
	j = 1;
	is_char_repeated = 0;
	while (base[i] != '\0')
	{
		while (base[j] != '\0')
			if (base[i] == base[j++])
				is_char_repeated = 1;
		if (base[i] == '+' || base[i] == '-'
			|| base[i] < 32 || base[i] >= 127 || is_char_repeated)
			return (1);
		i++;
		j = i + 1;
	}
	return (i);
}

int	calculate_neg(char **str, char *base)
{
	int	num_of_negs;

	num_of_negs = 0;
	while ((**str >= 9 && **str <= 13) || **str == ' ')
		*str = *str + 1;
	while (**str == '-' || **str == '+')
	{
		if (**str == '-')
			num_of_negs++;
		*str = *str + 1;
	}
	if ((**str >= 9 && **str <= 13) || **str == ' ')
		return (-1);
	while (**str == *base)
		*str = *str + 1;
	return (num_of_negs);
}

int	check_and_calculate_each_digit(char *digit, char *base, int check)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (check)
	{
		while (digit[i] != '\0')
		{
			while (digit[i] != base[j] && base[j] != '\0')
				j++;
			if (base[j] == '\0')
				return (i);
			i++;
			j = 0;
		}
		return (i);
	}
	while (base[i] != *digit)
		i++;
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	num_of_negs;
	int	base_length;
	int	result;
	int	i;

	i = 0;
	result = 0;
	num_of_negs = calculate_neg(&str, base);
	base_length = calculate_base_length(base);
	if (base_length == 1 || *base == '\0')
		return (0);
	i = check_and_calculate_each_digit(str, base, 1);
	while (--i >= 0)
		result += check_and_calculate_each_digit(str++, base, 0)
			* calculate_base_exp(base_length, i);
	if (num_of_negs % 2 == 1)
		return (result * -1);
	return (result);
}
