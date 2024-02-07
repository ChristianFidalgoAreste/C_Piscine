/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:29:34 by cfidalgo          #+#    #+#             */
/*   Updated: 2023/10/25 18:12:23 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned char	c_s1;
	unsigned char	c_s2;
	unsigned int	i;

	i = 0;
	while (i < n && *s1 != '\0' && *s2 != '\0')
	{
		c_s1 = *s1;
		c_s2 = *s2;
		if (c_s1 != c_s2)
			return (c_s1 - c_s2);
		s1++;
		s2++;
		i++;
	}
	c_s1 = *s1;
	c_s2 = *s2;
	if (i != n && c_s1 != c_s2)
		return (c_s1 - c_s2);
	return (0);
}
