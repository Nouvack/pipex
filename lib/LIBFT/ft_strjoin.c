/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsantand <nsantand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:01:57 by nsantand          #+#    #+#             */
/*   Updated: 2024/10/11 18:13:52 by nsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	str = malloc(i + j + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, i + 1);
	ft_strlcat(str, s2, i + j + 1);
	return (str);
}

// #include <stdio.h>
// #include <stdlib.h>
// int main(void)
// {
//     const char *cadena1 = "Hola, ";
//     const char *cadena2 = "mundo!";
//     char *resultado = ft_strjoin(cadena1, cadena2);
// 	printf("Resultado de la concatenación: %s\n", resultado);
// 	free(resultado);
//     return 0;
// }