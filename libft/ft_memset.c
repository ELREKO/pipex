/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkost <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:24:40 by rkost             #+#    #+#             */
/*   Updated: 2023/05/16 21:25:55 by rkost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int ch, size_t n)
{
	size_t			count;
	unsigned char	*mem;

	count = 0;
	mem = (unsigned char *)str;
	while (count < n)
	{
		mem[count] = (unsigned char)ch;
		count++;
	}
	return (mem);
}
