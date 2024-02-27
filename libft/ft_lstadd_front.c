/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 21:48:47 by ple-guya          #+#    #+#             */
/*   Updated: 2023/11/27 19:14:40 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new -> next = *lst;
	*lst = new;
}

// void print_list(t_list *lst) 
// {
//     while (lst != NULL) {
//         printf("%s -> ", (char *)lst->content);
//         lst = lst->next;
//     }
//     printf("NULL\n");
// }
/* 
int main() 
{
    t_list *list = NULL;
	t_list *new = ft_lstnew("okay");
	int	i = 3;
	while (i > 0)
	{
		list = ft_lstnew("oui");
		list -> next = ft_lstnew("oui");
		i--;
	}
	print_list(list);
    ft_lstadd_front(&list, new);
    print_list(list);
} */
