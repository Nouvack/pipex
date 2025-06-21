/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsantand <nsantand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 14:40:03 by nsantand          #+#    #+#             */
/*   Updated: 2025/03/25 13:01:56 by nsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_array(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}
