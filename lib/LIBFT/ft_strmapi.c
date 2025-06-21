/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsantand <nsantand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:48:01 by nsantand          #+#    #+#             */
/*   Updated: 2024/10/17 12:55:58 by nsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	str = malloc(ft_strlen(s) + 1);
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

// char	tolo(unsigned int i, char c)
// {
// 	(void)i;
// 	if (c >= 'A' && c <= 'Z')
// 		c = c + 32;
// 	return (c);
// }

// #include <stdio.h>
// int main(void)
// {
// 	char* str1 = "HaasdA(  )";

// 	printf("String antes de la cadena:	%s\n", str1);
// 	str1 = ft_strmapi(str1, tolo);
// 	printf("String despues de la cadena:	%s\n", str1);
// }