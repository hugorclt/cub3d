/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:19:06 by hrecolet          #+#    #+#             */
/*   Updated: 2022/06/07 10:20:59 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	unsigned char	p;

	p = (unsigned char) c;
	i = 0;
	while (s[i])
	{
		if (s[i] == p)
			return ((char *)&(s[i]));
		i++;
	}
	if (p == 0)
		return ((char *)&(s[i]));
	return (NULL);
}

char	*ft_strjoin_free_s1(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*output;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	output = (char *)malloc(sizeof(char)
			* (ft_strlen(s1) + ft_strlen(s2)+ 1));
	if (output == NULL)
		return (NULL);
	while (s1[i])
		output[j++] = s1[i++];
	i = 0;
	while (s2[i])
		output[j++] = s2[i++];
	output[j] = '\0';
	free(s1);
	return (output);
}

char	*ft_strndup_gnl(const char *s, int n)
{
	int		i;
	int		len;
	char	*copy;

	i = 0;
	len = ft_strlen(s);
	copy = (char *)malloc(sizeof(char) * (len + 1));
	if (copy == NULL)
		return (NULL);
	while (s[i] && i < n)
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
