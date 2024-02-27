/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:11:14 by ple-guya          #+#    #+#             */
/*   Updated: 2023/11/27 19:06:57 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void	*content)
{
	t_list	*new;

	new = (t_list *) malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new -> content = content;
	new -> next = NULL;
	return (new);
}
/* 
#include <stdio.h>
int	main()
{
	char	*content = "au max";
	t_list	*new;
	new = ft_lstnew(content);
	printf("%s\n", (char *)new -> content);
	printf("%s\n", (char *)new -> next);
	free(new);
}*/
