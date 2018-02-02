/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdauphin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 01:41:11 by mdauphin          #+#    #+#             */
/*   Updated: 2016/11/23 01:51:46 by mdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	unsigned int	len;

	len = ft_strlen(src);
	if (len >= n)
		ft_memcpy(dest, src, n);
	else
	{
		ft_memcpy(dest, src, n);
		ft_bzero(dest + len, n - len);
	}
	return (dest);
}
