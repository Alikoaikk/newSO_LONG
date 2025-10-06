/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoaik <akoaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 18:33:34 by akoaik            #+#    #+#             */
/*   Updated: 2025/06/02 16:07:37 by akoaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr >= 10)
		count += ft_putnbr_unsigned(nbr / 10);
	count += ft_putchar((nbr % 10) + '0');
	return (count);
}
