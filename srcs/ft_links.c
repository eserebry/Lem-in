/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eserebry <eserebry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 07:17:47 by eserebry          #+#    #+#             */
/*   Updated: 2017/11/26 03:32:45 by eserebry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** checking array for links
*/

int		check_for_links(char *line)
{
	int x;

	x = -1;
	if (!ft_isprint(line[0]) || line[0] == '#' || line[0] == '-')
		return (0);
	while (line[++x] && line[x] != '-')
		;
	if (line[x] != '-')
		return (0);
	while (line[++x] && line[x] != '-')
		;
	if (line[x] == '\0')
		return (1);
	return (0);
}

/*
** allocating memory for links
*/

t_link	*new_link(t_lemin *lemin, t_link *tmp)
{
	if (!lemin->links)
	{
		lemin->links = (t_link *)ft_memalloc(sizeof(t_link));
		tmp = lemin->links;
	}
	else
	{
		tmp = lemin->links;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = (t_link *)ft_memalloc(sizeof(t_link));
		tmp = tmp->next;
	}
	return (tmp);
}

/*
** adding a link
*/

void	parse_link(t_lemin *lemin, char *line)
{
	t_link	*tmp;
	int		x;
	int		y;

	tmp = NULL;
	tmp = new_link(lemin, tmp);
	x = -1;
	while (line[++x] != '-')
		;
	tmp->name1 = ft_strsub(line, 0, x);
	y = x + 1;
	while (line[++x])
		;
	tmp->name2 = ft_strsub(line, y, x);
	tmp->next = NULL;
}

int		add_links(t_lemin *lemin, char *line)
{
	if (!check_for_links(line))
		return (0);
	parse_link(lemin, line);
	lemin->links_num++;
	return (1);
}
