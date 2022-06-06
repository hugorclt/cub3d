/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:34:18 by ajung             #+#    #+#             */
/*   Updated: 2022/06/06 20:49:53 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/cub3d.h"

void	free_tab(char **tab)
{
	int i;

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

void	skip_space(char *line)
{
	while (*line && *line == ' ')
		line++;
}

int	is_num(char *line)
{
	int i;

	i = 0;
	while (line[i] && (line[i] != ',' || line[i] != ' '))
	{
		if (line[i] < '0' || line[i] > '9')
			return (FAILURE);
		i++;
	}
	return (SUCCESS);	
}

int	len_number(char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] != ',' || line[i] != ' '))
		i++;
	return (i);
}
