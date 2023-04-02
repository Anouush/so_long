/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 14:32:41 by angalsty          #+#    #+#             */
/*   Updated: 2022/05/20 12:27:59 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	cont;
	size_t	i;

	i = 0;
	cont = 0;
	while (src[cont])
		cont = ft_strlen(src);
	if (dstsize != 0)
	{
		while (src[i] && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (cont);
}	

/*int	main(void)
{
	char src[] = "hola";
	char dst[] = "hello";
	unsigned int cont;

	cont = ft_strlcpy(dst, src, 3);
	printf("%s\n", src);
	printf("%s\n", dst);
	printf("%d\n", cont);
	return ('O');	
}*/
