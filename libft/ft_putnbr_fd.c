/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okavak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 04:14:11 by okavak            #+#    #+#             */
/*   Updated: 2022/02/02 04:16:35 by okavak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	index;

	index = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		index = n * -1;
	}
	else
		index = n;
	if (index > 9)
		ft_putnbr_fd(index / 10, fd);
	ft_putchar_fd(index % 10 + '0', fd);
}
/*int	main()
{
	ft_putnbr_fd(121, 1);
}*/