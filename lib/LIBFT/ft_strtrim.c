/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsantand <nsantand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:16:46 by nsantand          #+#    #+#             */
/*   Updated: 2024/10/11 18:17:23 by nsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

static int	is_in_set(char c, const char *set);
static char	*empty_str(void);

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	end;
	unsigned int	len;
	char			*trimmed_str;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	if (end == 0)
		return (empty_str());
	end--;
	while (s1[start] && is_in_set(s1[start], set))
		start++;
	while (end > start && is_in_set(s1[end], set))
		end--;
	len = end - start + 1;
	trimmed_str = (char *)malloc(len + 1);
	if (!trimmed_str)
		return (NULL);
	ft_strlcpy(trimmed_str, &s1[start], len + 1);
	return (trimmed_str);
}

static int	is_in_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static char	*empty_str(void)
{
	char	*str;

	str = (char *)malloc(1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}
