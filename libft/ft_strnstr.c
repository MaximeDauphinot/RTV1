/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdauphin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 03:44:29 by mdauphin          #+#    #+#             */
/*   Updated: 2016/11/30 00:20:10 by mdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *l, size_t n)
{
	unsigned int	i;
	unsigned int	j;
	size_t			len;

	i = 0;
	j = 0;
	len = ft_strlen(l);
	if (l == '\0')
		return ((char*)big);
	while (big[i] != '\0' && len + i <= n)
	{
		if (ft_strncmp(big + i, l, len) == 0)
			return ((char*)big + i);
		i++;
	}
	return (NULL);
}
