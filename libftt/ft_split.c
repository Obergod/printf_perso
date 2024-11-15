/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:52:04 by mafioron          #+#    #+#             */
/*   Updated: 2024/11/14 19:18:38 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			return (count);
		while (*s && *s != c)
			s++;
		count++;
	}
	return (count);
}

static int	count_char(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static char	**res_split(char **res, char const *s, char c, int x)
{
	int	i;
	int	j;

	i = 0;
	while (s[x])
	{
		j = 0;
		while (s[x] == c)
			x++;
		if (s[x])
		{
			res[i] = malloc(sizeof(char) * count_char(s + x, c) + 1);
			if (!res[i])
			{
				free(res);
				return (NULL);
			}
			while (s[x] != c && s[x])
				res[i][j++] = s[x++];
			res[i][j] = '\0';
		}
		i++;
	}
	res[i] = 0;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		x;

	x = 0;
	res = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!res)
		return (NULL);
	res = res_split(res, s, c, x);
	if (!res)
		return (NULL);
	return (res);
}
/*
int	main()
{
	int	i;
	char *s = "      split       this for   me  !       ";
 
	char **res = ft_split(s, ' ');
	i = 0;
	while (res[i])
	{
		printf("%s\n", res[i]);
		i++;
	}
	free(res);
}*/
