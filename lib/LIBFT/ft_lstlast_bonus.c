/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsantand <nsantand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:34:21 by nsantand          #+#    #+#             */
/*   Updated: 2025/02/25 12:34:21 by nsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

// int main()
// {
//     t_list *lst = malloc(sizeof(t_list));
//     lst->content = "Queso";
//     lst->next = NULL;
//     t_list *new = malloc(sizeof(t_list));
//     new->content = "Hello";
//     new->next = lst;
//     t_list *last= ft_lstlast(new);
//     printf("último nodo: %s\n", (char *)last->content);
//     return 0;
// }