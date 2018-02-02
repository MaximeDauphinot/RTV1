/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdauphin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 15:34:47 by mdauphin          #+#    #+#             */
/*   Updated: 2016/11/29 15:36:00 by mdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*d;

	if (!s)
		return (NULL);
	if (!(d = (char*)malloc(sizeof(char) * (len) + 1)))
		return (NULL);
	d = ft_strncpy(d, &s[start], len);
	d[len] = '\0';
	return (d);
}
