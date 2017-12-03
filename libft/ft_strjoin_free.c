/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strxjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eserebry <eserebry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 21:15:24 by eserebry          #+#    #+#             */
/*   Updated: 2017/11/21 21:22:29 by eserebry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoin_free(char *s1, char *s2, int free)
{
	int c;
	char*ptr;

	if (!s1 || !s2)
		return (NULL);
	c = ft_strlen(s1) + ft_strlen(s2);
	ptr = ft_memalloc(c);
	if (!ptr)
		return (NULL);
	ptr = ft_strcpy_int(ptr, s1, 0, 0);
	ptr = ft_strcpy_int(ptr, s2, 0, (ft_strlen(s1)));
	if (free == 1)
		ft_strdel(&s1);
	else if (free == 2)
		ft_strdel(&s2);
	else if (free == 3)
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
	return (ptr);
}
