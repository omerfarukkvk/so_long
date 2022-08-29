/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okavak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:33:08 by okavak            #+#    #+#             */
/*   Updated: 2022/02/02 02:13:10 by okavak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//size kadar srcdeki veriyi dstye kopyalar.
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_size;

	i = 0;
	src_size = ft_strlen(src);
	if (!dstsize)
		return (src_size);
	while (src[i] && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_size);
}
/*int	main()
{
	char	a[] = "omer";
	char	b[] = "faruk";
	ft_strlcpy(a,b,3);
	//printf("%zu", ft_strlcpy(a,b,2));
	printf("a verisi %s\nb verisi %s",a,b);
}*/
