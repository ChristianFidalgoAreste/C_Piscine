/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:40:27 by cfidalgo          #+#    #+#             */
/*   Updated: 2023/10/25 21:11:08 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*check_for_matches(char *str, char *to_find, int i, int j)
{
	while (*str != '\0')
	{
		if (*str == *to_find)
		{
			while (*to_find != '\0')
			{
				if (*str != *to_find)
					break ;
				i++;
				to_find++;
				str++;
				j++;
			}
			str -= j;
			if (*to_find == '\0')
				return (str);
			else
				to_find -= j;
			j = 0;
		}
		str++;
	}
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	if (to_find[0] == '\0')
		return (str);
	return (check_for_matches(str, to_find, 0, 0));
}
