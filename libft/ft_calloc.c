/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okavak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 16:10:46 by okavak            #+#    #+#             */
/*   Updated: 2022/01/30 17:09:54 by okavak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//yer ayırırken belleğin içinde bi değer varsa içine null atar.
void	*ft_calloc(size_t count, size_t size)
{
	void	*array;

	array = (char *)malloc(count * size);
	if (!array)
		return (NULL);
	return (ft_memset(array, 0, size * count));
}
/*int main()
{
	char *a = ft_calloc(3,sizeof(int));
	printf("%d",*a);
}*/