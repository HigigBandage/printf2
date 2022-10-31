/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinn <dfinn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:34:14 by dfinn             #+#    #+#             */
/*   Updated: 2022/10/31 18:41:18 by dfinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

int	ft_format(va_list args, const char format)
{
	int	print_lenght;

	print_lenght = 0;
	if (format == 'c')
		print_lenght += ft_putchar(va_arg(args, int));
	if (format == 's')
		print_lenght += ft_putstr(va_arg(args, char *));
	if (format == 'p')
		print_lenght += ft_putadress(va_arg(args, const void *));
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;
	int		print_lenght;

	i = 0;
	print_lenght = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			print_lenght += ft_format(args, format[i + 1]);
			i++;
		}
		else
		{
			print_lenght += ft_putchar(format);
			i++;
		}
		va_ends(args);
		return (print_lenght);
	}
}
