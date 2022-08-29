/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okavak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 23:15:02 by okavak            #+#    #+#             */
/*   Updated: 2022/01/06 01:17:36 by okavak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//alfabetik bir karakter veya rakam olup olmadığını kontrol eder.
int	ft_isalnum(int a)
{
	if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'))
		return (1);
	else if (a >= '0' && a <= '9')
		return (1);
	else
		return (0);
}
/*int	main()
{
	printf("%d",ft_isalnum(','));
}*/
