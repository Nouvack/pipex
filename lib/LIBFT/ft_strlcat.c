/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsantand <nsantand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:48:55 by nsantand          #+#    #+#             */
/*   Updated: 2024/10/04 15:29:09 by nsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	size_t			sum;

	i = 0;
	j = 0;
	sum = ft_strlen(dst) + ft_strlen(src);
	if (size == 0)
		return (ft_strlen(src));
	while (dst[i] != '\0')
		i++;
	if (size <= ft_strlen(dst))
		return (size + ft_strlen(src));
	while (src[j] != '\0' && i + j < (unsigned)size - 1)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (sum);
}

// #include <stdio.h>
// #include <string.h> 

// size_t ft_strlcat(char *dst, const char *src, size_t size);  
// int main(void)
// {
//     char destino[20] = "Hola";  
//     const char *origen = " Mundo";  
//     size_t size = sizeof(destino);  

//     size_t resultado = ft_strlcat(destino, origen, size);

//     printf("Cadena destino después de ft_strlcat: %s\n", destino);
//     printf("Tamaño total requerido para concatenar: %zu\n", resultado);
// 	return 0;
// }
