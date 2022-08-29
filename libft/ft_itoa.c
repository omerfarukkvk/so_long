/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okavak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:50:58 by okavak            #+#    #+#             */
/*   Updated: 2022/02/09 12:51:45 by okavak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

//int olarak verilen değeri char'a çevirir.
static long	ft_len(long src)
{
	int	i;

	i = 0;
	if (src == 0)
		i++;
	if (src < 0)
		i++;
	while (src)
	{
		src /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		i;
	long	num;

	num = n;
	i = ft_len(num);
	ret = malloc(i + 1);
	if (ret == NULL)
		return (NULL);
	if (n < 0)
	{
		num = num * -1;
		ret[0] = '-';
	}
	ret[i] = 0;
	i--;
	while (i >= (n < 0))
	{
		ret[i] = (num % 10) + '0';
		num /= 10;
		i--;
	}
	return (ret);
}
/*int	main()
{
	printf("%s",ft_itoa(-123));
}*/
