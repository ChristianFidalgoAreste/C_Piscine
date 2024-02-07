/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:31:47 by cfidalgo          #+#    #+#             */
/*   Updated: 2023/10/25 12:23:31 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	unsigned char	byte;
	int				first_char;
	int				second_char;

	while (*str != '\0')
	{
		if (*str < 32 || *str >= 127)
		{
			byte = *str;
			first_char = "0123456789abcdef"[byte / 16];
			second_char = "0123456789abcdef"[byte % 16];
			write(1, "\\", 1);
			write(1, &first_char, 1);
			write(1, &second_char, 1);
		}
		else
			write(1, str, 1);
		str++;
	}
}
