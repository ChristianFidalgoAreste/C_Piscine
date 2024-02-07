/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:57:16 by cfidalgo          #+#    #+#             */
/*   Updated: 2023/10/24 20:48:49 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (size > 0)
	{
		while (i < size - 1 && *src != '\0')
		{
			*dest = *src;
			src++;
			dest++;
			i++;
		}
		*dest = '\0';
	}
	while (*src != '\0')
	{
		i++;
		src++;
	}
	dest -= i;
	return (i);
}
