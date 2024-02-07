/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:30:06 by cfidalgo          #+#    #+#             */
/*   Updated: 2023/10/30 17:31:22 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	calculate_neg_nums(char **str_addr)
{
	int	neg_nums;

	neg_nums = 0;
	while ((**str_addr >= 9 && **str_addr <= 13) || **str_addr == ' ')
		(*str_addr)++;
	while (**str_addr == '-' || **str_addr == '+')
	{
		if (**str_addr == '-')
			neg_nums++;
		*str_addr = *str_addr + 1;
	}
	if ((**str_addr >= 9 && **str_addr <= 13) || **str_addr == ' ')
		return (-1);
	return (neg_nums);
}

int	calculate_string_length(char *str)
{
	int	i;

	i = 0;
	while (*str >= '0' && *str <= '9')
	{
		str++;
		i++;
	}
	str -= i;
	return (i);
}

int	ft_atoi(char *str)
{
	unsigned int	num;
	int				i;
	int				neg_nums;

	num = 0;
	neg_nums = calculate_neg_nums(&str);
	if (neg_nums == -1)
		return (0);
	while (*str == '0')
		str++;
	i = calculate_string_length(str);
	while (i > 0)
	{
		num = num * 10 + ((*str - '0'));
		str++;
		i--;
	}
	if (neg_nums % 2 == 1)
		return (num * -1);
	return (num);
}
