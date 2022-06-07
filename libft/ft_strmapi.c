/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:23:46 by yobougre          #+#    #+#             */
/*   Updated: 2022/06/07 10:04:42 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*output;
	unsigned int	i;

	if (!s)
		return (NULL);
	output = ft_strdup(s);
	if (!output)
		return (NULL);
	i = 0;
	while (output[i])
	{
		output[i] = f(i, output[i]);
		i++;
	}
	return (output);
}
