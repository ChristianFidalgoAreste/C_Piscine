/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:57:34 by cfidalgo          #+#    #+#             */
/*   Updated: 2023/11/02 15:26:30 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	calculate_total_length(int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	total_length;

	i = 0;
	total_length = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			total_length++;
			j++;
		}
		i++;
	}
	i = 0;
	while (sep[i] != '\0')
		i++;
	if (size == 0)
		return (1);
	return (total_length + (size - 1) * i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*dest;
	int		i;
	int		j;
	int		k;

	dest = malloc(calculate_total_length(size, strs, sep) * sizeof(char));
	dest[0] = 0;
	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
			dest[k++] = strs[i][j++];
		j = 0;
		if (i != size - 1)
			while (sep[j] != '\0')
				dest[k++] = sep[j++];
		i++;
	}
	dest[k] = '\0';
	return (dest);
}
