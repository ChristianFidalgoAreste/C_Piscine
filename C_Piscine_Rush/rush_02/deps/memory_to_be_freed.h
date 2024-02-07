/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_to_be_freed.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 16:14:49 by arcanava          #+#    #+#             */
/*   Updated: 2023/11/05 16:14:56 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_memory_to_be_freed
{
	long	*key_array;
	int		*lengths_tab;
	char	**value_array;
	char	**lines_tab;
	long	size;
};