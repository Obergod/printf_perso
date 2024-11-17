/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:48:02 by mafioron          #+#    #+#             */
/*   Updated: 2024/11/17 20:46:30 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	unsigned_len(unsigned int n)
{
	int	count;

	count = 0;
	if (n <= 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

void	ft_putunsigned(unsigned int n)
{
	int	len;

	if (n >= 0 && n <= 9)
		ft_putchar(n + '0');
	if (n > 9)
	{
		ft_putunsigned(n / 10);
		ft_putunsigned(n % 10);
	}
}

int	ft_printunsigned(unsigned int n)
{
	int	len;

	len = unsigned_len(n);
	ft_putunsigned(n);
	return (len);
}
