/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decompose_arg_in_keys2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:04:29 by cfidalgo          #+#    #+#             */
/*   Updated: 2023/11/05 20:10:35 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	decomp_arg(long n, long *k_arr, char **v_arr);
int	print(char *str);
int	search(long *key_array, long value);

int	decomp_billions(long n, long *k_arr, char **v_arr, long billion)
{
	int	print_res;

	decomp_arg(n / billion, k_arr, v_arr);
	write(1, " ", 1);
	print_res = print(v_arr[search(k_arr, billion)]);
	if (n % billion == 0)
		return (print_res);
	write(1, " ", 1);
	return (decomp_arg(n % billion, k_arr, v_arr));
}

int	decomp_millions(long n, long *k_arr, char **v_arr, long million)
{
	int	print_res;

	decomp_arg(n / million, k_arr, v_arr);
	write(1, " ", 1);
	print_res = print(v_arr[search(k_arr, million)]);
	if (n % million == 0)
		return (print_res);
	write(1, " ", 1);
	return (decomp_arg(n % million, k_arr, v_arr));
}

int	decomp_thousands(long n, long *k_arr, char **v_arr, long thousand)
{
	int	print_res;

	decomp_arg(n / thousand, k_arr, v_arr);
	write(1, " ", 1);
	print_res = print(v_arr[search(k_arr, thousand)]);
	if (n % thousand == 0)
		return (print_res);
	write(1, " ", 1);
	return (decomp_arg(n % thousand, k_arr, v_arr));
}
