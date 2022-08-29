/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okavak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:59:50 by okavak            #+#    #+#             */
/*   Updated: 2022/01/30 17:45:00 by okavak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//memcpyden farkı daha güvenli olması bellek hatası alınmaması.
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s;
	char	*d;
	size_t	i;

	s = (char *)src;
	d = (char *)dst;
	i = 0;
	if (!len || dst == src)
		return (dst);
	if (d > s)
	{
		while (len-- > 0)
			d[len] = s[len];
	}
	else
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}
/*int	main()
{
	char a[] = "hello";
	char b[] = "world";

	printf("%s",(char *)ft_memmove(a,b,2));
}*/
/*int	main()
{
	char str[] = "123456789";
	ft_memmove(str + 2, str, 7); 
	printf("%s", str);
}*/
