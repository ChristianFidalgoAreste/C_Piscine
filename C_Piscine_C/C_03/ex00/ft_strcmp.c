/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:41:59 by cfidalgo          #+#    #+#             */
/*   Updated: 2023/10/25 17:48:28 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	unsigned char	c_s1;
	unsigned char	c_s2;

	while (*s1 != '\0' && *s2 != '\0')
	{
		c_s1 = *s1;
		c_s2 = *s2;
		if (c_s1 != c_s2)
			return (c_s1 - c_s2);
		s1++;
		s2++;
	}
	c_s1 = *s1;
	c_s2 = *s2;
	if (c_s1 != c_s2)
		return (c_s1 - c_s2);
	return (0);
}
