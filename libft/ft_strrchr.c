/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okavak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 19:22:22 by okavak            #+#    #+#             */
/*   Updated: 2022/01/14 19:34:58 by okavak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//str'de c'nin geçtiği son yeri ara ve sonrasını bastırır.
char	*ft_strrchr(const char *s, int c)
{
	char	*p;

	p = 0;
	while (*s)
	{
		if (*s == ((unsigned char) c))
			p = (char *)s;
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (p);
}
/*int	main()
{
	char a[] = "deneme";
	
	printf("%s",ft_strrchr(a,'n'));
}*/
