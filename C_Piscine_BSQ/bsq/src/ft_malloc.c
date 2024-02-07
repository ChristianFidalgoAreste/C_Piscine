/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:53:58 by arcanava          #+#    #+#             */
/*   Updated: 2023/11/08 15:54:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	memory_error(void);

void	*ft_malloc(unsigned long size)
{
	void	*new_var;

	new_var = malloc(size);
	if (!new_var)
		memory_error();
	return (new_var);
}
