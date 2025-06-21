/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsantand <nsantand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:38:26 by nsantand          #+#    #+#             */
/*   Updated: 2024/10/05 12:07:12 by nsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	aux(unsigned char *dest, unsigned char *src, size_t n)
{
	size_t	i;

	if (src < dest)
	{
		i = n;
		while (i > 0)
		{
			dest[i - 1] = src[i - 1];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			dest[i] = src[i];
			i++;
		}
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest2;
	unsigned char	*src2;

	dest2 = (unsigned char *)dest;
	src2 = (unsigned char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (src2 < dest2)
		aux(dest2, src2, n);
	else
		aux(dest2, src2, n);
	return (dest2);
}

/*
#include <stdio.h>
#include "libft.h"

int main(void)
{
    char src[] = "Hola, mundo!";
    char dest[20];

    ft_memmove(dest, NULL, 5);
    dest[5] = '\0';
    printf("Resultado de ft_memmove: %s\n", dest);
    ft_memmove(src + 5, src, 5);
    printf("Resultado con solapamiento: %s\n", src);
    return 0;
}
*/