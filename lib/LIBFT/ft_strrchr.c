/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsantand <nsantand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:37:19 by nsantand          #+#    #+#             */
/*   Updated: 2024/10/04 19:07:02 by nsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;

	i = ft_strlen(s) + 1;
	while (i > 0)
	{
		if (s[i - 1] == (unsigned char)c)
		{
			return ((char *)&s[i - 1]);
		}
		i--;
	}
	if ((unsigned char)c == '\0')
	{
		return ((char *)&s[i]);
	}
	return (NULL);
}
