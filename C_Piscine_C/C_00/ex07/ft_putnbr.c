/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:44:16 by cfidalgo          #+#    #+#             */
/*   Updated: 2023/10/21 12:40:48 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	int	is_negative;
	int	uni;
	int	dec;
	int	cen;

	is_negative = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	uni = (nb % 10) + '0';
	dec = ((nb / 10) % 10) + '0';
	cen = ((nb / 100) % 10) + '0';
	if (cen != '0')
	{
		write(1, &cen, 1);
	}
	if (dec != '0' || cen != '0')
	{
		write(1, &dec, 1);
	}
	write(1, &uni, 1);
}
