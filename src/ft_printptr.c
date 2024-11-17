/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 20:03:00 by mafioron          #+#    #+#             */
/*   Updated: 2024/11/17 20:44:22 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "ft_printf.h"

int	a_lenptr(unsigned long long n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n >= 16)
	{
		count++;
		n /= 16;
	}
	return (count + 1);
}

void	ft_putptr(unsigned long long n)
{
	char		*low_base;

	low_base = "0123456789abcdef";
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 16)
		ft_putptr(n / 16);
	ft_putchar(low_base[n % 16]);
}

int	ft_printptr(unsigned long long n)
{
	int	len;

	len = a_lenptr(n);
	ft_putptr(n);
	return (len);
}
