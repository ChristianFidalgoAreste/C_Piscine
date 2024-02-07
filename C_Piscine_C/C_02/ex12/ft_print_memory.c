/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:55:48 by cfidalgo          #+#    #+#             */
/*   Updated: 2023/10/25 20:28:07 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_string(char *str, unsigned int *size);

void	print_spaces(int i)
{
	int	spaces_to_print;

	spaces_to_print = 2 * (15 - i) + (15 - i) / 2 + 2;
	while (spaces_to_print > 0)
	{
		write(1, " ", 1);
		spaces_to_print--;
	}
}

void	print_memory_to_string(char *p)
{
	static char			*table;
	unsigned long		value;
	char				buffer[sizeof(void*) * 2];
	unsigned int		idx;
	int					digit;

	idx = 0;
	table = &"0123456789abcdef"[0];
	value = (unsigned long)p;
	while (value)
	{
		digit = value % 16;
		buffer[idx++] = table[digit];
		value /= 16;
	}
	while (idx < sizeof(buffer))
		buffer[idx++] = '0';
	idx = sizeof(buffer) - 1;
	while (idx > 0)
		write(1, buffer + idx--, 1);
	write(1, buffer, 1);
	write(1, ": ", 2);
}

void	print_string_to_hexa(char *str, int i, unsigned int *size)
{
	unsigned char	byte;
	int				first_char;
	int				second_char;

	while ((*str != '\0' || *size != 0) && i < 16)
	{
		if (*size == 0)
			break ;
		byte = *str;
		first_char = "0123456789abcdef"[byte / 16];
		second_char = "0123456789abcdef"[byte % 16];
		write(1, &first_char, 1);
		write(1, &second_char, 1);
		if (++i % 2 == 0 && i >= 2 && i != 16)
			write(1, " ", 1);
		str++;
		(*size)--;
	}
	print_spaces(i);
	str -= i;
	(*size) += i;
	print_string(str, size);
}

void	print_string(char *str, unsigned int *size)
{
	int	i;

	i = 0;
	write(1, " ", 1);
	while ((*str != '\0' || *size != 0) && i < 16)
	{
		if (*size == 0)
			break ;
		if (*str < 32 || *str >= 127)
			write(1, ".", 1);
		else
			write(1, str, 1);
		str++;
		i++;
		(*size)--;
	}
	write(1, "\n", 1);
	str -= i;
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int	num_of_phrases;
	int	i;

	num_of_phrases = size / 16;
	if (size % 16 != 0)
		num_of_phrases++;
	i = 0;
	while (i < num_of_phrases)
	{
		print_memory_to_string(addr);
		print_string_to_hexa(addr, 0, &size);
		addr += 16;
		i++;
	}
	addr -= i * 16;
	return (addr);
}
