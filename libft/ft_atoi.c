/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okavak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 16:17:27 by okavak            #+#    #+#             */
/*   Updated: 2022/02/24 05:21:30 by okavak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//char olarak verilen stringi int'e çevirir
int	ft_atoi(const char *str)
{
	int			neg;
	long int	snc;

	snc = 0;
	neg = 1;
	while (*str == ' ' || *str == '\t' || *str == '\r'
		|| *str == '\n' || *str == '\v' || *str == '\f')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		snc = (snc * 10) + (*str - 48) * neg;
		str++;
		if (snc > 2147483647)
			return (-1);
		if (snc < -2147483648)
			return (0);
	}
	return (snc);
}
/*int	main()
{
	printf("%d", ft_atoi("-2352"));
}*/
