/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:46:14 by mafioron          #+#    #+#             */
/*   Updated: 2024/11/17 20:43:22 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long	ft_abs(long n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	a_len(int nb)
{
	int	count;
	long	n;

	n = nb;
	count = 0;
	if (n <= 0)
		count++;
	n = ft_abs(n);
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

void	ft_putnbr(int nb)
{
	long	n;
	int	len;


	n = nb;
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n >= 0 && n <= 9)
		ft_putchar(n + '0');
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

int	ft_printnbs(int nb)
{
	int	len;

	len = a_len(nb);
	ft_putnbr(nb);
	return (len);
}
