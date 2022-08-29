/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okavak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:36:46 by okavak            #+#    #+#             */
/*   Updated: 2022/01/10 22:58:28 by okavak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//1.girilen pointeri verilen byte kadar "\0" yazdirir.
void	ft_bzero(void *str, size_t n)
{
	ft_memset(str, '\0', n);
}
/*int main()
{
	char a[]= "deneme";
	ft_bzero(a,2);

	printf("%s",&a[2]);
}*/