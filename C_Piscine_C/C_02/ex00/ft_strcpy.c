/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:44:14 by cfidalgo          #+#    #+#             */
/*   Updated: 2023/10/23 11:03:43 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	cummul;

	cummul = 0;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
		cummul++;
	}
	*dest = *src;
	dest -= cummul;
	return (dest);
}
