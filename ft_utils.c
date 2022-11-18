/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinn <dfinn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:37:40 by dfinn             #+#    #+#             */
/*   Updated: 2022/11/18 12:31:21 by dfinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "NULL", 5);
		return (i);
	}
	while (str)
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_put_adress(void *p)
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

int	ft_print_percent(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "NULL", 5);
		return (0);
	}
	while (str[i])
	{
		write(1, &str, 1);
		i++;
	}
	return (i);
}

int	ft_print_nbr(int n)
{
	int		len;
	char	*str;

	len = 0;
	str = ft_itoa(n);
	len = ft_putstr(str);
	free(str);
	return (len);
}
