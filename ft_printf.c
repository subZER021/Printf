/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-rio <ddel-rio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:56:55 by delrio            #+#    #+#             */
/*   Updated: 2025/03/12 00:21:14 by ddel-rio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_format(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putunsigned(va_arg(args, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_puthex(va_arg(args, unsigned int), c));
	else if (c == 'p')
		return (ft_puthex(va_arg(args, unsigned long int), c));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;
	int		ret;

	ret = 0;
	i = -1;
	va_start(args, format);
	while (format[++i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			ret += ft_check_format(format[++i], args);
		}
		else if (format[i] != '%')
		{
			ft_putchar(format[i]);
			ret++;
		}
	}
	va_end(args);
	return (ret);
}
