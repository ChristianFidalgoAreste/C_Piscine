/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:55:15 by cfidalgo          #+#    #+#             */
/*   Updated: 2023/10/30 18:42:15 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	calculate_base_length(char *base)
{
	int		i;
	int		j;
	char	is_char_repeated;

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

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_length;
	char	array[32];
	int		i;
	long	long_num;

	long_num = (long) nbr;
	i = 0;
	base_length = calculate_base_length(base);
	if (*base == '\0' || base_length < 2)
		return ;
	if (long_num < 0)
	{
		long_num = -long_num;
		write(1, "-", 1);
	}
	else if (long_num == 0)
		write(1, &base[0], 1);
	while (long_num > 0)
	{
		array[i++] = base[long_num % base_length];
		long_num /= base_length;
	}
	while (--i >= 0)
		write(1, &array[i], 1);
}
