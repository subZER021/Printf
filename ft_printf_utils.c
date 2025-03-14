/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-rio <ddel-rio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:58:39 by delrio            #+#    #+#             */
/*   Updated: 2025/03/12 00:23:51 by ddel-rio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i] != '\0')
		ft_putchar(str[i++]);
	return (i);
}

int	ft_putnbr(int nbr)
{
	int	i;

	i = 0;
	if (nbr == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nbr < 0)
	{
		i += ft_putchar('-');
		nbr = nbr * -1;
	}
	if (nbr > 9)
		i += ft_putnbr(nbr / 10);
	return (i += ft_putchar(nbr % 10 + '0'));
}

int	ft_putunsigned(unsigned int i)
{
	int	j;

	j = 0;
	if (i > 9)
		j += ft_putunsigned(i / 10);
	return (j += ft_putchar(i % 10 + '0'));
}

int	ft_puthex(unsigned long nbr, char c)
{
	int		i;
	char	*str;

	i = 0;
	if (c == 'X')
		str = "0123456789ABCDEF";
	else
		str = "0123456789abcdef";
	if (c == 'p')
	{
		if (!nbr)
			return (write(1, "(nil)", 5));
		i += ft_putstr("0x");
		c = 0;
	}
	if (nbr < 16)
		i += ft_putchar(str[nbr]);
	else
	{
		i += ft_puthex(nbr / 16, c);
		i += ft_puthex(nbr % 16, c);
	}
	return (i);
}
