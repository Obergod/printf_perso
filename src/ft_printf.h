/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 19:33:29 by mafioron          #+#    #+#             */
/*   Updated: 2024/11/17 20:46:53 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <unistd.h>


int	ft_printf(const char *str, ...);
int	ft_printnbr_base(int nbr, char c);
int	ft_printchar(char c);
void	ft_putchar(char c);
int	ft_printstr(char *s);
int	ft_printnbs(int nb);
int	ft_printunsigned(unsigned int n);
int	ft_printptr(unsigned long long n);


#endif
