/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 12:35:30 by angalsty          #+#    #+#             */
/*   Updated: 2022/05/23 12:45:38 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	if ((count == SIZE_MAX) || (size == SIZE_MAX))
		return (0);
	str = (void *) malloc (count * size);
	if (str == 0)
		return (0);
	else
		ft_bzero(str, count * size);
	return (str);
}

/*int main(void)
{
	char s[] = "hello";
	ft_collac(5, 1);
	printf("%s\n", str);
	return (0);
}*/
