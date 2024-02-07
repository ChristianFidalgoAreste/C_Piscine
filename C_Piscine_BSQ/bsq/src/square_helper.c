/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:55:20 by arcanava          #+#    #+#             */
/*   Updated: 2023/11/08 15:55:22 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/square.h"

void	set_square(t_square *square, int size, int i, int j)
{
	square->size = size;
	square->i = i;
	square->j = j;
}
