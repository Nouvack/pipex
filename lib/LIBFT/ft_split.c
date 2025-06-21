/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsantand <nsantand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:49:32 by nsantand          #+#    #+#             */
/*   Updated: 2024/10/11 19:32:12 by nsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		word_count(char const *s, char c);
static char		*get_word(char const *s, char c);
static char		**fill_split(char **str, char const *s, char c);
static void		free_split(char **str, unsigned int words);

char	**ft_split(char const *s, char c)
{
	char			**str;
	unsigned int	word_total;

	if (s == NULL)
		return (NULL);
	word_total = word_count(s, c);
	str = malloc(sizeof(char *) * (word_total + 1));
	if (str == NULL)
		return (NULL);
	if (!fill_split(str, s, c))
		return (NULL);
	return (str);
}

static char	**fill_split(char **str, char const *s, char c)
{
	unsigned int	i;

	i = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != '\0')
		{
			str[i] = get_word(s, c);
			if (!str[i])
			{
				free_split(str, i);
				return (NULL);
			}
			i++;
		}
		while (*s != '\0' && *s != c)
			s++;
	}
	str[i] = NULL;
	return (str);
}

static int	word_count(char const *s, char c)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (count);
}

static char	*get_word(char const *s, char c)
{
	unsigned int	len;
	unsigned int	i;
	char			*word;

	len = 0;
	while (s[len] != c && s[len] != '\0')
		len++;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_split(char **str, unsigned int words)
{
	while (words > 0)
	{
		words--;
		free(str[words]);
	}
	free(str);
}

// #include <stdio.h>
// #include <stdlib.h>
// int main(void)
// {
//     char **result;
//     int i;
//     result = ft_split("Hola mundo C", ' ');
//     i = 0;
//     while (result[i])
//     {
//         printf("%s\n", result[i]);
//         free(result[i]);
//         i++;
//     }
//    free(result);
//     return (0);
// }
