/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinn <dfinn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:28:17 by dfinn             #+#    #+#             */
/*   Updated: 2022/11/18 12:56:20 by dfinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
#include "libft.h"


int		ft_putstr(char *str);
char	ft_putchar(char c);
int		ft_putadress(void *p);
void	ft_putnbr(int nb);
void	ft_put_hex(unsigned int num, const char format);
int		ft_print_hex(unsigned int num, const char format);
int		ft_num_len(unsigned int num);
char	*ft_itooa(unsigned int n);
int		ft_print_unsigned(int n);
int		ft_format(va_list args, const char format);
int		ft_printf(const char *format, ...);
int		ft_print_percent(void);
int		ft_printstr(char *str);
int		ft_print_nbr(int n);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);



#endif