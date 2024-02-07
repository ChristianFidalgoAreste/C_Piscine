/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 21:27:03 by arcanava          #+#    #+#             */
/*   Updated: 2023/11/04 21:27:06 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str);

int	ft_len_no_space_end(char *src)
{
	int	i;

	i = ft_strlen(src) - 1;
	while (i >= 0 && (src[i] == ' '
			|| src[i] == '\v' || src[i] == '\t'
			|| src[i] == '\r' || src [i] == '\f'))
		i--;
	return (i);
}

int	ft_trim(char *src)
{
	int	i;
	int	j;
	int	end;

	i = 0;
	j = 0;
	end = ft_len_no_space_end(src);
	while (src[i] != '\0' && (src[i] == ' '
			|| src[i] == '\v' || src[i] == '\t'
			|| src[i] == '\r' || src [i] == '\f'))
		i++;
	while (i <= end)
	{
		src[j] = src[i];
		j++;
		i++;
	}
	src[j] = '\0';
	return (j);
}
