/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsantand <nsantand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:40:07 by nsantand          #+#    #+#             */
/*   Updated: 2024/10/04 15:26:12 by nsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*s2;
	size_t			i;

	s2 = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		s2[i] = 0;
		i++;
	}
}

/*
#include <stdio.h>

int main(void)
{
    char str1[]= "42"; 
    printf("String : '%s'\n", str1);
    ft_bzero(str1, 1);
    printf("String después: '%s'\n", str1); 
    return 0;
}*/
