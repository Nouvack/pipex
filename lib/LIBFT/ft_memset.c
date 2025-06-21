/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsantand <nsantand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:14:17 by nsantand          #+#    #+#             */
/*   Updated: 2024/10/04 15:38:27 by nsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*s2;
	size_t			i;

	s2 = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		s2[i] = c;
		i++;
	}
	return (s2);
}

/*
#include <stdio.h>
#include "libft.h"

int main(void)
{
    char buffer[20];

    ft_memset(buffer, 'A', 10);
    buffer[10] = '\0'; 
    printf("Resultado de ft_memset con 'A': %s\n", buffer);
    return 0;
}*/
