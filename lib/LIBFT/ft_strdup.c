/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsantand <nsantand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 18:12:44 by nsantand          #+#    #+#             */
/*   Updated: 2024/10/11 17:51:51 by nsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	len;
	char	*str;

	len = ft_strlen(s);
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

// #include <stdio.h>
// #include <stdlib.h>
// int main(void)
// {
//     const char *cadena_original = "Hola, mundo!"
//     char *copia = ft_strdup(cadena_original);
//   	printf("Cadena original: %s\n", cadena_original);
//     printf("Copia duplicada: %s\n", copia);
// 	free(copia)
//     return 0;
// }
