/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoaik <akoaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 19:19:51 by akoaik            #+#    #+#             */
/*   Updated: 2025/06/02 16:25:01 by akoaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex(unsigned long n)
{
	char	*hex;
	int		count;

	count = 0;
	hex = "0123456789abcdef";
	if (n >= 16)
		count += ft_putnbr_hex(n / 16);
	count += ft_putchar(hex[n % 16]);
	return (count);
}

int	ft_putnbr_hex_lowercase(unsigned int n)
{
	char	*base ;
	int		count;

	count = 0;
	base = "0123456789abcdef";
	if (n >= 16)
		count += ft_putnbr_hex_lowercase(n / 16);
	count += ft_putchar(base[n % 16]);
	return (count);
}

int	ft_putnbr_hex_uppercase(unsigned int n)
{
	char	*base ;
	int		count;

	count = 0;
	base = "0123456789ABCDEF";
	if (n >= 16)
		count += ft_putnbr_hex_uppercase(n / 16);
	count += ft_putchar(base[n % 16]);
	return (count);
}
