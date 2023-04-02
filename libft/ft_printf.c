/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:12:13 by angalsty          #+#    #+#             */
/*   Updated: 2023/01/12 13:49:40 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_formats(va_list args, const char format)
{
	int	counter;

	counter = 0;
	if (format == 'c')
		counter += ft_printchar(va_arg(args, int));
	else if (format == 's')
		counter += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		counter += ft_print_ptr(va_arg(args, unsigned long));
	else if (format == 'd' || format == 'i')
		counter += ft_printdec(va_arg(args, int));
	else if (format == 'u')
		counter += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		counter += ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		counter += ft_printpercent();
	return (counter);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		counter;

	i = 0;
	counter = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			counter += ft_formats(args, str[i + 1]);
			i++;
		}
		else
			counter += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (counter);
}
