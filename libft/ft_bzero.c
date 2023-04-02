/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:56:46 by angalsty          #+#    #+#             */
/*   Updated: 2022/05/03 17:50:29 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
}

/*int   main(void)
{
    char str[] = "helloworld";
    puts(str);
	
	ft_bzero(str, 7);
	
	//puts(str);
	printf("%s\n", str);
	//write(1,str, 9);

	return (0);
}*/
