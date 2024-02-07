/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:13:25 by cfidalgo          #+#    #+#             */
/*   Updated: 2023/10/25 18:30:27 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*dest != '\0')
	{
		i++;
		dest++;
	}
	while (*src != '\0')
	{
		*dest = *src;
		j++;
		src++;
		dest++;
	}
	*dest = '\0';
	dest -= i + j;
	return (dest);
}
