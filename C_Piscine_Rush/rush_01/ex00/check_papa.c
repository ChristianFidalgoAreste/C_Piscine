/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_papa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 21:18:15 by arcanava          #+#    #+#             */
/*   Updated: 2023/10/29 21:18:21 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	print_matrix(int size, char **matrix);
int		get_vws(int ibase, int iaug, char *str);
int		check_sudoku(char **matrix);

int	is_zeros(char **matrix, int i, int j, int size)
{
	int	k;
	int	l;

	k = 0;
	l = 0;
	while (k < size)
	{
		if (matrix[i][k] == '0')
			return (1);
		k++;
	}
	while (l < size)
	{
		if (matrix[l][j] == '0')
			return (1);
		l++;
	}
	return (0);
}

int	check_rows_view(char **matrix, char **view, int i, int j)
{
	char	str[9];
	int		k;
	int		k_rev;
	int		size;

	k = -1;
	while (matrix[i][++k] != '\0')
		str[k] = matrix[i][k];
	size = k;
	if (is_zeros(matrix, i, j, size)
		&& get_vws(0, 1, str) > view[2][i])
		return (0);
	else if (!is_zeros(matrix, i, j, size) && get_vws(0, 1, str) != view[2][i])
		return (0);
	k = 0;
	k_rev = size - 1;
	while (k_rev >= 0)
		str[k] = matrix[i][k_rev--];
	if (is_zeros(matrix, i, j, size) && get_vws(0, 1, str) > view[3][i])
		return (0);
	else if (!is_zeros(matrix, i, j, size) && get_vws(0, 1, str) != view[3][i])
		return (0);
	return (1);
}

int	check_cols_view(char **matrix, char **view, int i, int j)
{
	char	str[9];
	int		k;
	int		k_rev;
	int		size;

	size = 0;
	while (matrix[i][size] != '\0')
		size++;
	k = -1;
	k_rev = size - 1;
	while (++k < size)
		str[k] = matrix[k][j];
	if (is_zeros(matrix, i, j, size) && get_vws(0, 1, str) > view[0][j])
		return (0);
	else if (!is_zeros(matrix, i, j, size) && get_vws(0, 1, str) != view[0][j])
		return (0);
	k = 0;
	while (k_rev >= 0)
		str[k] = matrix[k_rev--][j];
	if (is_zeros(matrix, i, j, size) && get_vws(0, 1, str) > view[1][j])
		return (0);
	else if (!is_zeros(matrix, i, j, size) && get_vws(0, 1, str) != view[1][j])
		return (0);
	return (1);
}

int	check_view(char **matrix, char **view, int i, int j)
{
	int	crows;
	int	ccols;

	crows = check_rows_view(matrix, view, i, j);
	ccols = check_cols_view(matrix, view, i, j);
	return (crows && ccols);
}

int	check_papa(char **matrix, char **view, int i, int j)
{
	int	cview;
	int	csudoku;

	cview = check_view(matrix, view, i, j);
	csudoku = check_sudoku(matrix);
	return (cview && csudoku);
}
