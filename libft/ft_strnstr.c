/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkost <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:50:25 by rkost             #+#    #+#             */
/*   Updated: 2023/05/29 17:11:44 by rkost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ftft_strnstr(const char *haystack, const char *needle, size_t size_cmp)
{
	size_t	count_hay;
	size_t	count_needle;

	if (needle[0] == '\0')
		return ((char *)haystack);
	count_hay = 0;
	while (haystack[count_hay] != '\0' && count_hay < size_cmp)
	{
		if (haystack[count_hay] == needle[0])
		{
			count_needle = 0;
			while (haystack[count_hay + count_needle] != '\0'
				&& needle[count_hay] != '\0'
				&& (count_hay + count_needle) < size_cmp
				&& haystack[count_hay + count_needle] == needle[count_needle])
				count_needle++;
			if (needle[count_needle] == '\0')
				return ((char *)haystack + count_hay);
		}
		count_hay++;
	}
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		j;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (needle[j] && haystack[i + j] && i + j < len
				&& haystack[i + j] == needle[j])
				j++;
			if (needle[j] == '\0')
				return ((char *)haystack + i);
		}
		i++;
	}
	return (0);
}
