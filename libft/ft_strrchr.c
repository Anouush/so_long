/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 10:41:23 by angalsty          #+#    #+#             */
/*   Updated: 2022/05/20 18:17:19 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char) c)
		{
			return ((char *)s + i);
		}
		i--;
	}
	return (0);
}

/*int   main(void)
{
    char str[]= "hello";
    printf ("%s\n", ft_strrchr(str, 'l'));
    return (0);

}*/
