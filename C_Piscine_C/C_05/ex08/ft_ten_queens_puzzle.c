/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:11:57 by cfidalgo          #+#    #+#             */
/*   Updated: 2023/10/31 18:46:00 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_comb(int *queens)
{
	char	row;
	int		i;

	i = 0;
	while (i <= 9)
	{
		row = queens[i] + '0';
		write(1, &row, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	check_queen(int *queens, int i, int row)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (row == queens[j]
			|| i - j == row - queens[j]
			|| i - j == queens[j] - row)
			return (0);
		j++;
	}
	return (1);
}

void	ft_check_col(int *queens, int i, int row, int *comb_count)
{
	int	can_queen_place;

	while (row <= 9)
	{
		can_queen_place = check_queen(queens, i, row);
		if (can_queen_place)
		{
			queens[i] = row;
			if (i < 9)
				ft_check_col(queens, i + 1, 0, comb_count);
			else
			{
				print_comb(queens);
				*comb_count = *comb_count + 1;
			}
		}
		row++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	queens[10];
	int	comb_count;

	ft_check_col(queens, 0, 0, &comb_count);
	return (comb_count);
}
