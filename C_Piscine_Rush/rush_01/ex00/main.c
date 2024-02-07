/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 21:31:28 by arcanava          #+#    #+#             */
/*   Updated: 2023/10/29 21:31:35 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define MIN_PARAMS 16
#define MAX_PARAMS 36

void	print_matrix(int size, char **matrix);
char	**fill_view_matrix(char *str, int size);
char	**fill_matrix(int size);
int		papa(char **matrix, char **view, int i, int j);
int		get_numbers_amount(char *str);
int		arg_acceptable(char *arg, int digits_amount);
int		arg_solvable(char *arg, int size);
int		error(void);

int	main(int args_amount, char **args)
{
	int		size;
	double	division_result;
	int		numbers_amount;
	char	**matrix;

	if (args_amount != 2)
		return (error());
	numbers_amount = get_numbers_amount(args[1]);
	division_result = numbers_amount / 4.00;
	size = (int) division_result;
	if (numbers_amount < MIN_PARAMS
		|| numbers_amount > MAX_PARAMS
		|| division_result != size
		|| !arg_acceptable(args[1], size)
		|| !arg_solvable(args[1], size))
		return (error());
	matrix = fill_matrix(size);
	if (papa(matrix, fill_view_matrix(args[1], size), 0, 0))
		print_matrix(size, matrix);
	else
	{
		print_matrix(size, matrix);
		return (error());
	}
	return (0);
}
