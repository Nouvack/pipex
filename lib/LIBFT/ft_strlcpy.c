/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsantand <nsantand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:41:30 by nsantand          #+#    #+#             */
/*   Updated: 2024/10/04 15:51:25 by nsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;

	i = 0;
	if (size == 0)
	{
		return (ft_strlen(src));
	}
	while (src[i] != '\0' && i < (unsigned)size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

// #include <stdio.h>
// #include <string.h> 

// int main(void)
// {
//     char destino[10];
//     const char *origen = "Hola, mundo"; 
//     size_t size = sizeof(destino);  
//     size_t resultado = ft_strlcpy(destino, origen, size);

//     printf("Cadena destino después de ft_strlcpy: %s\n", destino);
//     printf("Longitud de la cadena fuente: %zu\n", resultado);

//     return 0;
// }
