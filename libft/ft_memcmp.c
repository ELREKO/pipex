/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkost <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:12:28 by rkost             #+#    #+#             */
/*   Updated: 2023/05/29 17:01:49 by rkost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t size_cmp)
{
	size_t				count;
	const unsigned char	*mem_str1;
	const unsigned char	*mem_str2;

	mem_str1 = (unsigned char *)str1;
	mem_str2 = (unsigned char *)str2;
	count = 0;
	while (size_cmp-- > 0)
	{
		if (mem_str1[count] == mem_str2[count])
			count++;
		else if (mem_str1[count] != mem_str2[count])
			return (((int) mem_str1[count]) - ((int) mem_str2[count]));
	}
	return (0);
}
