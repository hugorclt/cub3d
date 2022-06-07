/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:22:13 by yobougre          #+#    #+#             */
/*   Updated: 2022/06/07 10:03:43 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *)dst;
	b = (unsigned char *)src;
	if (!src && !dst)
		return (dst);
	if (a < b)
		while (len--)
			*a++ = *b++;
	else
	{
		a += len - 1;
		b += len - 1;
		while (len--)
			*a-- = *b--;
	}
	return (dst);
}
