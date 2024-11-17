/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:29:25 by mafioron          #+#    #+#             */
/*   Updated: 2024/11/17 20:49:26 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int	print_cases(va_list vl, char c)
{
	int	put_len;

	put_len = 0;
	if (c == 'c')
		put_len += ft_printchar(va_arg(vl, int));
	else if (c == 's')
		put_len += ft_printstr(va_arg(vl, char *));
	else if (c == 'p')
		put_len += ft_printptr(va_arg(vl, unsigned long long));
	else if (c == 'd' || c == 'i')
		put_len = ft_printnbs(va_arg(vl, int));
	else if (c == 'u')
		put_len = ft_printunsigned(va_arg(vl, unsigned int));
	else if (c == 'x' || c == 'X')
		put_len = ft_printnbr_base(va_arg(vl, int), c);
	else if (c == '%')
		put_len += ft_printchar('%');
	return (put_len);
}

int	ft_printf(const char *str, ...)
{
	va_list	vl;
	char	*s;
	int	put_len;

	put_len = 0;
	s = (char *)str;
	va_start(vl, str);
	while (*s)
	{
		if (*s == '%')
			put_len += print_cases(vl, *s);
		else
			put_len += ft_printchar(*s);
	}
	va_end(vl);
	return (put_len);
}

#include <stdio.h>

int	main()
{
	int	res = 5;
	ft_printf("test %d\n", res);
	printf("test %d\n", res);
}
