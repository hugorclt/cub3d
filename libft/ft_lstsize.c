/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:20:57 by yobougre          #+#    #+#             */
/*   Updated: 2022/06/07 10:03:25 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*count;

	i = 0;
	if (!lst)
		return (i);
	count = lst;
	while (count->next != NULL)
	{
		count = count->next;
		i++;
	}	
	return (i + 1);
}
