/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsantand <nsantand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:10:48 by nsantand          #+#    #+#             */
/*   Updated: 2025/02/26 11:10:48 by nsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isneg(int n);
static char	*put_digits(char *str, unsigned int i, unsigned int j);
static int	countdig(int i, int j);

char	*ft_itoa(int n)
{
	unsigned int	i;
	unsigned int	j;
	char			*str;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	j = isneg(n);
	if (n < 0)
		i++;
	if (n == 0)
		i = 1;
	i = countdig(i, j);
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	put_digits(str, i, j);
	if (n < 0)
		str[0] = '-';
	str[i] = '\0';
	return (str);
}

static int	isneg(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static char	*put_digits(char *str, unsigned int i, unsigned int j)
{
	while (i != 0)
	{
		str[i - 1] = ('0' + (j % 10));
		j = j / 10;
		i--;
	}
	return (str);
}

static int	countdig(int i, int j)
{
	while (j != 0)
	{
		j = j / 10;
		i++;
	}
	return (i);
}

/*
#include <stdio.h>


int	main(void)
{
	int     str1;
	char    *str_num;

	str1 = 42;
	printf("Número: %d\n", str1);
	str_num = ft_itoa(str1);
	printf("String: %s\n", str_num);
	return (0);
}*/
