/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:29:25 by mafioron          #+#    #+#             */
/*   Updated: 2024/11/15 21:09:05 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

int	ft_printf(const char *str, ...)
{
	va_list	vl;
	char	*s;

	s = (char *)str;
	va_start(vl, str);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (*s == 'c'')
			{
				char c = va_arg(vl, int);
				write (1, &c, 1);
			}
			else if (*s == 's')
				ft_putstr(va_arg(vl, char *));
			else if (*s == 'd' || *s == 'i')
				ft_putnbr(va_arg(vl, int));
			else if (*s == 'u')
				ft_putusignednbr(va_arg(vl, unsigned int));
			else if (*s == 'x')
				ft_putnbrbase_lower(va_arg(vl, int));
			else if (*s == 'X')
				ft_putnbrbase_upper(va_arg(vl, int));
			else if (*s == '%')
				write(1, "%", 1);
		}
		else
			write(1, &*s++, 1);
	}
	va_end(vl);
}
