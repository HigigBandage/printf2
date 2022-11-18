/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinn <dfinn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:48:38 by dfinn             #+#    #+#             */
/*   Updated: 2022/11/18 12:25:04 by dfinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb -= nb;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar (nb + 48);
}

int	ft_format(va_list args, const char format)
{
	int	print_lenght;

	print_lenght = 0;
	if (format == 'c')
		print_lenght += ft_putchar(va_arg(args, int));
  	if (format == 's')
		print_lenght = ft_putstr(va_arg(args, char *));
	if (format == 'p')
		print_lenght += ft_putadress(va_arg(args, void *));
	if (format == 'd' || format == 'i')
		print_lenght += ft_print_nbr(va_arg(args, int));
	if (format == 'u')
		print_lenght += ft_print_unsigned(va_arg(args, unsigned int));
	if (format == 'x' || format == 'X')
		print_lenght += ft_print_hex(va_arg(args, unsigned int), format);
	if (format == '%')
		print_lenght += ft_print_percent();
	return (print_lenght);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		print_lenght;
	int		i;

	print_lenght = 0;
	i = 0;
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
			print_lenght += ft_putchar(format[i]);
			i++;
		}
		va_end(args);
	}
	return (print_lenght);
}
