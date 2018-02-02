/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdauphin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 03:32:35 by mdauphin          #+#    #+#             */
/*   Updated: 2016/11/30 00:20:19 by mdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if ((ft_strlen(little)) == 0)
		return ((char*)big);
	while (big[i] != '\0')
	{
		while (little[j] == big[i + j])
		{
			if (j == (ft_strlen(little) - 1))
				return ((char*)big + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
