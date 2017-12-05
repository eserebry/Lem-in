/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eserebry <eserebry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 09:55:02 by eserebry          #+#    #+#             */
/*   Updated: 2017/11/25 00:36:18 by eserebry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
**checking if ants are represented by number
*/

int		check_ants(char *str)
{
	int x;

	x = -1;
	while (str[++x])
	{
		if (!ft_isdigit(str[x]))
			return (0);
	}
	return (1);
}

/*
**getting number of ants
*/ 

int		get_ants(t_lemin *lemin, char *line)
{
	if (!check_ants(line))
		return (0);
	lemin->ants_num = ft_atoi(line);
	return (1);
}
