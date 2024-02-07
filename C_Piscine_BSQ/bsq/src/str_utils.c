/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:55:32 by arcanava          #+#    #+#             */
/*   Updated: 2023/11/08 15:55:34 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_malloc(unsigned long size);

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (*src != '\0')
	{
		if (i < n)
			*dest = *src;
		src++;
		dest++;
		i++;
	}
	while (i < n)
	{
		*dest = '\0';
		dest++;
		i++;
	}
	dest -= i;
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	augment_str_size(char *str)
{
	char	*aux;
	int		size;

	if (str)
	{
		size = ft_strlen(str);
		aux = ft_malloc(sizeof(str));
		str = ft_malloc(size + sizeof(char *));
		ft_strncpy(str, aux, size);
		free(aux);
	}
}
