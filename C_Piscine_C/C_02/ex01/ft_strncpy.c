/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:05:16 by cfidalgo          #+#    #+#             */
/*   Updated: 2023/10/23 12:56:44 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	cummul;

	cummul = 0;
	while (*src != '\0')
	{
		if (cummul < n)
			*dest = *src;
		else
			break ;
		dest++;
		src++;
		cummul++;
	}
	while (cummul < n)
	{
		*dest = '\0';
		dest++;
		cummul++;
	}
	dest -= cummul;
	return (dest);
}
