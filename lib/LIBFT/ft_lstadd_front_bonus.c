/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsantand <nsantand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:37:57 by nsantand          #+#    #+#             */
/*   Updated: 2025/02/25 12:37:57 by nsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

// int main()
// {
//     t_list *lst = NULL;
//     t_list *new = malloc(sizeof(t_list));
//     new->content = "Hello";
//     new->next = NULL;
//     ft_lstadd_front(&lst, new);
//     printf("%s\n", (char *)lst->content);
//     return 0;
// }