/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 13:54:33 by angalsty          #+#    #+#             */
/*   Updated: 2023/01/12 14:50:01 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* er */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;

	if (s == 0)
		return (0);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (ft_strlen(&s[start]) < len)
		len = (ft_strlen(&s[start]));
	dst = (char *) malloc (sizeof(char) * (len + 1));
	if (dst == 0)
		return (0);
	ft_strlcpy(dst, (s + start), (len + 1));
	return (dst);
}

/*int main(void)
{
	char str[] = "hello";

	printf("%s\n", ft_substr(str, 2, 3));
	return(0);
}*/
