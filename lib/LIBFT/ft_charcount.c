/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsantand <nsantand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:11:50 by nsantand          #+#    #+#             */
/*   Updated: 2025/01/22 11:29:50 by nsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_charcount(const char *s, int c)
{
	unsigned int	i;
	int				count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
		{
			++count;
		}
		i++;
	}
	return (count);
}

// #include <stdio.h>
// int main(void)
// {
// 	char *resultado = ft_strchr("hola mundo", 'm');
// 	printf("El carácter '%c' fue encontrado en la 
//  cadena: %s \n", 'm',  resultado);
//     return 0;
// }
