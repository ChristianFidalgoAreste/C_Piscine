/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decomp_arg_in_keys.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 16:01:18 by cfidalgo          #+#    #+#             */
/*   Updated: 2023/11/05 20:19:53 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	print_number_str(char *str);
int	decomp_arg(long n, long *k_arr, char **v_arr);
int	decomp_thousands(long n, long *k_arr, char **v_arr, long thousand);
int	decomp_millions(long n, long *k_arr, char **v_arr, long million);
int	decomp_billions(long n, long *k_arr, char **v_arr, long billion);

int	print(char *str)
{
	return (print_number_str(str));
}

int	search(long *key_array, long value)
{
	int	i;

	i = 0;
	while (value != key_array[i])
		i++;
	return (i);
}

int	decomp_hundreds(long n, long *k_arr, char **v_arr)
{
	int	print_res;

	decomp_arg(n / 100, k_arr, v_arr);
	write(1, " ", 1);
	print_res = print(v_arr[search(k_arr, 100)]);
	if (n % 100 == 0)
		return (print_res);
	write(1, " ", 1);
	return (decomp_arg(n % 100, k_arr, v_arr));
}

int	decomp_tens(long n, long *k_arr, char **v_arr)
{
	if (n % 10 == 0)
		return (print(v_arr[search(k_arr, n)]));
	decomp_arg(n - (n % 10), k_arr, v_arr);
	write(1, " ", 1);
	return (decomp_arg(n % 10, k_arr, v_arr));
}

int	decomp_arg(long n, long *k_arr, char **v_arr)
{
	if (n <= 20)
		return (print(v_arr[search(k_arr, n)]));
	else if (n / 100 == 0)
		return (decomp_tens(n, k_arr, v_arr));
	else if (n / 1000 == 0)
		return (decomp_hundreds(n, k_arr, v_arr));
	else if (n / 1000000 == 0)
		return (decomp_thousands(n, k_arr, v_arr, 1000));
	else if (n / 1000000000 == 0)
		return (decomp_millions(n, k_arr, v_arr, 1000000));
	else
		return (decomp_billions(n, k_arr, v_arr, 1000000000));
}
