/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 20:03:20 by lyandriy          #+#    #+#             */
/*   Updated: 2022/10/22 16:10:22 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*new_nodo;

	if (lst == NULL)
		return (NULL);
	while (lst != NULL)
	{
		new_nodo = lst;
		lst = lst->next;
	}
	return (new_nodo);
}
