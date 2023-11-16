/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkost <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:36:31 by rkost             #+#    #+#             */
/*   Updated: 2023/05/17 14:16:36 by rkost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	count;
	size_t	count_dest;
	size_t	src_len;
	size_t	dest_len;

	count_dest = 0;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	count = dest_len;
	if (destsize == 0)
		return (src_len);
	if (destsize < dest_len)
		return (src_len + destsize);
	else
	{
		while (src[count_dest] && (dest_len + count_dest) < destsize)
			dest[count++] = src[count_dest++];
		if ((dest_len + count_dest) == destsize && dest_len < destsize)
			dest[--count] = '\0';
		else
			dest[count] = '\0';
		return (src_len + dest_len);
	}
}
