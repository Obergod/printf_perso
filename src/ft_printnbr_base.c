/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 19:30:35 by mafioron          #+#    #+#             */
/*   Updated: 2024/11/17 20:42:48 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long	ft_abs(long n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	a_lenbase(int nb)
{
	int	count;
	long	n;

	n = nb;
	count = 0;
	if (n <= 0)
		count++;
	n = ft_abs(n);
	while (n >= 16)
	{
		count++;
		n /= 16;
	}
	return (count + 1);
}

void	ft_putnbr_base(int nbr, char c)
{
	long		n;
	char		*low_base;
	char		*up_base;

	low_base = "0123456789abcdef";
	up_base = "0123456789ABCDEF";
	n = nbr;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 16)
		ft_putnbr_base(n / 16, c);
	if (c == 'x')
		ft_putchar(low_base[n % 16]);
	if (c == 'X')
		ft_putchar(up_base[n % 16]);
}

int	ft_printnbr_base(int nbr, char c)
{
	int	len;

	len = a_lenbase(nbr);
	ft_putnbr_base(nbr, c);
	return (len);
}
/*
#include <stdio.h>

int	main()
{
	printf("\nlen nb : %d\n", ft_printnbr_base(42, 'X'));
}*/
