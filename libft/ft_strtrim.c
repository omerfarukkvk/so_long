/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okavak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 04:03:10 by okavak            #+#    #+#             */
/*   Updated: 2022/02/04 04:03:17 by okavak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//s1'i tarar set stringinde verdiğimiz harfleri çıkartır
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	set_start_index;
	size_t	set_end_index;

	if (!s1 || !set)
		return (NULL);
	set_start_index = 0;
	set_end_index = ft_strlen((char *) s1);
	while (ft_strchr(set, s1[set_start_index]) && s1[set_start_index] != '\0')
		set_start_index++;
	while (ft_strchr(set, s1[set_end_index]) && set_end_index != '\0')
		set_end_index--;
	if ((int)(set_end_index - set_start_index + 1) <= 0)
		return (ft_calloc(1, 1));
	return (ft_substr(s1, set_start_index, \
	(set_end_index - set_start_index) + 1));
}
/*int main()
{
    char *a = "   omer faruk kavak   ";
    char *s = " ";
    printf("%s",ft_strtrim(a,s));
}*/
