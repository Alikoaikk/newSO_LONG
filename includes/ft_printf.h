/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoaik <akoaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 15:38:11 by akoaik            #+#    #+#             */
/*   Updated: 2025/08/27 12:42:55 by akoaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *string, ...);
int	ft_putchar(char s);
int	ft_putnbr(int n);
int	ft_putnbr_unsigned(unsigned int nbr);
int	ft_putnbr_hex(unsigned long n);
int	ft_putstr(char *s);
int	ft_print_pointer(void *ptr);
int	ft_putnbr_hex_lowercase(unsigned int n);
int	ft_putnbr_hex_uppercase(unsigned int n);
int	ft_hexa(char spec, va_list lst);

#endif