/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okavak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 18:13:06 by okavak            #+#    #+#             */
/*   Updated: 2022/02/02 02:17:31 by okavak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//malloc ile yer ayırıp s1'i döndürür.
char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s1) + 1;
	str = malloc(sizeof(char) * len);
	if (!str)
	{
		return (0);
	}
	return (ft_memcpy(str, s1, len));
}
/*int	main()
{
	printf("%s",ft_strdup("deneme"));
}*/
