/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:11:29 by angalsty          #+#    #+#             */
/*   Updated: 2023/01/12 14:42:16 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	dst = (char *) malloc (sizeof(char) * len);
	if (!dst)
		return (NULL);
	while (s1[i])
	{
		dst[j++] = s1[i++];
	}
	i = 0;
	while (s2[i])
	{
		dst[j++] = s2[i++];
	}
	dst[j] = '\0';
	return (dst);
}

/*int	main(void)
{
	char str1[] = "Hello";
	char str2[] = "Anoush";
	printf("%s\n", ft_strjoin(str1, str2));
	return (0);
}*/
