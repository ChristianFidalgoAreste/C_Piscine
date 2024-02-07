/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:02:20 by cfidalgo          #+#    #+#             */
/*   Updated: 2023/10/30 22:27:10 by cfidalgo         ###   ########.fr       */
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
	return (0);
}
