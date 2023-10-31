/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:10:10 by fvoicu            #+#    #+#             */
/*   Updated: 2023/10/31 12:12:47 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **list, t_list *new)
{
	t_list	*temp;

	if ((!list && !*list) || !new)
		return ;
	if (*list == NULL)
		*list = new;
	else
	{
		temp = ft_lstlast(*list);
		temp->next = new;
	}
}
