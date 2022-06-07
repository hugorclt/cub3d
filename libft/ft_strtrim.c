/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:24:12 by yobougre          #+#    #+#             */
/*   Updated: 2022/06/07 12:53:52 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

static int	ft_is_set(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char *s1, char *set)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	ret = NULL;
	if (!s1 || !set)
		return (NULL);
	while (ft_is_set(s1[i], set))
		i++;
	j = ft_strlen(s1) - 1;
	while (j && ft_is_set(s1[j], set))
		j--;
	if (!j)
	{
		ret = ft_substr(s1, 0, j);
		free(s1);
		return (ret);
	}
	else
	{
		ret = ft_substr(s1, i, j - i + 1);
		free(s1);
		return (ret);
	}
}
