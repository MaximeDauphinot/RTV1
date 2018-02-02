/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdauphin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 02:32:54 by mdauphin          #+#    #+#             */
/*   Updated: 2017/12/21 02:35:37 by mdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


float   ft_atof(const char *str)
{
	float	n;
	int		i;
	int		k;
	int		sym;

	i = 0;
	n = 0;
	k = 0;
	sym = 1;
	if (!str)
		return (0);
	while (str[i] == ' ' || str[i] == '\v' || str[i] == '\t' || str[i] == '\r'
			|| str[i] == '\f' || str[i] == '\n')
		i++;
	sym = (str[i] == '-') ? -sym : sym;
	i = (str[i] == '-' || str[i] == '+') ? i + 1 : i;
	while (str[i] > 47 && str[i] < 58)
	{
		n = n * 10 + (str[i++] - 48);
		if (str[i] == '.')
			k = i++;
	}
	while (k != 0 && str[++k])
		sym = sym * 10;
	return (n / sym);
}
