/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:52:26 by arcanava          #+#    #+#             */
/*   Updated: 2023/11/08 15:52:29 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str);

long	check_sign(long number, int is_negative)
{
	if (is_negative)
		number *= -1;
	return (number);
}

long	ft_atoi(char *str)
{
	int		is_negative;
	long	number;
	int		mod;
	long	i;

	is_negative = 0;
	number = 0;
	mod = 1;
	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			if (is_negative)
				return (-1);
			number += (str[i] - '0') * mod;
			mod *= 10;
		}
		else if (str[i] == '-')
			is_negative = !is_negative;
		else if (str[i] != '+')
			return (-1);
		i--;
	}
	return (check_sign(number, is_negative));
}
