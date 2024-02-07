/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:01:05 by cfidalgo          #+#    #+#             */
/*   Updated: 2023/10/31 13:05:01 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long	max_n;
	long	min_n;
	long	mid;
	long	square;

	max_n = nb;
	min_n = 0;
	if (nb <= 0 || nb == 2)
		return (0);
	while (min_n <= max_n)
	{
		mid = (min_n + max_n) / 2;
		square = mid * mid;
		if (square == nb)
			return (mid);
		else if (square < nb)
			min_n = mid + 1;
		else
			max_n = mid - 1;
	}
	return (mid);
}

int	ft_is_prime(int nb)
{
	int	i;
	int	square;

	i = 2;
	if (nb <= 1)
		return (0);
	if (nb == 2)
		return (1);
	square = ft_sqrt(nb);
	while (nb % i != 0 && i < square)
		i++;
	if (i == square && nb % i != 0)
		return (1);
	return (0);
}

int	ft_find_next_prime(int nb)
{
	int	next_num;

	next_num = nb;
	if (nb <= 2)
		return (2);
	if (next_num % 2 == 0)
		next_num++;
	while (next_num > 0)
	{
		if (ft_is_prime(next_num))
			break ;
		next_num += 2;
	}
	return (next_num);
}
