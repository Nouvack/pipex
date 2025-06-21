/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsantand <nsantand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:15:14 by nsantand          #+#    #+#             */
/*   Updated: 2024/10/04 15:26:22 by nsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest2;
	unsigned char	*src2;
	size_t			i;

	i = 0;
	dest2 = (unsigned char *)dest;
	src2 = (unsigned char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		dest2[i] = src2[i];
		i++;
	}
	return (dest2);
}

/*
#include <stdio.h>

int main(void)
{
    char src[] = "Hola, mundo!";
    char dest[20];  

    ft_memcpy(dest, src, sizeof(src));
    printf("Contenido de dest: %s\n", dest);
    return 0;
}*/
