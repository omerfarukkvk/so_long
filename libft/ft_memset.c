/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okavak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:59:57 by okavak            #+#    #+#             */
/*   Updated: 2022/01/10 23:04:52 by okavak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//c'deki değeri n kadar str'ye yazar
void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)str;
	while (n)
	{
		*p = (unsigned char) c;
		p++;
		n--;
	}
	return (str);
}
/*int	main()
{
	char a[] = "deneme";

	printf("%s",ft_memset(a,'i',2));
}*/
