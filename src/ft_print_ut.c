/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ut.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:41:20 by mafioron          #+#    #+#             */
/*   Updated: 2024/11/17 20:45:03 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(char c)
{
	write (1, &c, 1);
	return (1);
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	ft_printstr(char *s)
{
	int	i;

	i = 0;
	while (*s)
	{
		ft_putchar(*s++);
		i++;
	}
	return (i);
}
