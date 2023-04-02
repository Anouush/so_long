/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:17:57 by angalsty          #+#    #+#             */
/*   Updated: 2022/05/13 12:07:44 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*dst;
	long int	nb;

	len = ft_len(n);
	nb = n;
	dst = (char *) malloc (sizeof(char) * len + 1);
	if (dst == NULL)
		return (NULL);
	dst[len] = '\0';
	if (nb < 0)
	{
		dst[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		dst[0] = '0';
	while (nb)
	{
		len--;
		dst[len] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (dst);
}
