/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okavak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 01:37:49 by okavak            #+#    #+#             */
/*   Updated: 2022/01/17 17:54:17 by okavak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//verinin uzunluğunu kontrol eder.
size_t	ft_strlen(const char *s)
{
	int	a;

	a = 0;
	while (*s != '\0')
	{
		a++;
		s++;
	}
	return (a);
}
/*int	main()
{
	char a[]="Hello World";
	printf("%zu",ft_strlen(a));
}*/
