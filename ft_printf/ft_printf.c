/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoaik <akoaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 22:49:17 by akoaik            #+#    #+#             */
/*   Updated: 2025/06/03 20:25:35 by akoaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_basic(char spec, va_list lst)
{
	if (spec == 'd' || spec == 'i')
	{
		return (ft_putnbr(va_arg(lst, int)));
	}
	else if (spec == 'u')
	{
		return (ft_putnbr_unsigned(va_arg(lst, unsigned int)));
	}
	else if (spec == 'c')
	{
		return (ft_putchar((char)va_arg(lst, int)));
	}
	else if (spec == '%')
	{
		return (ft_putchar('%'));
	}
	return (0);
}

static int	ft_string(char spec, va_list lst)
{
	void	*ptr;

	if (spec == 's')
	{
		return (ft_putstr(va_arg(lst, char *)));
	}
	else if (spec == 'p')
	{
		ptr = va_arg(lst, void *);
		return (ft_print_pointer(ptr));
	}
	return (0);
}

static int	ft_handle_spec(const char *str, int i, va_list lst)
{
	char	spec;
	int		result;

	if (str[i + 1] == '\0')
		return (ft_putchar('%'));
	spec = str[i + 1];
	result = ft_basic(spec, lst);
	if (result > 0)
		return (result);
	result = ft_hexa(spec, lst);
	if (result > 0)
		return (result);
	result = ft_string(spec, lst);
	if (result > 0)
		return (result);
	return (result);
}

static int	ft_process_percent(const char *string, int *i, va_list lst_param)
{
	if (string[*i + 1] == '\0')
	{
		(*i)++;
		return (ft_putchar('%'));
	}
	else
	{
		*i += 2;
		return (ft_handle_spec(string, *i - 2, lst_param));
	}
}

int	ft_printf(const char *string, ...)
{
	va_list	lst_param;
	int		i;
	int		count;

	if (!string)
		return (-1);
	va_start(lst_param, string);
	i = 0;
	count = 0;
	while (string[i] != '\0')
	{
		if (string[i] == '%')
			count += ft_process_percent(string, &i, lst_param);
		else
			count += ft_putchar(string[i++]);
	}
	va_end(lst_param);
	return (count);
}

// int main ()
// {
// 	int i = -2147483647;
// 	unsigned int b = 177 ;
// 	char c = 'a';
// 	char *s = NULL ;
// 	void *p = NULL;
// 	int count,count2 ;
// 	int *ptr ;

// 	count = ft_printf("%d \t %x \t %X \t %c \t %s \t %p \t %p\n"
// ,i, b, b, c, s, p, ptr);
// 	count2 = printf("%d \t %x \t %X \t %c \t %s \t %p \t %p\n"
// ,i, b, b, c, s, p, ptr);

// 	ft_printf("count = %d\n",count);
// 	ft_printf("count2 = %d\n",count);
// 	ft_printf("\n");
// 	ft_printf("count = %d\n",ft_printf("123456 "));
// 	ft_printf(" %s ","");
// 	// printf("%s\n","");
//  	// ft_printf("%s","");
// }

// #include <stdio.h>
// int main ()
// {
// 	// printf(" %p ", -1);
// 	ft_printf(" %p ", -1);
// }
