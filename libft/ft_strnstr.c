/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okavak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:18:25 by okavak            #+#    #+#             */
/*   Updated: 2022/01/18 12:19:54 by okavak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//size kadar tarar ve s2 elemanı ve sonrarsını döner.
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	a;
	size_t	b;

	a = 0;
	b = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[a] != '\0')
	{
		b = 0;
		while (haystack[a + b] == needle[b] && (a + b) < len)
		{
			if (needle[b + 1] == '\0')
				return ((char *) &haystack[a]);
			b++;
		}
		a++;
	}
	return (NULL);
}
/*int	main()
{
	printf("%s",ft_strnstr("merhaba","aba",5));
}*/