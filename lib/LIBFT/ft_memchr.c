/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsantand <nsantand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 20:10:03 by nsantand          #+#    #+#             */
/*   Updated: 2024/10/05 12:21:15 by nsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*src;

	i = 0;
	src = (unsigned char *)s;
	while (i < n)
	{
		if (src[i] == (unsigned char)c)
		{
			return ((void *)&src[i]);
		}
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include "libft.h"

int main(void)
{
    char data[] = {65, 66, 67, 68, 69, 70};  
    unsigned char *result = (unsigned char*)ft_memchr(data, 66, 3);
	printf("Encontrado el valor %p", result);
    return 0;
}

*/