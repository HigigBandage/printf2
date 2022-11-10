/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinn <dfinn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:48:38 by dfinn             #+#    #+#             */
/*   Updated: 2022/11/10 16:05:06 by dfinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "NULL", 5);
		return (i);
	}
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putadress(void *p)
{
	unsigned long	adr;
	char const		*base;
	char			res[9];
	int				i;

	adr = (unsigned long) p;
	base = "0123456789abcdef";
	i = 8;
	while ((adr / 16) > 0 || i >= 8)
	{
		res[i] = base[(adr % 16)];
		adr /= 16;
		i--;
	}
	res[i] = base[(adr % 16)];
	ft_putchar ('0');
	ft_putchar ('x');
	while (i < 9)
	{
		ft_putchar (res[i]);
		i++;
	}
	write(1, "\n", 1);
	return (1);
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
			print_lenght += ft_format(args, format[i+ 1]);
			i++;
		}
		else 
		{
			print_lenght += ft_putchar(format[i]);
			i++;
		}
		va_end(args);
		return (print_lenght);
	}
}

int	main(int ac, char **av)
{
  char *str;

  str = "8434&^*&)(";
  printf("%p\n", str);
  ft_printf("%p", str);
}