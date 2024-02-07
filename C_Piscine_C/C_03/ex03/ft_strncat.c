/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:30:51 by cfidalgo          #+#    #+#             */
/*   Updated: 2023/10/25 18:40:14 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (*dest != '\0')
	{
		i++;
		dest++;
	}
	while (j < nb && *src != '\0')
	{
		*dest = *src;
		j++;
		dest++;
		src++;
	}
	*dest = '\0';
	dest -= i + j;
	return (dest);
}
