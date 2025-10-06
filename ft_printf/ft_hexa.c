/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoaik <akoaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 22:07:24 by akoaik            #+#    #+#             */
/*   Updated: 2025/06/03 00:26:57 by akoaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa(char spec, va_list lst)
{
	unsigned int	ui;

	if (spec == 'x')
	{
		ui = va_arg(lst, unsigned int);
		return (ft_putnbr_hex_lowercase(ui));
	}
	else if (spec == 'X')
	{
		ui = va_arg(lst, unsigned int);
		return (ft_putnbr_hex_uppercase(ui));
	}
	return (0);
}
