/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkost <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:04:38 by rkost             #+#    #+#             */
/*   Updated: 2023/05/16 21:07:17 by rkost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		count;
	char		*mem_dest;
	const char	*mem_src;

	mem_dest = (char *)dest;
	mem_src = (const char *)src;
	count = 0;
	if (n <= 0 || dest == src)
		return (dest);
	if (mem_src < mem_dest)
	{
		while (n--)
			mem_dest[n] = mem_src[n];
		return (dest);
	}
	while (count < n)
	{
		mem_dest[count] = mem_src[count];
		count++;
	}
	return (dest);
}
