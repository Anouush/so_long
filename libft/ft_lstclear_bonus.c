/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:17:39 by angalsty          #+#    #+#             */
/*   Updated: 2022/05/18 12:58:02 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*clear;

	if (lst)
	{
		while (*lst)
		{
			clear = (*lst)-> next;
			ft_lstdelone(*lst, del);
			*lst = clear;
		}
		*lst = 0;
	}
}
