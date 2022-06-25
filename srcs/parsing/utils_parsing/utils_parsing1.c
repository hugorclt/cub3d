/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:34:18 by ajung             #+#    #+#             */
/*   Updated: 2022/06/25 16:42:08 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (s1[i] && s2[i] && (s1[i] == s2[i]))
		++i;
	return (s1[i] - s2[i]);
}

char	*skip_space(char *line)
{
	while (*line && *line == ' ')
		line++;
	return (line);
}

void	skip_space_new(char *str, int *i)
{
	while (str[*i] && (str[*i] == ' ' && str[*i] != '\n'))
		(*i)++;
}

int	is_num(char *line)
{
	int	i;

	i = 0;
	if (line[i] == ',')
		return (FAILURE);
	while (line[i] && (line[i] != ',' && line[i] != ' ' && line[i] != '\n'))
	{
		if (line[i] < '0' || line[i] > '9')
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}
