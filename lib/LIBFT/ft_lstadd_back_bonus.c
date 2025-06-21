/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsantand <nsantand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:39:26 by nsantand          #+#    #+#             */
/*   Updated: 2025/02/25 12:39:26 by nsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (lst == NULL || new == NULL)
		return ;
	current = *lst;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = new;
}

// int main()
// {
//     t_list *lst = malloc(sizeof(t_list));
//     lst->content = "Queso";
//     lst->next = NULL;
//     t_list *new = malloc(sizeof(t_list));
//     new->content = "Hello";
//     new->next = lst;
//     t_list *nuevo = malloc(sizeof(t_list));
//     nuevo->content = "Amerqueso";
//     nuevo->next = NULL;
//     ft_lstadd_back(&new, nuevo);
//     while (new)
//     {
//         printf("%s\n", (char *)new->content );
//         new = new->next;
//     }
//     return 0;
// }