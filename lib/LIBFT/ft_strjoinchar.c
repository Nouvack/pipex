/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsantand <nsantand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:07:40 by nsantand          #+#    #+#             */
/*   Updated: 2025/03/25 12:36:37 by nsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinchar(char const *s1, char const *s2, char const *c)
{
	char	*temp;
	char	*newstr;

	if (!s1 || !s2 || !c)
		return (NULL);
	temp = ft_strjoin(s1, c);
	if (!temp)
		return (NULL);
	newstr = ft_strjoin(temp, s2);
	free(temp);
	return (newstr);
}
