/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 21:13:29 by cfidalgo          #+#    #+#             */
/*   Updated: 2023/10/26 12:08:54 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	calculate_string_length(char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		str++;
		i++;
	}
	str -= i;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	result;
	unsigned int	dest_length;
	unsigned int	src_length;

	dest_length = calculate_string_length(dest);
	src_length = calculate_string_length(src);
	i = 0;
	if (size > dest_length)
		result = dest_length + src_length;
	else
		result = size + src_length;
	while (*src != '\0' && size > dest_length + 1)
	{
		dest[dest_length] = *src;
		dest_length++;
		src++;
		i++;
	}
	dest[dest_length] = '\0';
	return (result);
}
