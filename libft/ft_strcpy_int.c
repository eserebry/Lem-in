/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strxcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eserebry <eserebry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 21:30:18 by eserebry          #+#    #+#             */
/*   Updated: 2017/11/21 21:33:05 by eserebry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strcpy_int(char *dst, const char *src, int s, int t)
{
	while (src[s] != '\0')
	{
		dst[t] = src[s];
		s++;
		t++;
	}
	dst[t] = '\0';
	return (dst);
}
