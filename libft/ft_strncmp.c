/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkost <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:44:50 by rkost             #+#    #+#             */
/*   Updated: 2023/05/29 17:15:53 by rkost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t size_cmp)
{
	unsigned char	*mem1;
	unsigned char	*mem2;
	size_t			count;

	mem1 = (unsigned char *)str1;
	mem2 = (unsigned char *)str2;
	count = 0;
	while ((mem1[count] != '\0' || mem2[count] != '\0')
		&& count < size_cmp)
	{
		if (mem1[count] == mem2[count])
			count++;
		else
		{
			return ((mem1[count]) - (mem2[count]));
		}
	}
	return (0);
}
