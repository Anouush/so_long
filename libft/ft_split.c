/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:25:05 by angalsty          #+#    #+#             */
/*   Updated: 2022/05/16 13:27:39 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_divcounter(char const *s, char c)
{
	size_t	i;
	size_t	counter;

	counter = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (i > 0 && s[i] && s[i - 1] == c)
			counter++;
		if (s[i])
			i++;
	}
	if (counter == 0 && s[i - 1] == c)
		return (0);
	if (s[0] != c)
		counter++;
	return (counter);
}

char	*ft_word_dup(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 1) * sizeof (char));
	while (start < end)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		counter;
	char	**strs;
	size_t	i;
	size_t	j;

	if (s)
		strs = malloc((ft_divcounter(s, c) + 1) * sizeof (char *));
	if (!s || !strs)
		return (0);
	i = 0;
	j = 0;
	counter = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && counter < 0)
			counter = i;
		else if ((s[i] == c || i == ft_strlen(s)) && counter >= 0)
		{
			strs[j++] = ft_word_dup(s, counter, i);
			counter = -1;
		}
		i++;
	}
	strs[j] = 0;
	return (strs);
}
