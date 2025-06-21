/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsantand <nsantand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:32:48 by nsantand          #+#    #+#             */
/*   Updated: 2025/02/25 12:32:48 by nsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

// int main()
// {
//     t_list *lst = malloc(sizeof(t_list));
//     lst->content = "Queso";
//     lst->next = NULL;
//     t_list *new = malloc(sizeof(t_list));
//     new->content = "Hello";
//     new->next = lst;

//     printf("%i\n", ft_lstsize(new));
//     return 0;
// }