/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:13:47 by angalsty          #+#    #+#             */
/*   Updated: 2023/01/12 13:48:48 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_digit_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len ++;
		num = num / 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*digit;
	int		len;

	len = ft_digit_len(n);
	digit = (char *) malloc(sizeof(char ) * (len + 1));
	if (!digit)
		return (0);
	digit[len] = '\0';
	while (n != 0)
	{
		digit[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (digit);
}

int	ft_print_unsigned(unsigned int n)
{
	int		i;
	char	*str;

	i = 0;
	if (n == 0)
		i += write(1, "0", 1);
	else
	{
		str = ft_uitoa(n);
		i += ft_printstr(str);
		free(str);
	}
	return (i);
}
