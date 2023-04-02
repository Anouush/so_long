/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 19:02:59 by angalsty          #+#    #+#             */
/*   Updated: 2022/05/20 13:02:01 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	e;
	size_t	y;

	i = 0;
	e = 0;
	y = 0;
	while (dst[i])
		i++;
	while (src[e])
		e++;
	while (src[y] && (i + y + 1 < dstsize))
	{
		dst[i + y] = src[y];
		y++;
	}
	dst[i + y] = '\0';
	if (dstsize > i)
		return (i + e);
	else
		return (e + dstsize);
}

/*int main(void)
{
    char    src[] = "anush";
    char    dest[] = "barev";
    int c;

    c = ft_strlcat(dest, src, 4);
    printf("%d\n", c);
    printf("%s\n", dest);
    return (0);
 }*/
