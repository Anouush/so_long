/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:24:52 by angalsty          #+#    #+#             */
/*   Updated: 2022/05/03 19:46:41 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*dst;

	len = ft_strlen(s1) + 1;
	dst = (char *) malloc (sizeof (*s1) * len);
	if (!dst)
		return (0);
	dst = ft_memcpy (dst, s1, len);
	return (dst);
}

/*int	main(void)
{	
	char *s = ft_strdup((char *) "hello");
	printf("%s\n", s);
	return (0);
}*/
