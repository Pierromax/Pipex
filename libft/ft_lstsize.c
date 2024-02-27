/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:28:19 by ple-guya          #+#    #+#             */
/*   Updated: 2023/11/26 20:37:20 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
/*
int main()
{

    t_list *sumi;
    int i;
    i = 0;
    sumi = ft_lstnew("sumi");
    sumi ->next = ft_lstnew("pierre");
    sumi->next->next = ft_lstnew("third");
    printf("sumi next %s\n",(char *)sumi->next->next->content);
    i = ft_lstsize(sumi);
    printf("%d", i);
} */
