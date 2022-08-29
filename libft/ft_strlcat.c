/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okavak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:30:16 by okavak            #+#    #+#             */
/*   Updated: 2022/01/31 00:02:06 by okavak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//srcyi dstnin üstüne yazar.
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	count;

	i = 0;
	j = 0;
	count = 0;
	while (src[count] != '\0')
		count++;
	while (dst[i] != '\0' && i < size)
		i++;
	while (src[j] != '\0' && (i + j + 1) < size)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < size)
		dst[i + j] = '\0';
	return (i + count);
}
/*int	main()
{
	char	a[]	= "omer";
	char	b[] = "faruk";

	printf("%zu",ft_strlcat(a,b,7));
}*/
