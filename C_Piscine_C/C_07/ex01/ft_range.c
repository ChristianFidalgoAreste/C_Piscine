/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 21:10:58 by cfidalgo          #+#    #+#             */
/*   Updated: 2023/11/02 15:26:44 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	i;
	int	j;

	if (min >= max)
		return (0);
	range = malloc((max - min) * sizeof(int));
	i = 0;
	j = min;
	while (i < max - min)
	{
		range[i] = j;
		i++;
		j++;
	}
	return (range);
}
