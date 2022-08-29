/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okavak <okavak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 23:30:11 by okavak            #+#    #+#             */
/*   Updated: 2022/08/29 13:35:53 by okavak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//s1 ve s2 yi tek string olarak yazdırır.
char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		i2;

	i = 0;
	i2 = 0;
	if (!s1 || !s2)
		return (0);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[i2])
	{
		str[i++] = s2[i2];
		i2++;
	}
	str[i] = '\0';
	return (str);
}
/*int	main()
{
	char *a;
	a = ft_strjoin("ahmet", "mehmet");
	printf("%s", a);
}*/
