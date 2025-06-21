/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsantand <nsantand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:48:12 by nsantand          #+#    #+#             */
/*   Updated: 2024/10/17 12:29:04 by nsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (s == NULL || f == NULL)
		return ;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

// static void	toup(unsigned int x, char* s)
// {
// 	int	i;

// 	(void)x;
// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		if (s[i] >= 97 && s[i] <= 122)
// 		{
// 			s[i] = s[i] - 32;
// 		}
// 		i++;
// 	}
// }

/*
#include <stdio.h>
int main(void)
{
	char str1[] = "DIgue";

	printf("String antes de la cadena: %s\n", str1);
	ft_striteri(str1, toup);
	printf("String despues de la cadena: %s\n", str1);

}*/