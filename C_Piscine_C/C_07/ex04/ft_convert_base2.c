/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:14:23 by cfidalgo          #+#    #+#             */
/*   Updated: 2023/11/02 20:28:14 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	calculate_neg(char **nbr, char *base_from)
{
	int	negs;

	negs = 0;
	while ((**nbr >= 9 && **nbr <= 13) || **nbr == ' ')
		*nbr = *nbr + 1;
	while (**nbr == '-' || **nbr == '+')
	{
		if (**nbr == '-')
			negs++;
		*nbr = *nbr + 1;
	}
	if ((**nbr >= 9 && **nbr <= 13) || **nbr == ' ')
		return (-1);
	printf("b0s: %s\n", *nbr);
	while (**nbr == *base_from)
		*nbr = *nbr + 1;
	if (**nbr == '\0')
		*nbr = *nbr - 1;
	printf("a0s: %s\n", *nbr);
	return (negs);
}

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

long	ft_atoi_base(char *nbr, char *base, int negs, int base_length)
{
	int	result;
	int	i;

	i = 0;
	result = 0;
	i = check_and_calculate_each_digit(nbr, base, 1);
	while (--i >= 0)
		result += check_and_calculate_each_digit(nbr++, base, 0)
			* calculate_base_exp(base_length, i);
	if (negs % 2 == 1)
		return (result * -1);
	return (result);
}
