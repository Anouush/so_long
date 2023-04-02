/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:07:29 by angalsty          #+#    #+#             */
/*   Updated: 2022/05/10 13:48:46 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_start(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len && !(ft_strchr(set, s1[i]) == 0))
		i++;
	return (i);
}

static int	ft_end(char const *s1, char const *set)
{
	size_t	len;

	len = ft_strlen(s1);
	while (len > 0 && !(ft_strchr(set, s1[len - 1]) == 0))
		len--;
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dst;
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = ft_start(s1, set);
	end = ft_end(s1, set);
	if (start >= end)
		return (ft_strdup(""));
	dst = (char *) malloc (sizeof(char) * (end - start + 1));
	if (dst == 0)
		return (0);
	ft_strlcpy (dst, s1 + start, end - start +1);
	return (dst);
}
