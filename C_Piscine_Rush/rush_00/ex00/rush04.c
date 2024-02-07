/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:50:31 by cfidalgo          #+#    #+#             */
/*   Updated: 2023/10/22 12:07:42 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	print_row(char first_char, char second_char, char third_char, int x)
{
	int	col_index;

	col_index = 0;
	ft_putchar(first_char);
	while (col_index < x - 2)
	{
		ft_putchar(second_char);
		col_index++;
	}
	if (x != 1)
		ft_putchar(third_char);
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	row_index;

	if (x <= 0 || y <= 0)
	{
		write(1, "El numero de columnas o filas es incorrecto\n", 44);
		return ;
	}
	row_index = 0;
	while (row_index < y)
	{
		if (row_index == 0)
			print_row('A', 'B', 'C', x);
		else if (row_index == y - 1)
			print_row('C', 'B', 'A', x);
		else
			print_row('B', ' ', 'B', x);
		row_index++;
	}
}
