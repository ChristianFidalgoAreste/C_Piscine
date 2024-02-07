/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:27:27 by cfidalgo          #+#    #+#             */
/*   Updated: 2023/10/24 19:24:34 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	needs_to_be_capitalized;

	needs_to_be_capitalized = 1;
	i = 0;
	while (*str != '\0')
	{
		if (!needs_to_be_capitalized && *str >= 'A' && *str <= 'Z')
			*str += 32;
		if (*str < 'a' || *str > 'z')
			needs_to_be_capitalized = 0;
		if (*str >= 'a' && *str <= 'z' && needs_to_be_capitalized)
		{
			*str -= 32;
			needs_to_be_capitalized = 0;
		}
		if (!((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z')
				|| (*str >= '0' && *str <= '9')))
			needs_to_be_capitalized = 1;
		str++;
		i++;
	}
	str -= i;
	return (str);
}
