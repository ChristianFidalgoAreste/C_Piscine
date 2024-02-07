/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:54:09 by arcanava          #+#    #+#             */
/*   Updated: 2023/11/08 15:54:11 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	memory_error(void)
{
	write(STDOUT_FILENO, "Bad err: Memory crashed\n", 24);
	exit(1);
}

void	file_error(void)
{
	write(STDOUT_FILENO, "Err: Couldn't open the file\n", 28);
	exit(1);
}
