/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 23:59:34 by ple-guya          #+#    #+#             */
/*   Updated: 2023/11/27 19:17:01 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*clear;
	t_list	*tmp;

	clear = *lst;
	while (clear != NULL)
	{
		tmp = clear -> next;
		ft_lstdelone(clear, del);
		clear = tmp;
	}
	*lst = NULL;
}
