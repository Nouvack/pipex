/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsantand <nsantand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 17:30:00 by nsantand          #+#    #+#             */
/*   Updated: 2024/10/05 18:12:30 by nsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*i;

	i = malloc(nmemb * size);
	if (i == NULL)
		return (NULL);
	ft_bzero(i, size * nmemb);
	return (i);
}

/*
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int	main(void)
{
	char	*ptr;

	ptr = (char *)ft_calloc(3, 1);
	if (!ptr)
		return (1);
	printf("%d %d %d\n", ptr[0], ptr[1], ptr[2]);
	free(ptr);
	return (0);
}
*/