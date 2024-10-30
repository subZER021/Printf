/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 04:52:03 by marvin            #+#    #+#             */
/*   Updated: 2024/10/30 04:52:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int		len;
	char	num;

	len = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		len += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		len += ft_putnbr(n / 10);
	num = n % 10 + '0';
	len += ft_putchar(num);
	return (len);
}

int	ft_putunbr(unsigned int n)
{
	int		len;
	char	num;

	len = 0;
	if (n >= 10)
		len += ft_putunbr(n / 10);
	num = n % 10 + '0';
	len += ft_putchar(num);
	return (len);
}