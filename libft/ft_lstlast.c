/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:04:53 by ple-guya          #+#    #+#             */
/*   Updated: 2024/02/06 18:59:05 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst && lst -> next)
		lst = lst -> next;
	return (lst);
}

/* int main()
{

    t_list *sumi;
    t_list *last;
    
    int i;
    i = 0;
    sumi = ft_lstnew("sumi");
    sumi ->next = ft_lstnew("pierre");
    sumi->next->next = ft_lstnew("third");
    printf(" %s\n",(char *)sumi->next->next->content);
    last = ft_lstlast(sumi);
    printf(" %s\n",(char *)last->content);
}*/