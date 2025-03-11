/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delrio <delrio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:57:53 by delrio            #+#    #+#             */
/*   Updated: 2025/03/11 21:57:55 by delrio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

int	ft_printf(char const *s, ...);
int	ft_putchar(int c);
int	ft_putstr(const char *str);
int	ft_putnbr(int nb);
int	ft_putunsigned(unsigned int a);
int	ft_puthex(unsigned long n, char c);

#endif