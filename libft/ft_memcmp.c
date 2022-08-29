/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okavak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:01:52 by okavak            #+#    #+#             */
/*   Updated: 2022/01/31 00:04:12 by okavak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//s1 ve s2'yi size kadar tarar ve eşit değil iseler birbirnin asci farkı döner.
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned const char	*a;
	unsigned const char	*b;

	a = (unsigned const char *)s1;
	b = (unsigned const char *)s2;
	i = 0;
	while (i < n)
	{
		if (a[i] != b[i])
			return (a[i] - b[i]);
		i++;
	}
	return (0);
}
/*int	main()
{
	printf("%d",ft_memcmp("deneme","denek",5));
}*/
