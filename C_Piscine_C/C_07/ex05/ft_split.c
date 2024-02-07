/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:36:45 by cfidalgo          #+#    #+#             */
/*   Updated: 2023/11/02 15:26:13 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_sep(char str_char, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
		if (charset[i++] == str_char)
			return (1);
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	is_char_sep;
	int	start_counting;
	int	count;

	i = 0;
	start_counting = 1;
	count = 0;
	while (str[i] != '\0')
	{
		is_char_sep = check_sep(str[i], charset);
		if (start_counting && !is_char_sep)
		{
			start_counting = 0;
			count++;
		}
		else if (is_char_sep)
			start_counting = 1;
		i++;
	}
	return (count);
}

char	*ft_strdup(char *str, int start, int finish)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc((finish - start + 1) * sizeof(char));
	if (!dest)
		return (0);
	while (start < finish)
		dest[i++] = str[start++];
	if (str[start + 1] == '\0')
		dest[i++] = str[start];
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		match;
	char	**dest;

	i = 0;
	j = 0;
	match = -1;
	dest = malloc((count_words(str, charset) + 1) * sizeof(char *));
	if (!dest)
		return (0);
	while (str[i] != '\0')
	{
		if (!check_sep(str[i], charset) && match < 0)
			match = i;
		else if ((check_sep(str[i], charset) || str[i + 1] == '\0')
			&& match >= 0)
		{
			dest[j++] = ft_strdup(str, match, i);
			match = -1;
		}
		i++;
	}
	dest[j] = 0;
	return (dest);
}
