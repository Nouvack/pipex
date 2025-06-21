/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsantand <nsantand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:36:28 by nsantand          #+#    #+#             */
/*   Updated: 2025/02/25 12:36:28 by nsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

// void delete_content(void *content)
// {
//     free(content);
// }
// int main()
// {
//     t_list *node = malloc(sizeof(t_list));
//     if (!node->content)
//     {
//         free(node);
//         return 1;
//     }
//     node->next = NULL;

//     ft_lstdelone(node, delete_content);
//     return 0;
// }