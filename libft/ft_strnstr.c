/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:01:53 by angalsty          #+#    #+#             */
/*   Updated: 2022/04/27 16:52:02 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	c;

	i = 0;
	if (needle[i] == 0)
		return ((char *) haystack);
	while (i < len && haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			c = 0;
			while (needle[c] && haystack[i + c] && i + c < len
				&& needle[c] == haystack[i + c])
				c++;
			if (needle[c] == '\0')
				return ((char *)haystack + i);
		}	
		i++;
	}
	return (0);
}

/*int	main(void)
{
	char str1[] = "Foo Bar Baz";
	char str2[] = "Bar";
	printf("%s\n", ft_strnstr(str1, str2, 8));
	return (0);
}*/
